/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** cast_all_rays.c
*/

#include "proto.h"

sfTexture *set_wall_color(float offset_x, float offset_y, sfTexture **texture)
{
    if (fabsf(offset_x) > fabsf(offset_y))
        return texture[TX_WALL_N];
    return texture[TX_WALL_S];
}

static list_object_t *init_obj(int x, ray_casting_t *ray_struct)
{
    list_object_t *object = malloc(sizeof(list_object_t));

    object->id = x;
    object->data = ray_struct->wall_height;
    object->offset_x = ray_struct->offset_x;
    object->offset_y = ray_struct->offset_y;
    object->hit_x = fmod(ray_struct->x, TILE_SIZE);
    object->hit_y = fmod(ray_struct->y, TILE_SIZE);
    object->angle = ray_struct->angle;
    object->distance = ray_struct->distance_to_wall;
    return object;
}

static void init_ray(ray_casting_t *ray_struct, player_t *player,
    game_t **game, float x)
{
    ray_struct->entity = false;
    ray_struct->x = player->x + 5;
    ray_struct->y = player->y + 5;
    ray_struct->distance_to_wall = 0.0;
    ray_struct->angle = fmodf((fmodf(player->camera_x, 2 * M_PI) - FOV / 2.0) +
    (x / (*game)->windows.width) * FOV, 2 * M_PI);
    cast_single_ray(ray_struct, game);
}

void cast_all_rays(player_t *player, game_t **game)
{
    ray_casting_t ray_struct = {0};

    for (float x = 0; x < (*game)->windows.width; x +=
    (*game)->windows.width / 800) {
        init_ray(&ray_struct, player, game, x);
        if (ray_struct.distance_to_wall < 0) {
            push_to_end_list(&(*game)->wall_height, init_obj(
            ray_struct.distance_to_wall, &ray_struct));
            continue;
        }
        ray_struct.distance_to_wall *=
        (cosf(fmodf(player->camera_x, 2 * M_PI) - ray_struct.angle));
        ray_struct.wall_height = (double)(TILE_SIZE *
        (*game)->windows.height) / ray_struct.distance_to_wall;
        push_to_end_list(&(*game)->wall_height, init_obj(x, &ray_struct));
    }
}
