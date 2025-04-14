/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** display_loop.c
*/

#include "proto.h"

static void analyse_events_bis(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyJ &&
        game->multiplicator == 1)
        game->multiplicator = 3;
    else if (event.type == sfEvtKeyReleased && event.key.code == sfKeyJ &&
        game->multiplicator == 3)
        game->multiplicator = 1;
}

static void analyse_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->windows.windows);
        return;
    }
    if (event.type == sfEvtKeyReleased) {
        switch (event.key.code) {
            case sfKeyS:
                game->sprite_visible = !game->sprite_visible;
                break;
            case sfKeyL:
                game->box_visible = !game->box_visible;
                break;
            default:
                break;
        }
    }
    analyse_events_bis(game, event);
}

int display_loop(game_t *game, entity_t *entity)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->windows.windows)) {
        while (sfRenderWindow_pollEvent(game->windows.windows, &event))
            analyse_events(game, event);
        // if (display_main(game, entity) == 84)
        //     return 84;
        // if (entity->plane_botlft == NULL && entity->plane_botrht == NULL &&
        //     entity->plane_toplft == NULL && entity->plane_toprht == NULL)
        //     sfRenderWindow_close(game->windows.windows);
    }
    return 0;
}
