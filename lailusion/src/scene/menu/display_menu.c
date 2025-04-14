/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** display_menu.c
*/

#include "game.h"
#include "macro.h"

void display_menu(game_t *game)
{
    if (!game)
        return;

    scene_menu_t *data = game->scene->data;

    SPRITE_DRAW(game->screen.window, data->background, NULL);
    SPRITE_DRAW(game->screen.window, data->button[0], NULL);
    SPRITE_DRAW(game->screen.window, data->button[1], NULL);
    TEXT_DRAW(game->screen.window, data->text[0], NULL);
    TEXT_DRAW(game->screen.window, data->text[1], NULL);
    TEXT_DRAW(game->screen.window, data->text[2], NULL);
}
