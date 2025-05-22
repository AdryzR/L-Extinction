/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** menu.c
*/

#include "proto.h"

int menu(game_t *game)
{
    sfTexture *texture_menu = sfTexture_createFromFile(MENU, NULL);
    button_t button_start;
    button_t button_quit;

    if (!texture_menu)
        return 84;
    if (init_menu(&button_quit, &button_start, game, texture_menu) == 84)
        return 84;
    if (display_menu_loop(game, &button_start, &button_quit) == 1) {
        destroy_button(&button_start);
        destroy_button(&button_quit);
        destroy_window_menu(game, texture_menu);
        return 1;
    }
    destroy_button(&button_start);
    destroy_button(&button_quit);
    sfTexture_destroy(texture_menu);
    return 0;
}
