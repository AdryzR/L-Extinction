/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** player_create
*/

#include "object/player.h"
#include "macro.h"


player_t *player_create(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL) {
        fputs("Error: Couldn't allocate enough memory to create a player\n", stderr);
        exit(ERROR);
    }

    // Set default values:
    player->sprite = sfSprite_create();
    player->state = PS_NORMAL;
    player->accel_y = 0;

    sfSprite_setOrigin(player->sprite, (sfVector2f){ 16.f, 32.f });
    sfSprite_setScale(player->sprite, (sfVector2f){ 1.75f, 1.75f });
    sfSprite_setPosition(player->sprite, (sfVector2f){
        32.f, WINDOW_HEIGHT / 2.f + 32.f
    });

    return player;
}
