/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** display.c
*/

#include "macro.h"
#include "scene.h"
#include "game.h"

/**
 * @brief Display every entity related to the current scene.
 */
void display(game_t *game)
{
    CLEAR(game->screen.window, sfBlack);

    if (game->scene_type != ST_NONE)
        scenes[game->scene_type].display(game);

    DISPLAY(game->screen.window);
}
