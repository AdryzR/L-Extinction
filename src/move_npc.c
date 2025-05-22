/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** move_npc.c
*/

#include "proto.h"

static sfVector2f make_move(game_t *game, sfVector2f position,
    float dx, float dy)
{
    sfVector2f temp_position;

    temp_position.x = position.x + dx * 1.5;
    temp_position.y = position.y + dy * 1.5;
    if (temp_position.x <= position.x && temp_position.y <= position.y
        && check_back_collision(game, position, 1) == false)
        return temp_position;
    if (temp_position.x > position.x && temp_position.y > position.y
        && check_front_collision(game, position, 1) == false)
        return temp_position;
    if (check_side_y_collision(game, position) == false) {
        position.y += dy * 1.5;
        return position;
    }
    if (check_side_x_collision(game, position) == false)
        position.x += dx * 1.5;
    return position;
}

sfVector2f move_npc(game_t *game, sfVector2f position)
{
    float dx = game->player->x - position.x;
    float dy = game->player->y - position.y;
    float distance = sqrt(dx * dx + dy * dy);

    if (distance == 0)
        return position;
    dx /= distance;
    dy /= distance;
    return make_move(game, position, dx, dy);
}
