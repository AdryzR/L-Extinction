/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Implementation for
** update_ingame
*/

#include "game.h"
#include "object/player.h"


void update_death(game_t *game)
{
    if (!game || !game->scene)
        return;

    scene_death_t *data = game->scene->data;

    for (int i = 0; data->background[i]; i++) {
        sfIntRect rect = sfSprite_getTextureRect(data->background[i]);
        rect.left += (int)((game->speed) * (float)(i * 2));
        sfSprite_setTextureRect(data->background[i], rect);
    }
    game->speed -= 0.007f;
    if (game->speed < 0.0f)
        game->speed = 0.0f;
}
