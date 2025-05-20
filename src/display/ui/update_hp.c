/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_hp
*/

#include <proto.h>

static void handle_hp_update_under_50(player_t *pl)
{
    if (pl->hp > 25)
        pl->hp_texture = sfTexture_createFromFile(HP_50, NULL);
    else
        pl->hp_texture = sfTexture_createFromFile(HP_25, NULL);
}

static void update_hp_texture(player_t *pl)
{
    sfTexture_destroy(pl->hp_texture);
    if (pl->hp < 50)
        handle_hp_update_under_50(pl);
    else
        pl->hp_texture = sfTexture_createFromFile(HP_75, NULL);
    sfSprite_setTexture(pl->hp_sprite, pl->hp_texture, false);
}

// Todo: adapts on how damaged are taken
void update_hp(game_t *game)
{
    player_t *pl = game->player;

    if (pl->hp < 75)
        update_hp_texture(pl);
}
