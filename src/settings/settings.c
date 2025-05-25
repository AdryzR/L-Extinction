/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** settings
*/

#include "proto.h"

static void init_buttons(button_t btns[3])
{
    create_button(&btns[0], "Quit the game", 0, 0);
    create_button(&btns[1], "Volume Up", 0, 0);
    create_button(&btns[2], "Volume Down", 0, 0);
    create_button(&btns[3], "Toggle Music", 0, 0);
}

static void update_layout(game_t *game, button_t btns[3])
{
    float W = (float)game->windows.width;
    float H = (float)game->windows.height;
    float x = W * 0.4f;
    float y0 = H * 0.4f;
    float dy = H * 0.12f;

    sfText_setPosition(btns[0].contain, (sfVector2f){x, y0});
    sfText_setPosition(btns[1].contain, (sfVector2f){x, y0 + dy});
    sfText_setPosition(btns[2].contain, (sfVector2f){x, y0 + 2 * dy});
    sfText_setPosition(btns[3].contain, (sfVector2f){x, y0 + 3 * dy});
    for (int i = 0; i < 4; ++i)
        btns[i].hitbox = sfText_getGlobalBounds(btns[i].contain);
}

static bool close_window(game_t *game)
{
    sfRenderWindow_close(game->windows.windows);
    return false;
}

void handle_button_toggle_music(game_t *game)
{
    if (sfMusic_getStatus(game->music) == sfPlaying)
        sfMusic_pause(game->music);
    else
        sfMusic_play(game->music);
}

static bool handle_menu_buttons_event(game_t *game, button_t btns[3])
{
    float vol;
    sfVector2i m;

    if (game->menu_btn_sound)
        sfSound_play(game->menu_btn_sound);
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
    if (sfFloatRect_contains(&btns[3].hitbox, m.x, m.y))
        handle_button_toggle_music(game);
    return true;
}

static bool handle_event(game_t *game, button_t btns[3], sfEvent *evt)
{
    if (evt->type == sfEvtClosed)
        return close_window(game);
    if (evt->type == sfEvtKeyPressed && evt->key.code == sfKeyEscape)
        return false;
    if (evt->type == sfEvtMouseButtonPressed &&
        evt->mouseButton.button == sfMouseLeft) {
        return handle_menu_buttons_event(game, btns);
    }
    return true;
}

static void draw_buttons(game_t *game, button_t btns[3])
{
    sfRenderWindow_clear(game->windows.windows, sfBlack);
    for (int i = 0; i < 4; ++i)
        sfRenderWindow_drawText(game->windows.windows, btns[i].contain, NULL);
    sfRenderWindow_display(game->windows.windows);
}

void open_settings(game_t *game)
{
    button_t btns[4];
    bool running = true;
    sfEvent evt;

    init_buttons(btns);
    while (running) {
        update_layout(game, btns);
        while (sfRenderWindow_pollEvent(game->windows.windows, &evt))
            running = handle_event(game, btns, &evt);
        draw_buttons(game, btns);
    }
    for (int i = 0; i < 4; ++i) {
        sfText_destroy(btns[i].contain);
        sfFont_destroy(btns[i].font);
    }
}
