/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_menu.c
*/

#include "proto.h"

int init_menu(button_t *button_quit, button_t *button_start, game_t *game,
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
    if (init_button_start(button_start) == 84) {
        destroy_window_menu(game, texture_menu);
        destroy_button(button_start);
        return 84;
    }
    if (init_button_quit(button_quit) == 84) {
        destroy_window_menu(game, texture_menu);
        destroy_button(button_start);
        destroy_button(button_quit);
        return 84;
    }
    return 0;
}
