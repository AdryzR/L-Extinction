/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** wolf.c
*/

#include "proto.h"

static sfTexture **init_texture(void)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * (6));

    texture[0] = sfTexture_createFromFile(WALL_N, NULL);
    texture[1] = sfTexture_createFromFile(SHOT, NULL);
    texture[2] = sfTexture_createFromFile(WALL_S, NULL);
    texture[3] = sfTexture_createFromFile(WEAPON, NULL);
    texture[4] = sfTexture_createFromFile(FOG, NULL);
    texture[5] = NULL;
    return texture;
}

int wolf(game_t *game)
{
    int state = menu(game);
    sfTexture **texture;

    if (state != 0) {
        free_tab(game->map.map2D);
        return state;
    }
    texture = init_texture();
    game->fog = texture[4];
    game->zombie = sfSprite_create();
    if (!game->zombie) {
        free_tab(game->map.map2D);
        return 84;
    }
    sfSprite_setTexture(game->zombie, texture[4], sfTrue);
    if (init_main(game, texture) == 84)
        return 84;
    display_loop(game, texture);
    destroy_main(game, texture);
    return 0;
}
