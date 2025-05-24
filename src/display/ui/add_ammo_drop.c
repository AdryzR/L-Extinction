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
    d->sprite = sfSprite_create();
    sfSprite_setTexture(d->sprite, game->drop_texture, sfTrue);
    sfSprite_setPosition(d->sprite, pos);
    d->next = game->drops;
    game->drops = d;
}
