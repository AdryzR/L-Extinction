/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** add_ammo_drop
*/

#include <proto.h>

void add_ammo_drop(game_t *game, sfVector2f pos)
{
    ammo_drop_t *d = malloc(sizeof(*d));

    if (!d)
        return;
    d->position = pos;
    d->texture = game->drop_texture;
    d->next = game->drops;
    game->drops = d;
}
