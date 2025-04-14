/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_replace
*/

#include "object/platform.h"
#include "scene.h"
#include <stdlib.h>


void platform_replace(platform_t *platform, scene_ingame_t *data)
{
    unsigned char new_color = (unsigned char)(rand() % 2);

    if (new_color != platform->color) {
        sfSprite_setTexture(platform->sprite, data->platform_textures[new_color], sfFalse);
        platform->color = new_color;
        platform->is_active = !platform->is_active;
    }

    platform_randomize_width(platform);

    sfSprite_setPosition(platform->sprite, platform_generate_position(data->last_platform));
    data->last_platform = platform;
}
