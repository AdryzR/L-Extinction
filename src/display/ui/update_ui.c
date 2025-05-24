/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_ui
*/

#include <proto.h>

static void update_based_on_weapon(game_t *game)
{
    switch (game->player->wp_status) {
        case W_KNIFE:
            break;
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
        }
}

void update_weapons(game_t *game)
{
    float now = sfTime_asSeconds(sfClock_getElapsedTime(game->clock));

    if (game->player->reloading && now >= game->player->reload_end)
        game->player->reloading = false;
    if (game->player->reloading)
        return;
    if (game->player->wp_status == W_GUN && game->gun_shot.gunshot)
        sfSound_play(game->gun_shot.shot_sound);
    else if (game->player->wp_status == W_AK && game->ak_shot.gunshot)
        sfSound_play(game->ak_shot.shot_sound);
    update_based_on_weapon(game);
}
