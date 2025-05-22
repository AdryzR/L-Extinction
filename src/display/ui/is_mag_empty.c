/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** is_mag_empty
*/

#include <proto.h>

bool is_mag_empty(game_t *game)
{
    player_t *pl = game->player;

    switch (pl->wp_status) {
    case W_KNIFE:
        return true;
    case W_AK:
        return (pl->ak_mag == 0);
    case W_GUN:
        return (pl->gun_mag == 0);
    }
    return false;
}
