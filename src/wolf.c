/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** wolf.c
*/

#include "proto.h"

static sfTexture **init_texture(game_t *game)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * (TX_SIZE + 1));

<<<<<<< Updated upstream
    texture[TX_WALL_N] = sfTexture_createFromFile(WALL_N, NULL);
    texture[TX_SHOT] = sfTexture_createFromFile(SHOT, NULL);
    texture[TX_WALL_S] = sfTexture_createFromFile(WALL_S, NULL);
    texture[TX_GUN] = sfTexture_createFromFile(WP_GUN_TEXTURE, NULL);
    texture[TX_FOG] = sfTexture_createFromFile(FOG, NULL);
    texture[TX_ZOMBIE] = sfTexture_createFromFile(ZOMBIE, NULL);
    texture[TX_AK] = sfTexture_createFromFile(WP_AK_TEXTURE, NULL);
    texture[TX_SIZE] = NULL;
    game->textures = texture;
    for (int i = 0; texture[i]; ++i)
        if (!texture[i]) {
            my_putstr("Erreur de chargement de texture.\n");
=======
    texture[0] = sfTexture_createFromFile(WALL_N, NULL);
    texture[1] = sfTexture_createFromFile(SHOT, NULL);
    texture[2] = sfTexture_createFromFile(WALL_S, NULL);
    texture[3] = sfTexture_createFromFile(WEAPON, NULL);
    texture[4] = sfTexture_createFromFile(FOG, NULL);
    texture[5] = sfTexture_createFromFile(ZOMBIE, NULL);
    texture[6] = NULL;
    for (int i = 0; i < 6; ++i)
        if (texture[i] == NULL) {
            fprintf(stderr, "Failed to load texture.\n");
>>>>>>> Stashed changes
            return NULL;
        }
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
