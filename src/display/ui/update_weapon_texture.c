/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_weapon_texture
*/

#include <proto.h>

static void refresh_ammo_update_under_50(player_t *pl, unsigned int pct)
{
    if (pct > 25)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_50, NULL);
    else if (pct > 0)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_25, NULL);
    else
        pl->ammo_texture = sfTexture_createFromFile(AMMO_0, NULL);
}

static void refresh_ammo_update(player_t *pl, unsigned int pct)
{
    sfTexture_destroy(pl->ammo_texture);
    if (pct > 75)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_ASSET, NULL);
    else if (pct > 50)
        pl->ammo_texture = sfTexture_createFromFile(AMMO_75, NULL);
    else
        refresh_ammo_update_under_50(pl, pct);
    sfSprite_setTexture(pl->ammo_sprite, pl->ammo_texture, sfFalse);
}

/*
* Refresh de la sprite de munitions basée sur l’arme active.
*/
void refresh_ammo_sprite(game_t *game)
{
    player_t *pl = game->player;
    unsigned int pct;
    sfColor color;

    if (pl->wp_status == W_AK) {
        pct = (pl->ak_mag * 100) / AK_MAG_SIZE;
    } else if (pl->wp_status == W_GUN) {
        pct = (pl->gun_mag * 100) / GUN_MAG_SIZE;
    } else {
        return;
    }
    refresh_ammo_update(pl, pct);
    if (pct == 0)
        color = sfRed;
    else if (pct <= 10)
        color = sfColor_fromRGB(255, 165, 0);
    else
        color = sfWhite;
    sfText_setColor(pl->ammo_txt, color);
}

/**
* Détruit l’ancienne texture à l’index 3 puis charge la nouvelle.
*/
static void set_weapon_texture(game_t *game, const char *path)
{
    if (game->textures[3])
        sfTexture_destroy(game->textures[3]);
    game->textures[3] = sfTexture_createFromFile(path, NULL);
    if (!game->textures[3]) {
        fprintf(stderr, "Error: cannot load texture '%s'\n", path);
    }
    sfSprite_setTexture(
        game->weapon.sprite,
        game->textures[3],
        sfFalse
    );
}

void set_gun_texture(game_t *game)
{
    set_weapon_texture(game, WP_GUN_TEXTURE);
    sfSprite_setScale(game->weapon.sprite, (sfVector2f) {1, 1});
    sfSprite_setOrigin(game->weapon.sprite, (sfVector2f) {1020 / 2.f, 0});
    refresh_ammo_sprite(game);
}

void set_ak_texture(game_t *game)
{
    set_weapon_texture(game, WP_AK_TEXTURE);
    sfSprite_setScale(game->weapon.sprite, (sfVector2f) {8, 8});
    sfSprite_setOrigin(game->weapon.sprite, (sfVector2f) {64 / 2, 0});
    refresh_ammo_sprite(game);
}

void set_knife_texture(game_t *game)
{
    set_weapon_texture(game, WP_KNIFE_TEXTURE);
    sfSprite_setScale(game->weapon.sprite, (sfVector2f) {8, 8});
    sfSprite_setOrigin(game->weapon.sprite, (sfVector2f) {64 / 2, 0});
}
