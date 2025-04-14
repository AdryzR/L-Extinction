/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** game.c
*/

#include "core.h"
#include "macro.h"
#include <unistd.h>

/**
 * @brief Call to get the main struct from everywhere in the program.
 */
game_t *get_game(void)
{
    static game_t game = { 0 };

    return &game;
}

float get_time(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);

    return (float)((double)time.microseconds / 1000000.0f);
}


/**
 * @brief The main loop of the game.
 */
int game_mainloop(void)
{
    game_t *game = init_game(get_game());
    float seconds;

    change_scene(game, ST_MAIN_MENU);
    while (IS_OPEN(game->screen.window)) {
        seconds = get_time(game);
        while (POLL_EVENT(game->screen.window, &game->screen.event)) {
            event_manager(game);
        }
        while (seconds > 0.05f) {
            update(game);
            seconds -= 0.05f;
        }
        display(game);
    }
    free_game(game);
    return SUCCESS;
}
