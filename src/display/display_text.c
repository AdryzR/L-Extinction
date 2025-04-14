/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** display_text.c
*/

#include "proto.h"

int display_text(game_t *game)
{
    if (update_timer(game) == 84)
        return 84;
    sfRenderWindow_drawText(game->windows.windows, game->text.contain, NULL);
    return 0;
}
