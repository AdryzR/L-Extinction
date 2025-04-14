/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_randomize_width
*/

#include "object/platform.h"
#include "macro.h"
#include <stdlib.h>


void platform_randomize_width(platform_t *platform)
{
    int width =
        rand() % (PLATFORM_MAX_WIDTH - PLATFORM_MIN_WIDTH) +
        PLATFORM_MIN_WIDTH;

    sfSprite_setTextureRect(platform->sprite, (sfIntRect){
        0, 0, width, 13
    });
}
