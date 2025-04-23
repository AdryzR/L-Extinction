/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** display_menu_loop.c
*/

#include "proto.h"

static void button_hover(game_t *game, text_t *text_start, text_t *text_quit)
{
    if (sfFloatRect_contains(&text_start->hitbox,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).x,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).y))
        sfText_setColor(text_start->contain, sfColor_fromRGB(211, 211, 211));
    else
        sfText_setColor(text_start->contain, sfWhite);
    if (sfFloatRect_contains(&text_quit->hitbox,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).x,
        (float)sfMouse_getPositionRenderWindow(game->windows.windows).y))
        sfText_setColor(text_quit->contain, sfColor_fromRGB(211, 211, 211));
    else
        sfText_setColor(text_quit->contain, sfWhite);
}

static int analyse_menu_event(game_t *game, text_t *text_start,
    text_t *text_quit, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft &&
    sfFloatRect_contains((&text_start->hitbox),
    (float)event.mouseButton.x, (float)event.mouseButton.y)) {
        sfText_setColor(text_start->contain, sfColor_fromRGB(128, 128, 128));
        return 1;
    }
    if (event.type == sfEvtClosed || (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft &&
    sfFloatRect_contains((&text_quit->hitbox),
    (float)event.mouseButton.x, (float)event.mouseButton.y))) {
        sfText_setColor(text_quit->contain, sfColor_fromRGB(128, 128, 128));
        sfRenderWindow_close(game->windows.windows);
        return 2;
    }
    button_hover(game, text_start, text_quit);
    return 0;
}

int display_menu_loop(game_t *game, text_t *text_start, text_t *text_quit)
{
    int play = 0;
    sfEvent event;

    while (play == 0) {
        while (sfRenderWindow_pollEvent(game->windows.windows, &event))
            play = analyse_menu_event(game, text_start, text_quit, event);
        update_menu(game, text_start, text_quit);
        sfRenderWindow_drawSprite(game->windows.windows,
        game->windows.background.sprite, NULL);
        sfRenderWindow_drawText(game->windows.windows,
            text_start->contain, NULL);
        sfRenderWindow_drawText(game->windows.windows,
            text_quit->contain, NULL);
        sfRenderWindow_display(game->windows.windows);
    }
    if (play == 2)
        return 1;
    return 0;
}
