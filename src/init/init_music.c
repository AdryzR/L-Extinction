/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** init_music
*/

#include <proto.h>

int init_music(game_t *game)
{
    game->music = sfMusic_createFromFile(GAME_MUSIC);
    if (!game->music)
        return abort_fx(game);
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_setVolume(game->music, 30.f);
    sfMusic_play(game->music);
    return 0;
}
