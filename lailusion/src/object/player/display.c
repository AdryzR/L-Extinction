/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** player_display
*/

#include "object/player.h"
#include <SFML/Graphics/Sprite.h>


static void incr_run_anim(sfSprite *sprite)
{
    sfIntRect texture_rect = sfSprite_getTextureRect(sprite);

    texture_rect.left = (texture_rect.left + 32) % 192;

    sfSprite_setTextureRect(sprite, texture_rect);
}

static void incr_jump_anim(sfSprite *sprite)
{
    sfIntRect texture_rect = sfSprite_getTextureRect(sprite);

    if (texture_rect.left >= 160)
        texture_rect.left -= 32;
    else
        texture_rect.left += 32;

    sfSprite_setTextureRect(sprite, texture_rect);
}

static void incr_slide_anim(sfSprite *sprite)
{
    sfIntRect texture_rect = sfSprite_getTextureRect(sprite);

    if (texture_rect.left >= 64)
        return;

    texture_rect.left += 32;

    sfSprite_setTextureRect(sprite, texture_rect);
}

/**
 * @brief Go to the next animation frame,
 * regardless of which animation is currently
 being played
 */
static void increment_animation_frame(player_t *player)
{
    static void (*anim_incr_fncs[3])(sfSprite *) = {
        incr_run_anim, incr_jump_anim,
        incr_slide_anim
    };

    anim_incr_fncs[player->state](player->sprite);
}

/**
 * @brief Player's display function.
 * This function is called every frame,
 * and is thus framerate-dependent.
 */
void player_display(game_t *game, player_t *player)
{
    static unsigned int frame_count = 0;  // TODO: switch to a time-dependent counter
    static const unsigned int animation_delay = 8;

    if (frame_count >= animation_delay) {
        increment_animation_frame(player);
        frame_count = 0;
    }
    sfRenderWindow_drawSprite(game->screen.window, player->sprite, NULL);
    frame_count++;
}
