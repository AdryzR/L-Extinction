/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** cast_single_ray.c
*/

#include "proto.h"

static int check_colision(ray_casting_t *ray_struct, game_t **game)
{
    if (ray_struct->test_y >= 0 && ray_struct->test_y < (*game)->map.height &&
        ray_struct->test_x >= 0 && ray_struct->test_x <
        (int)strlen((*game)->map.map2D[(ray_struct->test_y)])) {
        ray_struct->offset_x =
        ray_struct->x - (ray_struct->test_x * TILE_SIZE + TILE_SIZE / 2);
        ray_struct->offset_y =
        ray_struct->y - (ray_struct->test_y * TILE_SIZE + TILE_SIZE / 2);
        return 1;
    }
    if (is_wall((*game), ray_struct->x, ray_struct->y) == 1) {
        ray_struct->offset_x =
        ray_struct->x - (ray_struct->test_x * TILE_SIZE + TILE_SIZE / 2);
        ray_struct->offset_y =
        ray_struct->y - (ray_struct->test_y * TILE_SIZE + TILE_SIZE / 2);
        return 1;
    }
    return 0;
}

ray_casting_t *cast_single_ray(ray_casting_t *ray_struct, game_t **game)
{
    bool b = 0;

    while (1) {
        b = 0;
        ray_struct->distance_to_wall += 0.1;
        ray_struct->x += cos(ray_struct->angle) * 0.1;
        ray_struct->y += sin(ray_struct->angle) * 0.1;
        ray_struct->test_x = (int)(ray_struct->x / TILE_SIZE);
        ray_struct->test_y = (int)(ray_struct->y / TILE_SIZE);
        if (check_colision(ray_struct, game) == 1)
            break;
        b = 1;
    }
    if (b == 1)
        ray_struct->distance_to_wall = -1;
    return ray_struct;
}
