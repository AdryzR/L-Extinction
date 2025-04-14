/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** display_menu.c
*/

#include "game.h"
#include "macro.h"

void free_menu(game_t *game)
{
    if (!game)
        return;

    scene_menu_t *data = game->scene->data;
    if (!data)
        return;

    sfTexture_destroy(data->background_texture);
    sfSprite_destroy(data->background);
    sfSprite_destroy(data->button[0]);
    sfSprite_destroy(data->button[1]);
    sfTexture_destroy(data->button_texture);
    sfText_destroy(data->text[0]);
    sfText_destroy(data->text[1]);
    sfText_destroy(data->text[2]);
    sfFont_destroy(data->font);
    free(data->button);
    free(data->text);
    free(data);
}
