/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** destroy_window_menu.c
*/

#include "proto.h"

void destroy_window_menu(game_t *game, sfTexture *texture_background)
{
    sfSprite_destroy(game->windows.background.sprite);
    sfTexture_destroy(texture_background);
    sfRenderWindow_destroy(game->windows.windows);
}
