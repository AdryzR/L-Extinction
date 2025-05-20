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

void destroy_map(game_t *game)
{
    free_tab(game->map.map2D);
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

static void destroy_ui(player_t *player)
{
    sfSprite_destroy(player->ammo_sprite);
    sfSprite_destroy(player->hp_sprite);
    sfTexture_destroy(player->ammo_texture);
    sfTexture_destroy(player->hp_texture);
    sfText_destroy(player->ammo_txt);
    sfText_destroy(player->hp_txt);
    sfFont_destroy(player->font);
}

void destroy_main(game_t *game, sfTexture **texture)
{
    destroy_window(game);
    if (game->wall_height)
        free_linklist(game->wall_height);
    destroy_ui(game->player);
    free(game->player);
    destroy_map(game);
    destroy_texture(texture);
    sfSprite_destroy(game->weapon.sprite);
    destroy_fx(game);
}
