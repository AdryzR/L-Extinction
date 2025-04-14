/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_create
*/

#include "object/platform.h"
#include <stdio.h>
#include <stdlib.h>


platform_t *platform_create(sfTexture **textures)
{
    platform_t *platform = malloc(sizeof(platform_t));

    platform->color = (unsigned char)(rand() % 2);
    platform->is_active = platform->color == PC_RED;  // red is active by default
    platform->sprite = sfSprite_create();

    sfSprite_setTexture(platform->sprite, textures[platform->color], sfFalse);
    platform_randomize_width(platform);

    return platform;
}
