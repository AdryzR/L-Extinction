/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** display_menu_loop.c
*/

#include "proto.h"

static void button_hover(game_t *game, button_t *bstart, button_t *bquit)
{
    if (sfFloatRect_contains(&bstart->hitbox,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).x,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).y))
        sfText_setColor(bstart->contain, sfColor_fromRGB(211, 211, 211));
    else
        sfText_setColor(bstart->contain, sfWhite);
    if (sfFloatRect_contains(&bquit->hitbox,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).x,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).y))
        sfText_setColor(bquit->contain, sfColor_fromRGB(211, 211, 211));
    else
        sfText_setColor(bquit->contain, sfWhite);
}

static int analyse_menu_event(game_t *game, button_t *bstart,
    button_t *bquit, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft &&
    sfFloatRect_contains((&bstart->hitbox),
    (float)event.mouseButton.x, (float)event.mouseButton.y)) {
        sfText_setColor(bstart->contain, sfColor_fromRGB(128, 128, 128));
        return 1;
    }
    if (event.type == sfEvtClosed || (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft &&
    sfFloatRect_contains((&bquit->hitbox),
    (float)event.mouseButton.x, (float)event.mouseButton.y))) {
        sfText_setColor(bquit->contain, sfColor_fromRGB(128, 128, 128));
        sfRenderWindow_close(game->windows.windows);
        return 2;
    }
    button_hover(game, bstart, bquit);
    return 0;
}

int display_menu_loop(game_t *game, button_t *bstart, button_t *bquit)
{
    int play = 0;
    sfEvent event;

    while (play == 0) {
        while (sfRenderWindow_pollEvent(game->windows.windows, &event))
            play = analyse_menu_event(game, bstart, bquit, event);
        update_menu(game, bstart, bquit);
        sfRenderWindow_drawSprite(game->windows.windows,
        game->windows.background.sprite, NULL);
        sfRenderWindow_drawText(game->windows.windows,
            bstart->contain, NULL);
        sfRenderWindow_drawText(game->windows.windows,
            bquit->contain, NULL);
        sfRenderWindow_display(game->windows.windows);
    }
    if (play == 2)
        return 1;
    return 0;
}
