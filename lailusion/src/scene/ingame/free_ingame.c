/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Implementation for
** free_ingame
*/

#include "game.h"
#include "object/player.h"


void free_ingame(game_t *game)
{
    if (!game || !game->scene)
        return;

    scene_ingame_t *data = game->scene->data;
    if (!data)
        return;

    // Free background:
    for (int i = 0; data->background[i]; i++) {
        sfTexture_destroy(data->background_texture[i]);
        sfSprite_destroy(data->background[i]);
    }

    // Free player:
    sfSprite_destroy(data->player->sprite);
    for (int i = 0; i < 3; i++)
        sfTexture_destroy(data->player_textures[i]);
    free(data->player);

    // Free platforms:
    for (int i = 0; i < 20; i++)
        sfSprite_destroy(data->platforms[i]->sprite);
    sfTexture_destroy(data->platform_textures[0]);
    sfTexture_destroy(data->platform_textures[1]);

    sfText_destroy(data->timer_text);
    sfFont_destroy(data->timer_font);

    free(data->background);
    free(data->background_texture);
    free(data);
    free(game->scene);
    game->scene = NULL;
}
