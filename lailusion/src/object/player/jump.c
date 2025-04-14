/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** jump
*/

#include "object/player.h"
#include "macro.h"


void player_jump(player_t *player, sfTexture **textures)
{
    player->accel_y += JUMP_STRENGTH;
    player->state = PS_JUMP;
    player_update_texture(player, textures);
}
