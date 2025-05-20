/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** check_front_colision.c
*/

#include "proto.h"

bool check_side_x_collision(game_t *game)
{
    if (is_entity(game, game->player->x + (PLAYER_COS_MOVE / 2),
        game->player->y, '#') == 0 &&
        is_entity(game, game->player->x + 20 + (PLAYER_COS_MOVE / 2),
        game->player->y + 20, '#') == 0 &&
        is_entity(game, game->player->x + 20 + (PLAYER_COS_MOVE / 2),
        game->player->y, '#') == 0 &&
        is_entity(game, game->player->x + (PLAYER_COS_MOVE / 2),
        game->player->y + 20, '#') == 0)
        return false;
    return true;
}

bool check_side_y_collision(game_t *game)
{
    if (is_entity(game, game->player->x,
        game->player->y + (PLAYER_SIN_MOVE / 2), '#') == 0 &&
        is_entity(game, game->player->x + 20,
        game->player->y + 20 + (PLAYER_SIN_MOVE / 2), '#') == 0 &&
        is_entity(game, game->player->x + 20,
        game->player->y + (PLAYER_SIN_MOVE / 2), '#') == 0 &&
        is_entity(game, game->player->x,
        game->player->y + 20 + (PLAYER_SIN_MOVE / 2), '#') == 0)
        return false;
    return true;
}

bool check_front_collision(game_t *game, int b)
{
    if (is_entity(game, game->player->x + (PLAYER_COS_MOVE * b),
        game->player->y + (PLAYER_SIN_MOVE * b), '#') == 0 &&
        is_entity(game, game->player->x + 20 + (PLAYER_COS_MOVE * b),
        game->player->y + 20 + (PLAYER_SIN_MOVE * b), '#') == 0 &&
        is_entity(game, game->player->x + 20 + (PLAYER_COS_MOVE * b),
        game->player->y + (PLAYER_SIN_MOVE * b), '#') == 0 &&
        is_entity(game, game->player->x + (PLAYER_COS_MOVE * b),
        game->player->y + 20 + (PLAYER_SIN_MOVE * b), '#') == 0)
        return false;
    return true;
}

bool check_back_collision(game_t *game, int b)
{
    if (is_entity(game, game->player->x - (PLAYER_COS_MOVE * b),
        game->player->y - (PLAYER_SIN_MOVE * b), '#') == 0 &&
        is_entity(game, game->player->x + 20 - (PLAYER_COS_MOVE * b),
        game->player->y + 20 - (PLAYER_SIN_MOVE * b), '#') == 0 &&
        is_entity(game, game->player->x + 20 - (PLAYER_COS_MOVE * b),
        game->player->y - (PLAYER_SIN_MOVE * b), '#') == 0 &&
        is_entity(game, game->player->x - (PLAYER_COS_MOVE * b),
        game->player->y + 20 - (PLAYER_SIN_MOVE * b), '#') == 0)
        return false;
    return true;
}
