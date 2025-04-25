/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** draw_player.c
*/

#include "proto.h"

void draw_player(game_t *game)
{
    sfRectangleShape *player_square = sfRectangleShape_create();
    sfVertex line[] = {
    {(sfVector2f){game->player->x / 2 + 5, game->player->y / 2 + 5},
    sfRed, {0, 0}}, {{game->player->x / 2 + cos(game->player->angle) * 20 + 5,
    game->player->y / 2 + sin(game->player->angle) * 20 + 5}, sfRed, {0, 0}}};

    sfRenderWindow_drawPrimitives(game->windows.windows,
    line, 2, sfLines, NULL);
    sfRectangleShape_setPosition(player_square,
    (sfVector2f){game->player->x / 2, game->player->y / 2});
    sfRectangleShape_setSize(player_square, (sfVector2f){10.0, 10.0});
    sfRectangleShape_setFillColor(player_square, sfGreen);
    sfRenderWindow_drawRectangleShape(game->windows.windows,
    player_square, NULL);
    sfRectangleShape_destroy(player_square);
}
