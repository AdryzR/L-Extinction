/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** init_player.c
*/

#include "proto.h"

static player_t *find_player_coord(game_t *game, player_t **player, int i)
{
    for (int k = 0; k < MAP_WIDTH; ++k) {
        if (game->map[i][k] == 3) {
            (*player)->x = k;
            (*player)->y = i;
            (*player)->angle = 90;
            return player;
        }
    }
    return NULL;
}

player_t *init_player(game_t *game, player_t *player)
{
    if (!player)
        return NULL;
    for (int i = 0; i < MAP_HEIGHT; ++i)
        player = find_player_coord(game, &player, i);
    return player;
}
