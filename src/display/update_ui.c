/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_ui
*/

#include <proto.h>

void update_ammo(game_t *game)
{
    if (game->player->ammo > 0) {
        game->player->ammo -= 1;
        return;
    }
    game->shot_struct.gunshot = false;
}
