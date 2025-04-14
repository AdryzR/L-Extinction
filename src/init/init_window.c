/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_window.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include "proto.h"

static sfRenderWindow *createmywindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My Radar", sfResize |
    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

int init_window(game_t *game)
{
    game->windows.windows = createmywindow(WINDOW_HEIGHT, WINDOW_WIDTH);
    if (!game->windows.windows)
        return 84;
    sfRenderWindow_setFramerateLimit(game->windows.windows, 60);
    return 0;
}
