/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** settings
*/

#include "proto.h"

static void init_buttons(button_t btns[3])
{
    create_button(&btns[0], "Quit the game",  0, 0);
    create_button(&btns[1], "Volume Up",      0, 0);
    create_button(&btns[2], "Volume Down",    0, 0);
}

static void update_layout(game_t *game, button_t btns[3])
{
    float W  = (float)game->windows.width;
    float H  = (float)game->windows.height;
    float x  = W * 0.4f;
    float y0 = H * 0.4f;
    float dy = H * 0.12f;

    sfText_setPosition(btns[0].contain, (sfVector2f){x,      y0    });
    sfText_setPosition(btns[1].contain, (sfVector2f){x, y0 + dy  });
    sfText_setPosition(btns[2].contain, (sfVector2f){x, y0 + 2*dy});
    btns[0].hitbox = sfText_getGlobalBounds(btns[0].contain);
    btns[1].hitbox = sfText_getGlobalBounds(btns[1].contain);
    btns[2].hitbox = sfText_getGlobalBounds(btns[2].contain);
}

static bool close_window(game_t *game)
{
    sfRenderWindow_close(game->windows.windows);
    return false;
}

static bool handle_event(game_t *game, button_t btns[3], sfEvent *evt)
{
    float vol;
    sfVector2i m;

    if (evt->type == sfEvtClosed)
        return close_window(game);
    if (evt->type == sfEvtKeyPressed && evt->key.code == sfKeyEscape)
        return false;
    if (evt->type == sfEvtMouseButtonPressed &&
        evt->mouseButton.button == sfMouseLeft)
    {
        m = sfMouse_getPositionRenderWindow(game->windows.windows);
        if (sfFloatRect_contains(&btns[0].hitbox, (float)m.x, (float)m.y)) {
            sfRenderWindow_close(game->windows.windows);
            return false;
        }
        if (sfFloatRect_contains(&btns[1].hitbox, (float)m.x, (float)m.y))
            sfListener_setGlobalVolume(sfListener_getGlobalVolume() + 10.f);
        if (sfFloatRect_contains(&btns[2].hitbox, (float)m.x, (float)m.y)) {
            vol = sfListener_getGlobalVolume() - 10.f;
            sfListener_setGlobalVolume(vol < 0.f ? 0.f : vol);
        }
    }
    return true;
}

static void draw_buttons(game_t *game, button_t btns[3])
{
    sfRenderWindow_clear(game->windows.windows, sfBlack);
    for (int i = 0; i < 3; ++i)
        sfRenderWindow_drawText(game->windows.windows, btns[i].contain, NULL);
    sfRenderWindow_display(game->windows.windows);
}

void open_settings(game_t *game)
{
    button_t btns[3];
    bool running = true;
    sfEvent evt;

    init_buttons(btns);
    while (running) {
        update_layout( game, btns );
        while (sfRenderWindow_pollEvent(game->windows.windows, &evt))
            running = handle_event(game, btns, &evt);
        draw_buttons(  game, btns );
    }
    for (int i = 0; i < 3; ++i) {
        sfText_destroy( btns[i].contain );
        sfFont_destroy( btns[i].font    );
    }
}