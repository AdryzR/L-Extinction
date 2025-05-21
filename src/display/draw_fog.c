/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** draw_fog.c
*/

#include "proto.h"

void draw_fog(game_t *game, int column,
    list_object_t *object, sfTexture *fog_texture)
{
    float top = (game->windows.height / object->data) + game->player->camera_y;
    float bottom = top + object->data;
    sfVertexArray *vertex_sky = create_sky(top, column);
    sfVertexArray *vertex_floor = create_floor(game, column, bottom);

    manage_quad(game, column, object, fog_texture);
    draw_vertex(game, vertex_sky, vertex_floor);
}
