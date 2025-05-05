/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** settings
*/

#include "proto.h"

bool check_event(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->windows.windows);
        return false;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        game->key = init_key();
        return false;
    }
    return true;
}

void open_settings(game_t *game)
{
    sfEvent event;
    bool settings = true;

    create_button(&game->button, "click here :)", 850, 770);
    while (settings) {
        sfRenderWindow_clear(game->windows.windows, sfBlack);
        while (sfRenderWindow_pollEvent(game->windows.windows, &event))
            settings = check_event(game, event);
        sfRenderWindow_drawText(game->windows.windows,
            game->button.contain, NULL);
        sfRenderWindow_display(game->windows.windows);
    }
    return;
}
