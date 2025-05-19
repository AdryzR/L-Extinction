/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_ui
*/

#include <proto.h>

static void handle_ammo_update_under_50(player_t *pl)
{
    if (pl->ammo > 25)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_50, NULL);
    else if (pl->ammo != 0)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_25, NULL);
    else
        pl->ammo_texture = sfTexture_createFromFile(AMMO_0, NULL);
}

static void update_ammo_texture(player_t *pl)
{
    sfTexture_destroy(pl->ammo_texture);
    if (pl->ammo < 50)
        handle_ammo_update_under_50(pl);
    else
        pl->ammo_texture = sfTexture_createFromFile(AMMO_75, NULL);
    sfSprite_setTexture(pl->ammo_sprite, pl->ammo_texture, false);
}

void update_ammo(game_t *game)
{
    player_t *pl = game->player;

    if (pl->ammo > 0)
        pl->ammo -= 1;
    if (pl->ammo < 75)
        update_ammo_texture(pl);
}
