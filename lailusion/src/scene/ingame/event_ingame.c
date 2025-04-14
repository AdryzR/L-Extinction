/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** event_menu.c
*/

#include "game.h"
#include "object/player.h"
#include "core.h"
#include "macro.h"

void event_ingame(game_t *game)
{
    if (!game)
        return;

    scene_ingame_t *data = game->scene->data;

    if (game->screen.event.type == sfEvtKeyReleased) {
        sfKeyEvent *evt_data = &game->screen.event.key;
        if (evt_data->code == sfKeyV) {
            data->color = (unsigned char)(data->color + 1) % 2;
            player_snap_to_platform(data);
        }
    }
}
