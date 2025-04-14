/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** player_run
*/

#include "object/player.h"


void player_run(player_t *player, sfTexture **textures)
{
    player->state = PS_NORMAL;
    player_update_texture(player, textures);
}
