/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** update_menu.c
*/

#include "proto.h"

void update_menu(game_t *game, text_t *text_start, text_t *text_quit)
{
    sfVector2u multiplicator = sfRenderWindow_getSize(game->windows.windows);
    float x_multiplicator = 1.0;
    float y_multiplicator = 1.0;

    if (multiplicator.x != 1920 || multiplicator.y != 1080){
        x_multiplicator = (float)multiplicator.x / 1920;
        y_multiplicator = (float)multiplicator.y / 1080;
    }
    text_start->hitbox.left = sfText_getPosition(text_start->contain).x *
    x_multiplicator;
    text_start->hitbox.top = sfText_getPosition(text_start->contain).y *
    y_multiplicator;
    text_start->hitbox.width = 190;
    text_start->hitbox.height = 100;
    text_quit->hitbox.left = sfText_getPosition(text_quit->contain).x *
    x_multiplicator;
    text_quit->hitbox.top = sfText_getPosition(text_quit->contain).y *
    y_multiplicator;
    text_quit->hitbox.width = 190;
    text_quit->hitbox.height = 100;
}
