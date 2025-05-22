/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** check_npc_hit.c
*/

#include "proto.h"

static void init_ray(ray_casting_t *ray_struct, player_t *player,
    game_t *game, float x)
{
    ray_struct->entity = false;
    ray_struct->x = player->x + 5;
    ray_struct->y = player->y + 5;
    ray_struct->distance_to_wall = 0.0;
    ray_struct->angle = fmodf((fmodf(player->camera_x, 2 * M_PI) - FOV / 2.0) +
    (x / game->windows.width) * FOV, 2 * M_PI);
}

static void npc_loop(ray_casting_t *ray_struct, game_t *game)
{
    for (npc_t *temp = game->npc; temp; temp = temp->next)
        if (temp->hit == false && ray_struct->x <= temp->position.x + 20
            && ray_struct->y <= temp->position.y + 20 && ray_struct->x >
            temp->position.x && ray_struct->y > temp->position.y) {
            add_particle(&game->particle, sfRed, (sfVector2f)
            {game->windows.width / 2, game->windows.height / 2 +
            ray_struct->distance_to_wall},
            fabsf(ray_struct->distance_to_wall - 200 / 2));
            add_particle(&game->particle, sfRed, (sfVector2f)
            {game->windows.width / 2, game->windows.height / 2 +
            ray_struct->distance_to_wall},
            fabsf(ray_struct->distance_to_wall - 200 / 2));
            temp->hit = true;
            temp->health -= 10;
        }
}

void check_npc_hit(game_t *game)
{
    ray_casting_t ray_struct = {0};

    if (is_mag_empty(game))
        return;
    init_ray(&ray_struct, game->player, game, game->windows.width / 2);
    while (ray_struct.distance_to_wall <= 200) {
        ray_struct.distance_to_wall += 0.1;
        ray_struct.x += cos(ray_struct.angle) * 0.1;
        ray_struct.y += sin(ray_struct.angle) * 0.1;
        ray_struct.test_x = (int)(ray_struct.x / TILE_SIZE);
        ray_struct.test_y = (int)(ray_struct.y / TILE_SIZE);
        npc_loop(&ray_struct, game);
    }
}
