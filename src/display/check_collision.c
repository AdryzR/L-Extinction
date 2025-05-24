/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** check_front_colision.c
*/

#include "proto.h"

bool check_side_x_collision(game_t *game, sfVector2f position)
{
    if (is_entity(game, position.x + (PLAYER_COS_MOVE / 2),
        position.y, "#C") == 0 &&
        is_entity(game, position.x + 20 + (PLAYER_COS_MOVE / 2),
        position.y + 20, "#C") == 0 &&
        is_entity(game, position.x + 20 + (PLAYER_COS_MOVE / 2),
        position.y, "#C") == 0 &&
        is_entity(game, position.x + (PLAYER_COS_MOVE / 2),
        position.y + 20, "#C") == 0)
        return false;
    return true;
}

bool check_side_y_collision(game_t *game, sfVector2f position)
{
    if (is_entity(game, position.x,
        position.y + (PLAYER_SIN_MOVE / 2), "#C") == 0 &&
        is_entity(game, position.x + 20,
        position.y + 20 + (PLAYER_SIN_MOVE / 2), "#C") == 0 &&
        is_entity(game, position.x + 20,
        position.y + (PLAYER_SIN_MOVE / 2), "#C") == 0 &&
        is_entity(game, position.x,
        position.y + 20 + (PLAYER_SIN_MOVE / 2), "#C") == 0)
        return false;
    return true;
}

bool check_front_collision(game_t *game, sfVector2f position, int b)
{
    if (is_entity(game, position.x + (PLAYER_COS_MOVE * b),
        position.y + (PLAYER_SIN_MOVE * b), "#C") == 0 &&
        is_entity(game, position.x + 20 + (PLAYER_COS_MOVE * b),
        position.y + 20 + (PLAYER_SIN_MOVE * b), "#C") == 0 &&
        is_entity(game, position.x + 20 + (PLAYER_COS_MOVE * b),
        position.y + (PLAYER_SIN_MOVE * b), "#C") == 0 &&
        is_entity(game, position.x + (PLAYER_COS_MOVE * b),
        position.y + 20 + (PLAYER_SIN_MOVE * b), "#C") == 0)
        return false;
    return true;
}

bool check_back_collision(game_t *game, sfVector2f position, int b)
{
    if (is_entity(game, position.x - (PLAYER_COS_MOVE * b),
        position.y - (PLAYER_SIN_MOVE * b), "#C") == 0 &&
        is_entity(game, position.x + 20 - (PLAYER_COS_MOVE * b),
        position.y + 20 - (PLAYER_SIN_MOVE * b), "#C") == 0 &&
        is_entity(game, position.x + 20 - (PLAYER_COS_MOVE * b),
        position.y - (PLAYER_SIN_MOVE * b), "#C") == 0 &&
        is_entity(game, position.x - (PLAYER_COS_MOVE * b),
        position.y + 20 - (PLAYER_SIN_MOVE * b), "#C") == 0)
        return false;
    return true;
}
