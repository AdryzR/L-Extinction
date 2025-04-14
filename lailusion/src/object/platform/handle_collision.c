/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_handle_collision
*/

#include "object/platform.h"
#include "object/player.h"
#include <math.h>


static void snap_to_platform(platform_t *platform, player_t *player)
{
    sfVector2f platform_position = sfSprite_getPosition(platform->sprite);
    sfVector2f player_position = sfSprite_getPosition(player->sprite);

    player_position.y = platform_position.y;  // snap back to top
    player->accel_y = 0;
    player->state = PS_NORMAL;
    sfSprite_setPosition(player->sprite, player_position);
}

static void collide_top(player_t *player)
{
    player->accel_y = - fabsf(player->accel_y);  // make the player accelerate downwards
}

static void collide_right(platform_t *platform, player_t *player, const sfFloatRect *player_bounds)
{
    sfVector2f platform_pos = sfSprite_getPosition(platform->sprite);
    float displacement =
        player_bounds->left + player_bounds->width - platform_pos.x;

    sfSprite_move(player->sprite, (sfVector2f){
        - displacement, 0.f
    });
}

/**
 * @brief handle collisions between player
 * and platform
 */
void handle_collision(platform_t *platform, player_t *player)
{
    sfFloatRect platform_bounds = sfSprite_getGlobalBounds(platform->sprite);
    sfFloatRect player_bounds = sfSprite_getGlobalBounds(player->sprite);

    float player_bottom = player_bounds.top + player_bounds.height;
    float platform_bottom = platform_bounds.top + platform_bounds.height;

    // If player is over platform, snap him to the platform
    if (player->state == PS_JUMP && platform_bounds.top >= player_bottom)
        snap_to_platform(platform, player);
    else if (player->state == PS_JUMP && platform_bottom <= player_bounds.top)
        collide_top(player);
    else  // here we don't care if the player is falling or not
        collide_right(platform, player, &player_bounds);
}
