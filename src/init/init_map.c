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
        if (line[k] != '#' && line[k] != ' ' && line[k] != 'P')
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

int init_map(game_t *game, sfTexture *texture)
{
    game->wall = init_sprite(texture);
    if (!game->wall)
        return 84;
    sfSprite_setTexture(game->wall, texture, sfTrue);
    if (check_map_valid(game->map.map2D) == false)
        return 84;
    return 0;
}
