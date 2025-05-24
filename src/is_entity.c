/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** is_entity.c
*/

#include "proto.h"

int is_entity(game_t *game, int x, int y, char *c)
{
    for (int i = 0; c[i]; ++i)
        if (!game->map.map2D ||
            game->map.map2D[y / TILE_SIZE][x / TILE_SIZE] == c[i])
            return 1;
    return 0;
}
