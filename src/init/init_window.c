/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_window.c
*/

#include "proto.h"

static sfRenderWindow *createmywindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Wolf3D", sfResize |
    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

int init_window(game_t *game)
{
    game->windows.height = WINDOW_HEIGHT;
    game->windows.width = WINDOW_WIDTH;
    game->windows.windows = createmywindow(
    game->windows.width, game->windows.height);
    if (!game->windows.windows)
        return 84;
    sfRenderWindow_setFramerateLimit(game->windows.windows, 60);
    return 0;
}
