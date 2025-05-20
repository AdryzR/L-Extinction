/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** reload
*/

#include <proto.h>

void reload_gun(game_t *game)
{
    player_t *pl = game->player;
    unsigned int need = GUN_MAG_SIZE - pl->gun_mag;
    unsigned int take = pl->gun_reserve < need ? pl->gun_reserve : need;

    pl->gun_mag += take;
    pl->gun_reserve -= take;
    refresh_ammo_sprite(game);
}

void reload_ak(game_t *game)
{
    player_t *pl = game->player;
    unsigned int need = AK_MAG_SIZE - pl->ak_mag;
    unsigned int take = pl->ak_reserve < need ? pl->ak_reserve : need;

    pl->ak_mag += take;
    pl->ak_reserve -= take;
    refresh_ammo_sprite(game);
}
