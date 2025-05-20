/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_ui
*/

#include <proto.h>

void update_weapons(game_t *game)
{
    switch (game->player->wp_status) {
    case W_GUN:
        return update_gun(game);
case W_AK:
    return update_ak(game);
// case W_KNIFE:
//     return update_knife(game->player);
    }
}
