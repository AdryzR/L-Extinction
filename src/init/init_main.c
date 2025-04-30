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

static int init_fx(game_t *game, sfTexture *shot)
{
    game->clock = sfClock_create();
    if (!game->clock)
        return 84;
    game->lastchance = 0.0;
    game->multiplicator = 1;
    game->camera_y = 100.0;
    game->key = init_key();
    game->shot_struct.gunshot = false;
    game->shot_struct.shot = sfSprite_create();
    sfSprite_setTexture(game->shot_struct.shot, shot, sfTrue);
    sfSprite_setOrigin(game->shot_struct.shot, (sfVector2f){682 / 2, 682 / 2});
    sfSprite_setPosition(game->shot_struct.shot,
    (sfVector2f){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    game->wall_height = NULL;
    game->shot_struct.rect.top = 0;
    game->shot_struct.rect.left = 0;
    game->shot_struct.rect.height = 682;
    game->shot_struct.rect.width = 682;
    return 0;
}

int init_main(game_t *game, sfTexture **texture)
{
    if (init_fx(game, texture[1]) == 84) {
        destroy_window(game);
        sfTexture_destroy(texture[0]);
        sfTexture_destroy(texture[1]);
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
