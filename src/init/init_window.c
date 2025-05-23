/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_window.c
*/

#include "proto.h"

sfRenderWindow *createmywindow(game_t *game, unsigned int width,
    unsigned int height, sfUint32 style)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    game->windows.height = height;
    game->windows.width = width;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Wolf3D", style, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

int init_window(game_t *game)
{
    game->windows.windows = createmywindow(game,
    WINDOW_WIDTH, WINDOW_HEIGHT, sfClose | sfResize);
    if (!game->windows.windows)
        return 84;
    sfRenderWindow_setFramerateLimit(game->windows.windows, 60);
    return 0;
}
