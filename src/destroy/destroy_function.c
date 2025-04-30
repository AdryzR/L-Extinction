/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** destroy_function.c
*/

#include "proto.h"

void destroy_window(game_t *game)
{
    sfSprite_destroy(game->windows.background.sprite);
    sfRenderWindow_destroy(game->windows.windows);
}

void destroy_map(game_t *game, sfTexture *texture_wall)
{
    sfSprite_destroy(game->wall);
    sfTexture_destroy(texture_wall);
}

void destroy_text(text_t *text)
{
    sfText_destroy(text->contain);
    sfFont_destroy(text->font);
}

void destroy_fx(game_t *game)
{
    sfClock_destroy(game->clock);
    free(game->wall_height);
    sfSprite_destroy(game->shot_struct.shot);
}

void destroy_main(game_t *game, sfTexture **texture)
{
    destroy_window(game);
    destroy_map(game, texture[0]);
    sfTexture_destroy(texture[1]);
    free(texture);
    destroy_fx(game);
}
