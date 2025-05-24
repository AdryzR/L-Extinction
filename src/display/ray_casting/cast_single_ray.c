/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** cast_single_ray.c
*/

#include "proto.h"

static int set_offset(ray_casting_t *ray_struct, int return_value)
{
        ray_struct->offset_x = ray_struct->x - ((float)ray_struct->test_x
        * (float)TILE_SIZE + (float)TILE_SIZE / 2.0);
        ray_struct->offset_y = ray_struct->y - ((float)ray_struct->test_y
        * (float)TILE_SIZE + (float)TILE_SIZE / 2.0);
        return return_value;
}

static int check_colision(ray_casting_t *ray_struct, game_t **game)
{
    ray_struct->distance_to_wall += 0.1;
    ray_struct->x += cos(ray_struct->angle) * 0.1;
    ray_struct->y += sin(ray_struct->angle) * 0.1;
    ray_struct->test_x = (int)(ray_struct->x / TILE_SIZE);
    ray_struct->test_y = (int)(ray_struct->y / TILE_SIZE);
    if (ray_struct->test_y >= 0 && ray_struct->test_y < 0 &&
        ray_struct->test_x >= 0 && ray_struct->test_x <
        (int)strlen((*game)->map.map2D[(ray_struct->test_y)]))
        return set_offset(ray_struct, 1);
    if (is_entity((*game), ray_struct->x, ray_struct->y, "#C") == 1)
        return set_offset(ray_struct, 1);
    return set_offset(ray_struct, 0);
}

static void update_distance(ray_casting_t *ray_struct, bool b)
{
    if (ray_struct->distance_to_wall > WALL_DISTANCE)
        ray_struct->distance_to_wall = -2;
    else if (b == 1)
        ray_struct->distance_to_wall = -1;
}

ray_casting_t *cast_single_ray(ray_casting_t *ray_struct, game_t **game)
{
    bool b = 0;
    int state = 0;

    while (ray_struct->distance_to_wall <= WALL_DISTANCE) {
        b = 0;
        state = check_colision(ray_struct, game);
        if (state == 1)
            break;
        b = 1;
    }
    update_distance(ray_struct, b);
    return ray_struct;
}
