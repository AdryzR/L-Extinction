/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** draw_ui
*/

#include "proto.h"
#include <stdlib.h>

void draw_ui(game_t *game)
{
    player_t *pl = game->player;
    char *ammo = uint_to_str(pl->ammo);
    char *hp = uint_to_str(pl->hp);

    if (!ammo || !hp)
        return;
    sfText_setString(pl->ammo_txt, ammo);
    sfText_setString(pl->hp_txt, hp);
    sfRenderWindow_drawText(game->windows.windows, pl->ammo_txt, NULL);
    sfRenderWindow_drawText(game->windows.windows, pl->hp_txt, NULL);
    sfRenderWindow_drawSprite(game->windows.windows, pl->ammo_sprite, NULL);
    sfRenderWindow_drawSprite(game->windows.windows, pl->hp_sprite, NULL);
    free(ammo);
    free(hp);
}
