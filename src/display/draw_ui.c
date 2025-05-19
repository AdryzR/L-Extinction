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

    fprintf(stderr, "ammo = %s\n", ammo);
    fprintf(stderr, "hp = %s\n", hp);
    if (!ammo || !hp)
        return;
    fprintf(stderr, "GROSCACA\n");
    sfText_setString(pl->ammo_txt, ammo);
    sfText_setString(pl->hp_txt, hp);
    sfRenderWindow_drawText(game->windows.windows, pl->ammo_txt, NULL);
    sfRenderWindow_drawText(game->windows.windows, pl->hp_txt, NULL);
    free(ammo);
    free(hp);
}
