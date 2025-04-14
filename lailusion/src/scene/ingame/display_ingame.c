/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** display_menu.c
*/

#include "game.h"
#include "macro.h"
#include "object/player.h"


void display_ingame(game_t *game)
{
    if (!game || !game->scene)
        return;

    scene_ingame_t *data = game->scene->data;

    for (int i = 0; data->background[i]; i++)
        SPRITE_DRAW(game->screen.window, data->background[i], NULL);
    player_display(game, data->player);
    for (int i = 0; i < 20; i++)
        SPRITE_DRAW(game->screen.window, data->platforms[i]->sprite, NULL);

    sfRenderWindow_drawText(game->screen.window, data->timer_text, NULL);
}
