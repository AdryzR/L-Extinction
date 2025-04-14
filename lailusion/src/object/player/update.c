/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Implementation for player
** update function
*/

#include "object/player.h"
#include "macro.h"
#include "sound.h"
#include <SFML/Graphics.h>
#include <stdbool.h>


static bool is_out_of_bounds(sfVector2f position)
{
    return
        (position.x + 16.f <= 0.f) ||
        (position.y - 32.f >= WINDOW_HEIGHT);
}

/**
 * @brief Player's update function. This
 * function relies on being called a fixed
 * amount of times
 *
 * @return whether or not the scene should
 * continue updating or not
 */
bool player_update(player_t *player, game_t *game)
{
    scene_ingame_t *data = game->scene->data;
    sfVector2f position = sfSprite_getPosition(player->sprite);

    if (is_out_of_bounds(position)) {
        change_scene(game, ST_DEATH);
        change_music(game, DEAD);
        return false;  // signal update function to stop updating
    }

    // Update the player's acceleration
    if (player->state != PS_JUMP && sfKeyboard_isKeyPressed(sfKeySpace)) {
        change_music(game, JUMP);
        player_jump(player, data->player_textures);
    }

    // Handle sliding
    bool slide_key_pressed = sfKeyboard_isKeyPressed(sfKeyC);

    if (player->state == PS_NORMAL && slide_key_pressed) {
        change_music(game, SLIDE);
        player_slide(player, data->player_textures);
    }
    if (player->state == PS_SLIDE && !slide_key_pressed)
        player_run(player, data->player_textures);

    // Apply the player's acceleration
    position.y -= player->accel_y;

    // Apply gravity if in the air
    if (player->state == PS_JUMP)
        player->accel_y -= PLAYER_GRAVITY;

    // Update the player's position
    sfSprite_setPosition(player->sprite, position);

    player->state = PS_JUMP;
    return true;
}
