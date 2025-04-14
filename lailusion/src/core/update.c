/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** update.c
*/

#include "game.h"
#include "scene.h"
#include "macro.h"
#include "core.h"
#include "sound.h"

void change_music(game_t *game, int index)
{
    if (index == MAIN_MUSIC || index == MENU || index == DEAD) {
        sfMusic_stop(game->current_music);
        game->current_music = game->musics.music[index];
        sfMusic_setVolume(game->current_music, game->musics.volume[index]);
        sfMusic_play(game->current_music);

    } else {
        if (game->current_sound)
            sfMusic_stop(game->current_sound);
        game->current_sound = game->musics.music[index];
        sfMusic_setVolume(game->current_sound, game->musics.volume[index]);
        sfMusic_play(game->current_sound);
    }
}

void put_sound(game_t *game, int index)
{
    sfMusic_play(game->current_music);
}

static void update_music(game_t *game)
{

}

/**
 * @brief Update every entity related to the current scene.
 */
void update(game_t *game)
{
    CLOCK_RESTART(game->clock);

    if (game->scene_type == ST_NONE)
        return;

    scenes[game->scene_type].update(game);
    update_music(game);
}
