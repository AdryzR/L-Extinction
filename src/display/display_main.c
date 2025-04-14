/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** display_main.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <stdbool.h>
#include "proto.h"

bool get_action_time(sfClock *clock, const float every, float *last_action)
{
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    if (elapsed - *last_action >= every) {
        *last_action = elapsed;
        return 1;
    }
    return 0;
}

int display_main(game_t *game, entity_t *entity)
{
    game->i = get_action_time(game->clock, 0.05, &game->lastchance);
    display_window(game);
    // if (display_text(game) == 84)
    //     return 84;
    // display_entity(game, entity);
    sfRenderWindow_display(game->windows.windows);
    return 0;
}
