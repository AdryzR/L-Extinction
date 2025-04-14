/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** player_update_texture
*/

#include "object/player.h"


void player_update_texture(player_t *player, sfTexture **textures)
{
    sfTexture *new_texture = textures[player->state];

    sfSprite_setTexture(player->sprite, new_texture, sfFalse);
    sfSprite_setTextureRect(player->sprite, (sfIntRect){ 0, 0, 32, 32 });
}
