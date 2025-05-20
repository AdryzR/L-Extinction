/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_ui
*/

#include <proto.h>

void update_weapons(game_t *game)
{
    if (game->player->wp_status == W_GUN && game->gun_shot.gunshot)
        sfSound_play(game->gun_shot.shot_sound);
    else if (game->player->wp_status == W_AK && game->ak_shot.gunshot)
        sfSound_play(game->ak_shot.shot_sound);
    switch (game->player->wp_status) {
    case W_GUN:
        update_gun(game);
        if (game->gun_shot.gunshot) {
            sfSound_play(game->gun_shot.shot_sound);
            refresh_ammo_sprite(game);
        }
        break;
    case W_AK:
        update_ak(game);
        if (game->ak_shot.gunshot) {
            sfSound_play(game->ak_shot.shot_sound);
            refresh_ammo_sprite(game);
        }
        break;
// case W_KNIFE:
//     return update_knife(game->player);
    }
}
