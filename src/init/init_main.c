/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_main.c
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

static void init_scaling(game_t *game)
{
    game->top_lft = sfRectangleShape_create();
    sfRectangleShape_setSize(game->top_lft, (sfVector2f)
    {WINDOW_HEIGHT / 2 - 1, WINDOW_WIDTH / 2 - 2});
    sfRectangleShape_setPosition(game->top_lft, (sfVector2f) {1, 1});
    game->top_rht = sfRectangleShape_create();
    sfRectangleShape_setSize(game->top_rht, (sfVector2f)
    {WINDOW_HEIGHT / 2 - 3, WINDOW_WIDTH / 2 - 2});
    sfRectangleShape_setPosition(game->top_rht, (sfVector2f)
    {WINDOW_HEIGHT / 2 + 2, 1});
    game->bot_lft = sfRectangleShape_create();
    sfRectangleShape_setSize(game->bot_lft, (sfVector2f)
    {WINDOW_HEIGHT / 2 - 1, WINDOW_WIDTH / 2 - 2});
    sfRectangleShape_setPosition(game->bot_lft, (sfVector2f) {1, WINDOW_WIDTH / 2});
    game->bot_rht = sfRectangleShape_create();
    sfRectangleShape_setSize(game->bot_rht, (sfVector2f)
    {WINDOW_HEIGHT / 2 - 3, WINDOW_WIDTH / 2 - 2});
    sfRectangleShape_setPosition(game->bot_rht, (sfVector2f)
    {WINDOW_HEIGHT / 2 + 2, WINDOW_WIDTH / 2});
}

static int init_fx(game_t *game, entity_t **entity, sfTexture **texture)
{
    game->clock = sfClock_create();
    game->text.contain = sfText_create();
    game->text.font = sfFont_createFromFile(FONT);
    if (!game->clock || !game->text.contain || !game->text.font) {
        destroy_main(game, *entity, texture);
        return 84;
    }
    game->sprite_visible = true;
    sfText_setFont(game->text.contain, game->text.font);
    sfText_setPosition(game->text.contain, (sfVector2f) {1800, 5});
    sfText_setString(game->text.contain, "0");
    game->box_visible = false;
    game->lastchance = 0.0;
    game->multiplicator = 1;
    game->land = 0;
    game->dead = 0;
    return 0;
}

int init_main(game_t *game, entity_t **entity, sfTexture **texture,
    script_t *script)
{
    init_scaling(game);
    if (init_window(game) == 84) {
        sfRenderWindow_destroy(game->windows.windows);
        return 84;
    }
    // if (init_map(game, script) == 84) {
    //     sfRenderWindow_destroy(game->windows.windows);
    //     return 84;
    // }
    // game->player = malloc(sizeof(player_t));
    // if (init_player(game, game->player) == NULL) {
    //     sfRenderWindow_destroy(game->windows.windows);
    //     return 84;
    // }
    return 0;
}
