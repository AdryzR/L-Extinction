/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** slide
*/

#include "object/player.h"


void player_slide(player_t *player, sfTexture **textures)
{
    player->state = PS_SLIDE;
    player_update_texture(player, textures);
}
