/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** draw_ammo_map.c
*/

#include "proto.h"

void draw_ammo_map(game_t *game, ammo_drop_t *ammo)
{
    sfRectangleShape *player_square = sfRectangleShape_create();

    sfRectangleShape_setPosition(player_square,
    (sfVector2f){ammo->position.x / 6, ammo->position.y / 6});
    sfRectangleShape_setSize(player_square, (sfVector2f)
    {PLAYER_HEIGHT, PLAYER_HEIGHT});
    sfRectangleShape_setFillColor(player_square, sfYellow);
    sfRenderWindow_drawRectangleShape(game->windows.windows,
    player_square, NULL);
    sfRectangleShape_destroy(player_square);
}
