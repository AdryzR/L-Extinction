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
    text_t text_start;
    text_t text_quit;

    if (init_menu(&text_quit, &text_start, game, texture_menu) == 84)
        return 84;
    if (display_menu_loop(game, &text_start, &text_quit) == 1) {
        destroy_text(&text_start);
        destroy_text(&text_quit);
        destroy_window_menu(game, texture_menu);
        return 1;
    }
    destroy_text(&text_start);
    destroy_text(&text_quit);
    sfTexture_destroy(texture_menu);
    return 0;
}
