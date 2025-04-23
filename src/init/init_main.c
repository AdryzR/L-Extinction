/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_main.c
*/

#include "proto.h"

static key_struct_t init_key(void)
{
    key_struct_t key = {0};

    return key;
}

static int init_fx(game_t *game)
{
    game->clock = sfClock_create();
    if (!game->clock)
        return 84;
    game->lastchance = 0.0;
    game->multiplicator = 1;
    game->camera_y = 100.0;
    game->key = init_key();
    game->wall_height = NULL;
    return 0;
}

int init_main(game_t *game, sfTexture **texture)
{
    if (init_fx(game) == 84) {
        destroy_window(game);
        sfTexture_destroy(texture[0]);
        free(texture);
        destroy_fx(game);
        return 84;
    }
    if (init_map(game, texture[0]) == 84) {
        destroy_main(game, texture);
        return 84;
    }
    game->player = malloc(sizeof(player_t));
    if (init_player(game, game->player) == NULL) {
        destroy_main(game, texture);
        return 84;
    }
    return 0;
}
