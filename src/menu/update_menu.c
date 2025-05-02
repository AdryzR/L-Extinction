/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** update_menu.c
*/

#include "proto.h"

void update_menu(game_t *game, button_t *button_start, button_t *button_quit)
{
    sfVector2u multiplicator = sfRenderWindow_getSize(game->windows.windows);
    float x_multiplicator = 1.0;
    float y_multiplicator = 1.0;

    if (multiplicator.x != 1920 || multiplicator.y != 1080){
        x_multiplicator = (float)multiplicator.x / 1920;
        y_multiplicator = (float)multiplicator.y / 1080;
    }
    button_start->hitbox.left = sfText_getPosition(button_start->contain).x *
    x_multiplicator;
    button_start->hitbox.top = sfText_getPosition(button_start->contain).y *
    y_multiplicator;
    button_start->hitbox.width = 190;
    button_start->hitbox.height = 100;
    button_quit->hitbox.left = sfText_getPosition(button_quit->contain).x *
    x_multiplicator;
    button_quit->hitbox.top = sfText_getPosition(button_quit->contain).y *
    y_multiplicator;
    button_quit->hitbox.width = 190;
    button_quit->hitbox.height = 100;
}
