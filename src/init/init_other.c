/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** init_other
*/

#include <proto.h>

int init_other(game_t *game, sfTexture **texture)
{
    game->player = malloc(sizeof(player_t));
    if (!game->player)
        return 84;
    if (init_player(game, game->player) == 84) {
        destroy_main(game, texture);
        return 84;
    }
    game->player->ak_reserve = DEFAULT_AK_AMMO;
    game->player->gun_reserve = DEFAULT_GUN_AMMO;
    game->npc = init_npc(game, game->npc);
    game->drops = NULL;
    game->drop_texture = texture[TX_AMMO];
    if (!game->drop_texture) {
        fprintf(stderr, "Error loading drop_texture\n");
        return 84;
    }
    return 0;
}
