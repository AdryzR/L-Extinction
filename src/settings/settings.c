/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** settings
*/

#include "proto.h"

bool check_event(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyEscape)
        return false;
    return true;
}

void open_settings(game_t *game)
{
    sfEvent event;
    create_button(&game->button, "click here :)", 850, 770);

    for(bool settings = true; (settings = true);) {
        while (sfRenderWindow_pollEvent(game->windows.windows, &event))
        settings = check_event(game, event);
        sfRenderWindow_display(game->windows.windows);
    }
    return;
}
