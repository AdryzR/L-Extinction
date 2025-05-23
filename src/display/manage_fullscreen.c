/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** manage_fullscreen.c
*/

#include "proto.h"

void manage_fullscreen(game_t *game, sfEvent event)
{
    size_t count;
    sfVideoMode *mode = sfVideoMode_getFullscreenModes(&count);

    if (event.key.code == sfKeyF11 && game->fullscreen == false) {
            sfRenderWindow_close(game->windows.windows);
            game->windows.windows = createmywindow(game, mode[0].width,
            mode[0].height, sfFullscreen);
            game->fullscreen = true;
            return;
        }
    if (event.key.code == sfKeyF11 && game->fullscreen == true) {
        sfRenderWindow_close(game->windows.windows);
        game->windows.windows = createmywindow(game,
        1920, 1080, sfClose | sfResize);
        game->fullscreen = false;
        return;
    }
}
