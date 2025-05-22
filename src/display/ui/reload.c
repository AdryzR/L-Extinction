/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** reload
*/

#include <proto.h>

static void play_random_reload(game_t *game)
{
    int idx = rand() % RELOAD_SOUNDS_COUNT;

    sfSound_setBuffer(game->reload_sound, game->reload_buffers[idx]);
    sfSound_play(game->reload_sound);
}

void reload_gun(game_t *game)
{
    player_t *pl = game->player;
    unsigned int need;
    unsigned int take;
    float now;

    if (pl->reloading || pl->gun_mag == GUN_MAG_SIZE || pl->gun_reserve == 0)
        return;
    need = GUN_MAG_SIZE - pl->gun_mag;
    take = pl->gun_reserve < need ? pl->gun_reserve : need;
    pl->gun_mag += take;
    pl->gun_reserve -= take;
    pl->reloading = true;
    now = sfTime_asSeconds(sfClock_getElapsedTime(game->clock));
    pl->reload_end = now + RELOAD_COOLDOWN;
    play_random_reload(game);
    refresh_ammo_sprite(game);
}

void reload_ak(game_t *game)
{
    player_t *pl = game->player;
    unsigned int need;
    unsigned int take;
    float now;

    if (pl->reloading || pl->ak_mag == AK_MAG_SIZE || pl->ak_reserve == 0)
        return;
    need = AK_MAG_SIZE - pl->ak_mag;
    take = pl->ak_reserve < need ? pl->ak_reserve : need;
    pl->ak_mag += take;
    pl->ak_reserve -= take;
    pl->reloading = true;
    now = sfTime_asSeconds(sfClock_getElapsedTime(game->clock));
    pl->reload_end = now + RELOAD_COOLDOWN;
    play_random_reload(game);
    refresh_ammo_sprite(game);
}
