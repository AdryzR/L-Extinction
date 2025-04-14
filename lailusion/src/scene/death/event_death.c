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

void event_death(game_t *game)
{
    if (!game)
        return;
    
    scene_death_t *data = game->scene->data;

    if (game->screen.event.type == sfEvtMouseButtonReleased
    && game->screen.event.mouseButton.button == sfMouseLeft)
    {
        sfVector2i mousePos = sfMouse_getPositionRenderWindow(game->screen.window);
        sfFloatRect restart_button = sfSprite_getGlobalBounds(data->button);

        if (sfFloatRect_contains(&restart_button, (float)mousePos.x, (float)mousePos.y)) {
            game->speed = 1.0f;
            game->score = 0.0f;
            change_scene(game, ST_INGAME);
            return;
        }
    }
}
