/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_gun
*/

#include <proto.h>

static void handle_ammo_update_under_50(player_t *pl)
{
    if (pl->gun_ammo > 25)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_50, NULL);
    else if (pl->gun_ammo != 0)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_25, NULL);
    else
        pl->ammo_texture = sfTexture_createFromFile(AMMO_0, NULL);
}

static void update_ammo_texture(player_t *pl, unsigned int ammo_pct)
{
    sfTexture_destroy(pl->ammo_texture);
    if (ammo_pct > 50)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_75, NULL);
    else if (ammo_pct > 25)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_50, NULL);
    else if (ammo_pct > 0)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_25, NULL);
    else
        pl->ammo_texture = sfTexture_createFromFile(AMMO_0, NULL);
    sfSprite_setTexture(pl->ammo_sprite, pl->ammo_texture, sfFalse);
    // if (pl->gun_ammo < 50)
    //     handle_ammo_update_under_50(pl);
    // else
    //     pl->ammo_texture = sfTexture_createFromFile(AMMO_75, NULL);
    // sfSprite_setTexture(pl->ammo_sprite, pl->ammo_texture, false);
}

void update_gun(game_t *game)
{
    player_t *pl = game->player;
    unsigned int ammo_pct;

    game->shot_struct.gunshot = (pl->gun_ammo > 0);
    if (pl->gun_ammo > 0) {
        pl->gun_ammo--;
        ammo_pct = (pl->gun_ammo * 100) / DEFAULT_GUN_AMMO;
    }
    if (ammo_pct < 75)
        update_ammo_texture(pl, ammo_pct);
}
