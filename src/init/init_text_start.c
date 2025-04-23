/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_text_start.c
*/

#include "proto.h"

int init_text_start(text_t *text_start)
{
    text_start->contain = sfText_create();
    text_start->font = sfFont_createFromFile(FONT);
    if (!text_start->contain || !text_start->font)
        return 84;
    sfText_setFont(text_start->contain, text_start->font);
    sfText_setPosition(text_start->contain, (sfVector2f)
    {1920 / 2 - 100, 1080 / 2 - 150});
    sfText_setScale(text_start->contain, (sfVector2f) {3, 3});
    sfText_setString(text_start->contain, "Play");
    text_start->hitbox.left = sfText_getPosition(text_start->contain).x;
    text_start->hitbox.top = sfText_getPosition(text_start->contain).y;
    text_start->hitbox.width = 190;
    text_start->hitbox.height = 100;
    return 0;
}
