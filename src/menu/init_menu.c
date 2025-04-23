/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_menu.c
*/

#include "proto.h"

int init_menu(text_t *text_quit, text_t *text_start, game_t *game,
    sfTexture *texture_menu)
{
    if (init_window(game) == 84) {
        sfRenderWindow_destroy(game->windows.windows);
        return 84;
    }
    if (init_background(game, texture_menu) == 84) {
        destroy_window_menu(game, texture_menu);
        return 84;
    }
    if (init_text_start(text_start) == 84) {
        destroy_window_menu(game, texture_menu);
        destroy_text(text_start);
        return 84;
    }
    if (init_text_quit(text_quit) == 84) {
        destroy_window_menu(game, texture_menu);
        destroy_text(text_start);
        destroy_text(text_quit);
        return 84;
    }
    return 0;
}
