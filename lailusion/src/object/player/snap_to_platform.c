/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** snap_to_platform
*/

#include "object/player.h"
#include "object/platform.h"
#include <math.h>


/**
 * @brief snap the player on the platform
 * he's intersecting with.
 * Does nothing if the player isn't intersecting with a platform
 */
void player_snap_to_platform(scene_ingame_t *data)
{
    sfFloatRect player_bounds = sfSprite_getGlobalBounds(data->player->sprite);

    float player_bottom = player_bounds.top + player_bounds.height;
    float momentum = fabsf(data->player->accel_y);
    player_bounds.height += momentum * 2 + 4.f;
    player_bounds.top -= momentum + 2.f;

    for (int i = 0; i < 20; i++) {
        if (data->platforms[i]->color != data->color)  // skip all non-colliding platforms
            continue;

        sfFloatRect platform_bounds = sfSprite_getGlobalBounds(data->platforms[i]->sprite);

        if (!sfFloatRect_intersects(&player_bounds, &platform_bounds, NULL))
            continue;

        float height_difference = player_bottom - platform_bounds.top;

        sfSprite_move(data->player->sprite, (sfVector2f){
            0.f, - (height_difference > 40.f ? -45.f : height_difference)
        });

        if (height_difference < 40.f)
            data->player->accel_y = 0;

        return;
    }
}
