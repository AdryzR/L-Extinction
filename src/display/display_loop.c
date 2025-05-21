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
    if (game->key.Echap != status && event.key.code == sfKeyEscape)
        game->key.Echap = status;
}

static game_t *analyse_other_key_press(game_t *game, int b)
{
    if (game->key.Down == true && game->player->camera_y > -200)
        game->player->camera_y -= PLAYER_MOVE_SPEED * 2 * b;
    if (game->key.Up && game->player->camera_y < 400)
        game->player->camera_y += PLAYER_MOVE_SPEED * 2 * b;
    if (game->key.Q == true)
        game->player->camera_x -= PLAYER_ROTATION_SPEED * b;
    if (game->key.D == true)
        game->player->camera_x += PLAYER_ROTATION_SPEED * b;
    if (game->key.Echap == true)
        open_settings(game);
    return game;
}

void manage_s(game_t *game, int b)
{
    bool enter = false;

    if (check_back_collision(game, b) == false) {
        game->player->x -= PLAYER_COS_MOVE * b;
        game->player->y -= PLAYER_SIN_MOVE * b;
        enter = true;
    }
    if (enter == false && check_side_y_collision(game) == false) {
        game->player->y += PLAYER_SIN_MOVE / 2;
        enter = true;
    }
    if (enter == false && check_side_x_collision(game) == false)
        game->player->x += PLAYER_COS_MOVE / 2;
}

void manage_z(game_t *game, int b)
{
    bool enter = false;

    if (check_front_collision(game, b) == false) {
        game->player->x += PLAYER_COS_MOVE * b;
        game->player->y += PLAYER_SIN_MOVE * b;
        enter = true;
    }
    if (enter == false && check_side_y_collision(game) == false) {
        game->player->y += PLAYER_SIN_MOVE / 2;
        enter = true;
    }
    if (enter == false && check_side_x_collision(game) == false)
        game->player->x += PLAYER_COS_MOVE / 2;
}

static void analyse_key_press(game_t *game)
{
    int b = 1;

    if (game->key.shift == true)
        b = 3;
    if (game->key.S == true)
        manage_s(game, b);
    if (game->key.Z == true)
        manage_z(game, b);
    game = analyse_other_key_press(game, b);
}

static void analyse_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->windows.windows);
        return;
    }
    if (event.type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        game->shot_struct.gunshot = (game->player->ammo != 0) ? true : false;
        check_npc_hit(game);
        update_ammo(game);
        sfSound_play(game->shot_struct.shot_sound);
    }
    update_hp(game);
    if (event.type == sfEvtKeyPressed)
        analyse_key(game, event, true);
    if (event.type == sfEvtKeyReleased)
        analyse_key(game, event, false);
}

static void manage_loop(game_t *game)
{
    if (game->i == true)
        analyse_key_press(game);
    if (game->player->camera_x > deg_to_rad(360))
        game->player->camera_x -= deg_to_rad(360);
    if (game->player->camera_x < deg_to_rad(-360))
        game->player->camera_x += deg_to_rad(360);
    if (is_movement(&game->key) == true && game->i == true) {
        game->wall_height = free_linklist(game->wall_height);
        cast_all_rays(game->player, &game);
    }
}

int display_loop(game_t *game, sfTexture **texture)
{
    sfEvent event;

    cast_all_rays(game->player, &game);
    while (sfRenderWindow_isOpen(game->windows.windows)) {
        game->i = get_action_time(game->clock, 0.001, &game->lastchance);
        for (game->windows.width = sfRenderWindow_getSize(game->windows.
        windows).x; game->windows.width % 4 != 0; --game->windows.width);
        for (game->windows.height = sfRenderWindow_getSize(game->windows.
        windows).y; game->windows.height % 4 != 0; --game->windows.height);
        sfRenderWindow_setSize(game->windows.windows, (sfVector2u)
        {game->windows.width, game->windows.height});
        while (sfRenderWindow_pollEvent(game->windows.windows, &event))
            analyse_events(game, event);
        manage_loop(game);
        if (display_main(game, texture) == 84)
            return 84;
    }
    return 0;
}
