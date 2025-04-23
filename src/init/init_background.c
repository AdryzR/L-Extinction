/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_background.c
*/

#include "proto.h"

int init_background(game_t *game, sfTexture *texture)
{
    game->windows.background = init_object(texture, (sfVector2f){0, 0});
    if (!game->windows.background.sprite)
        return 84;
    sfSprite_setTexture(game->windows.background.sprite, texture, sfTrue);
    return 0;
}
