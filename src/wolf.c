/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** wolf.c
*/

#include "proto.h"

static sfTexture **init_texture(void)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * (5));

    texture[0] = sfTexture_createFromFile(WALL_N, NULL);
    texture[1] = sfTexture_createFromFile(SHOT, NULL);
    texture[2] = sfTexture_createFromFile(WALL_S, NULL);
    texture[3] = sfTexture_createFromFile(WEAPON, NULL);
    texture[4] = NULL;
    return texture;
}

int wolf(game_t *game)
{
    int state = menu(game);
    sfTexture **texture;

    if (state == 1) {
        free_tab(game->map.map2D);
        return 0;
    }
    if (state == 84) {
        free_tab(game->map.map2D);
        return 84;
    }
    texture = init_texture();
    if (init_main(game, texture) == 84)
        return 84;
    display_loop(game, texture);
    destroy_main(game, texture);
    return 0;
}
