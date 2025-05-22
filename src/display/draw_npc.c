/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** draw_npc.c
*/

#include "proto.h"

void draw_npc(game_t *game, npc_t *npc)
{
    sfRectangleShape *player_square = sfRectangleShape_create();

    sfRectangleShape_setPosition(player_square,
    (sfVector2f){npc->position.x / 6, npc->position.y / 6});
    sfRectangleShape_setSize(player_square, (sfVector2f)
    {PLAYER_HEIGHT, PLAYER_HEIGHT});
    sfRectangleShape_setFillColor(player_square, sfRed);
    sfRenderWindow_drawRectangleShape(game->windows.windows,
    player_square, NULL);
    sfRectangleShape_destroy(player_square);
}
