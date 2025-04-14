/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** event.c
*/

#include "core.h"
#include "scene.h"
#include "game.h"
#include "macro.h"

/**
 * @brief Manage every event related to the current scene.
 */
void event_manager(game_t *game)
{
    if (game->screen.event.type == sfEvtClosed) {
        CLOSE(game->screen.window);
        return;
    }
    if (game->scene_type == ST_NONE)
        return;
    scenes[game->scene_type].event_manager(game);
}
