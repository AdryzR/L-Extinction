/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** settings_button
*/

#include "proto.h"

void settings_button(game_t *game, button_t *bsound)
{
    if (sfFloatRect_contains(&bsound->hitbox,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).x,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).y))
        sfText_setColor(bsound->contain, sfColor_fromRGB(211, 211, 211));
    else
        sfText_setColor(bsound->contain, sfWhite);
}
