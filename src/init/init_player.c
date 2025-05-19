/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** init_player.c
*/

#include "proto.h"

static player_t *find_player_coord(game_t *game, player_t *player, int i)
{
    for (int k = 0; game->map.map2D[i][k]; ++k) {
        if (game->map.map2D[i][k] == 'P') {
            player->x = k * TILE_SIZE;
            player->y = i * TILE_SIZE;
            player->camera_x = 0.0f;
            return player;
        }
    }
    return player;
}

int init_player(game_t *game, player_t *player)
{
    if (!player)
        return 84;
    player->x = -1;
    player->y = -1;
    player->camera_y = 100.0;
    print_tab(game->map.map2D);
    for (int i = 0; game->map.map2D[i]; ++i)
        player = find_player_coord(game, player, i);
    if (player->x == -1 && player->y == -1)
        return 84;
    return 0;
}
