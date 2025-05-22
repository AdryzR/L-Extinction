/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** init_object.c
*/

#include "proto.h"

object_t init_object(sfTexture *texture, sfVector2f position)
{
    object_t object;

    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, texture, sfTrue);
    object.position = position;
    sfSprite_setPosition(object.sprite, object.position);
    return object;
}
