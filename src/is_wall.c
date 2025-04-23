/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** is_wall.c
*/

#include "proto.h"

int is_wall(game_t *game, int x, int y)
{
    if (!game->map.map2D ||
        game->map.map2D[y / TILE_SIZE][x / TILE_SIZE] == '#')
        return 1;
    return 0;
}
