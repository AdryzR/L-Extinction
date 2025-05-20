/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_weapon_texture
*/

#include <proto.h>

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
}

void set_gun_texture(game_t *game)
{
    set_weapon_texture(game, WP_GUN_TEXTURE);
}

void set_ak_texture(game_t *game)
{
    set_weapon_texture(game, WP_AK_TEXTURE);
}

void set_knife_texture(game_t *game)
{
    set_weapon_texture(game, WP_KNIFE_TEXTURE);
}
