/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Header file for all things
** related to platforms
*/

#ifndef OBJECT_PLATFORM_H
    #define OBJECT_PLATFORM_H
    #include "types.h"
    #include <stdbool.h>
    #include <SFML/Graphics.h>


struct platform_s {
    sfSprite *sprite;
    bool is_active;
    enum { PC_RED, PC_GREEN } color;
};


platform_t *platform_create(sfTexture **textures);
void platforms_init(platform_t **platforms, sfTexture **textures);
void platform_update(platform_t *platform, scene_ingame_t *data);

// Utils:
sfVector2f platform_generate_position(const platform_t *previous);
void platform_replace(platform_t *platform, scene_ingame_t *data);
void handle_collision(platform_t *platform, player_t *player);
void platform_randomize_width(platform_t *platform);


#endif
