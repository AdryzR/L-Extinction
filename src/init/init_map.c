/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** init_map.c
*/

#include "proto.h"

static int add_map(game_t *game, script_t *script, int i)
{
    for (int k = 0; k < MAP_WIDTH; ++k) {
        if (script->tab[i][k] == '\0' ||
        my_char_isnum(script->tab[i][k]) == 0) {
            write(2, "Invalid map file\n", 18);
            return 84;
        }
        game->map[i][k] = script->tab[i][k] - 48;
    }
    return 0;
}

int init_map(game_t *game, script_t *script)
{
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        if (!script->tab[i])
            return 84;
        if (add_map(game, script, i) == 84)
            return 84;
    }
    return 0;
}