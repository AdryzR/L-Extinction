/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** change_scene.c
*/

#include "macro.h"
#include "scene.h"
#include "game.h"
#include "sound.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief  Call this function wherever to change the current scene.
 */
void change_scene(game_t *game, scene_type_t scene_type)
{
    if (scene_type == game->scene_type)
        return;  // don't do anything if the scene doesn't change

    if (game->scene_type != ST_NONE)
        scenes[game->scene_type].free(game);

    if (game->current_music)
        sfMusic_stop(game->current_music);

    game->scene_type = scene_type;  // Update the game's scene to new scene

    if (scene_type != ST_NONE)
        scenes[scene_type].load(game);
}
