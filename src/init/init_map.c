/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** init_map.c
*/

#include "proto.h"

static bool line_valid(char *line)
{
    for (int k = 0; line[k]; ++k) {
        if (line[k] != '#' && line[k] != ' ' && line[k] != 'P' &&
            line[k] != 'Z' && line[k] != 'C')
            return false;
    }
    return true;
}

static bool check_map_valid(char **map)
{
    for (int i = 0; map[i]; ++i) {
        if (line_valid(map[i]) == 0)
            return false;
    }
    return true;
}

int init_map(game_t *game)
{
    int i = 0;

    if (!game->map.map2D[0])
        return 84;
    for (; game->map.map2D[i]; ++i)
        for (int k = 0; game->map.map2D[i][k]; ++k)
    game->map.height = i;
    if (check_map_valid(game->map.map2D) == false)
        return 84;
    return 0;
}
