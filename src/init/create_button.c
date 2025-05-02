/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** create_button
*/

#include "proto.h"

int create_button(button_t *button, char *text, int x_pos, int y_pos)
{
    button->contain = sfText_create();
    button->font = sfFont_createFromFile(FONT);
    if (!button->contain || !button->font)
        return 84;
    sfText_setFont(button->contain, button->font);
    sfText_setPosition(button->contain, (sfVector2f) {x_pos, y_pos});
    sfText_setScale(button->contain, (sfVector2f) {3, 3});
    sfText_setString(button->contain, text);
    button->hitbox.left = sfText_getPosition(button->contain).x;
    button->hitbox.top = sfText_getPosition(button->contain).y;
    button->hitbox.width = 200;
    button->hitbox.height = 100;
    return 0;
}
