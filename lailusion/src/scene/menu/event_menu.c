/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** event_menu.c
*/

#include "game.h"
#include "core.h"
#include "macro.h"
#include "sound.h"

void event_menu(game_t *game)
{
    if (!game || !game->scene)
        return;

    scene_menu_t *data = game->scene->data;

    if (game->screen.event.type == sfEvtMouseButtonReleased
    && game->screen.event.mouseButton.button == sfMouseLeft)
    {
        sfVector2i mousePos = sfMouse_getPositionRenderWindow(game->screen.window);
        sfFloatRect startButton = sfSprite_getGlobalBounds(data->button[0]);
        sfFloatRect quitButton = sfSprite_getGlobalBounds(data->button[1]);

        if (sfFloatRect_contains(&startButton, (float)mousePos.x, (float)mousePos.y)) {
            change_music(game, START);
            change_scene(game, ST_INGAME);
            return;
        }
        if (sfFloatRect_contains(&quitButton, (float)mousePos.x, (float)mousePos.y)) {
            CLOSE(game->screen.window);
            return;
        }
    }
}
