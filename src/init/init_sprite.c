/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_sprite.c
*/

#include "proto.h"

sfSprite *init_sprite(sfTexture *texture)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setOrigin(sprite, (sfVector2f){10, 10});
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
