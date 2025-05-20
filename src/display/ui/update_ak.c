/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_ak
*/

#include <proto.h>

void update_ak(game_t *game)
{
    player_t *pl = game->player;

    game->ak_shot.gunshot = (pl->ak_ammo > 0);
    if (pl->ak_ammo > 0) {
        pl->ak_ammo--;
    }
    refresh_ammo_sprite(game);
}
