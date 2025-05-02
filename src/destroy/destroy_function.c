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

void destroy_button(button_t *button)
{
    sfText_destroy(button->contain);
    sfFont_destroy(button->font);
}

void destroy_fx(game_t *game)
{
    sfClock_destroy(game->clock);
    sfSprite_destroy(game->shot_struct.shot);
    sfSoundBuffer_destroy(game->shot_struct.shot_soundbuffer);
    sfSound_destroy(game->shot_struct.shot_sound);
}

void destroy_main(game_t *game, sfTexture **texture)
{
    destroy_window(game);
    if (game->wall_height)
        free_linklist(game->wall_height);
    free_tab(game->map.map2D);
    free(game->player);
    destroy_map(game, texture[0]);
    sfTexture_destroy(texture[1]);
    sfTexture_destroy(texture[2]);
    sfTexture_destroy(texture[3]);
    sfSprite_destroy(game->weapon.sprite);
    free(texture);
    destroy_fx(game);
}
