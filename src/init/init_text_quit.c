/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_text_quit.c
*/

#include "proto.h"

int init_text_quit(text_t *text_quit)
{
    text_quit->contain = sfText_create();
    text_quit->font = sfFont_createFromFile(FONT);
    if (!text_quit->contain || !text_quit->font)
        return 84;
    sfText_setFont(text_quit->contain, text_quit->font);
    sfText_setPosition(text_quit->contain, (sfVector2f)
    {1920 / 2 - 100, 1080 / 2 + 150});
    sfText_setScale(text_quit->contain, (sfVector2f) {3, 3});
    sfText_setString(text_quit->contain, "Quit");
    text_quit->hitbox.left = sfText_getPosition(text_quit->contain).x;
    text_quit->hitbox.top = sfText_getPosition(text_quit->contain).y;
    text_quit->hitbox.width = 190;
    text_quit->hitbox.height = 100;
    return 0;
}
