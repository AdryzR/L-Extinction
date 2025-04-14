/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** free.c
*/

#include "macro.h"
#include "game.h"
#include <stdlib.h>

/**
 * @brief Free the current loaded scene.
 */
void free_current_scene(game_t *game)
{
    if (game->scene_type != ST_NONE)
        scenes[game->scene_type].free(game);
}

static void free_music(game_t *game)
{
    for (int i = 0; i < 6; i++)
        sfMusic_destroy(game->musics.music[i]);
}

/**
 * @brief Free the main structure and every sub structures.
 */
void free_game(game_t *game)
{
    CLOCK_DESTROY(game->clock);
    free_current_scene(game);
    WINDOW_DESTROY(game->screen.window);
    free_music(game);
    // Don't free the value associated to the game ptr (it lives in static memory)
}
