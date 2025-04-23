/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** wolf.c
*/

#include "proto.h"

static sfTexture **init_texture(void)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * (2));

    texture[0] = sfTexture_createFromFile(WALL, NULL);
    texture[1] = NULL;
    return texture;
}

int wolf(game_t *game)
{
    int state = menu(game);
    sfTexture **texture = init_texture();

    if (state == 1)
        return 0;
    if (state == 84)
        return 84;
    if (init_main(game, texture) == 84)
        return 84;
    display_loop(game);
    destroy_main(game, texture);
    return 0;
}
