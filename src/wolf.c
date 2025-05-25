/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** wolf.c
*/

#include "proto.h"

static sfTexture **loading_texture_error(void)
{
    my_putstr("Erreur de chargement de texture.\n");
    return NULL;
}

static sfTexture **init_texture(game_t *game)
{
    sfTexture **texture = calloc(TX_SIZE + 1, sizeof(*texture));

    if (!texture)
        return NULL;
    texture[TX_WALL_N] = sfTexture_createFromFile(WALL_N, NULL);
    texture[TX_SHOT] = sfTexture_createFromFile(SHOT, NULL);
    texture[TX_WALL_S] = sfTexture_createFromFile(WALL_S, NULL);
    texture[TX_GUN] = sfTexture_createFromFile(WP_GUN_TEXTURE, NULL);
    texture[TX_FOG] = sfTexture_createFromFile(FOG, NULL);
    texture[TX_ZOMBIE] = sfTexture_createFromFile(ZOMBIE, NULL);
    texture[TX_AK] = sfTexture_createFromFile(WP_AK_TEXTURE, NULL);
    texture[TX_KNIFE] = sfTexture_createFromFile(WP_KNIFE_TEXTURE, NULL);
    texture[TX_AMMO] = sfTexture_createFromFile(DROP_ASSET, NULL);
    texture[TX_SIZE] = NULL;
    game->textures = texture;
    for (int i = 0; i < TX_SIZE; ++i)
        if (!texture[i])
            return loading_texture_error();
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
    texture = init_texture(game);
    if (!texture)
        return 84;
    game->fog = texture[TX_FOG];
    game->zombie_texture = texture[TX_ZOMBIE];
    if (init_main(game, texture) == 84)
        return 84;
    display_loop(game, texture);
    destroy_main(game, texture);
    return 0;
}
