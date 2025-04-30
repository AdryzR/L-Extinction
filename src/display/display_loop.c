/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** display_loop.c
*/

#include "proto.h"

static void analyse_key(game_t *game, sfEvent event, bool status)
{
    if (game->key.S != status && event.key.code == sfKeyS)
        game->key.S = status;
    if (game->key.Z != status && event.key.code == sfKeyZ)
        game->key.Z = status;
    if (game->key.D != status && event.key.code == sfKeyD)
        game->key.D = status;
    if (game->key.Q != status && event.key.code == sfKeyQ)
        game->key.Q = status;
    if (game->key.Up != status && event.key.code == sfKeyUp)
        game->key.Up = status;
    if (game->key.Down != status && event.key.code == sfKeyDown)
        game->key.Down = status;
    if (game->key.shift != status && event.key.code == sfKeyLShift)
        game->key.shift = status;
}

static game_t *analyse_other_key_press(game_t *game, int b)
{
    if (game->key.Down == true && game->camera_y > -200)
        game->camera_y -= PLAYER_MOVE_SPEED * 2 * b;
    if (game->key.Up && game->camera_y < 1000)
        game->camera_y += PLAYER_MOVE_SPEED * 2 * b;
    if (game->key.Q == true)
        game->player->angle -= PLAYER_ROTATION_SPEED * b;
    if (game->key.D == true)
        game->player->angle += PLAYER_ROTATION_SPEED * b;
    if (game->key.Echap == true)
        open_settings(game);
    return game;
}

static void analyse_key_press(game_t *game)
{
    int b = 1;

    if (game->key.shift == true)
        b = 3;
    if (game->key.S == true) {
        if (check_back_collision(game, b) == false) {
            game->player->x -= PLAYER_COS_MOVE * b;
            game->player->y -= PLAYER_SIN_MOVE * b;
        }
    }
    if (game->key.Z == true) {
        if (check_front_collision(game, b) == false) {
            game->player->x += PLAYER_COS_MOVE * b;
            game->player->y += PLAYER_SIN_MOVE * b;
        }
    }
    game = analyse_other_key_press(game, b);
}

static void analyse_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->windows.windows);
        return;
    }
    if (event.type == sfEvtKeyPressed)
        analyse_key(game, event, true);
    if (event.type == sfEvtKeyReleased)
        analyse_key(game, event, false);
}

int display_loop(game_t *game)
{
    sfEvent event;

    cast_all_rays(game->player, &game);
    while (sfRenderWindow_isOpen(game->windows.windows)) {
        game->i = get_action_time(game->clock, 0.01, &game->lastchance);
        while (sfRenderWindow_pollEvent(game->windows.windows, &event))
            analyse_events(game, event);
        if (game->i == true)
            analyse_key_press(game);
        if (game->player->angle > 360)
            game->player->angle -= 360;
        if (game->player->angle < -360)
            game->player->angle += 360;
        if (is_movement(&game->key) == true && game->i == true)
            cast_all_rays(game->player, &game);
        if (display_main(game) == 84)
            return 84;
    }
    return 0;
}
