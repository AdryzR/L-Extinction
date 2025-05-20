/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_gun
*/

#include <proto.h>

void update_gun(game_t *game)
{
    player_t *pl = game->player;

    game->gun_shot.gunshot = (pl->gun_ammo > 0);
    if (pl->gun_ammo > 0) {
        pl->gun_ammo--;
    }
    refresh_ammo_sprite(game);
}
