/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** render_wall_column.c
*/

#include "proto.h"

void draw_vertex(game_t *game, sfVertexArray *vertex_sky,
    sfVertexArray *vertex_floor, sfVertexArray *vertex_array)
{
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    sfRenderWindow_drawVertexArray(game->windows.windows, vertex_array, NULL);
    sfRenderWindow_drawVertexArray(game->windows.windows, vertex_floor, NULL);
    sfRenderWindow_drawVertexArray(game->windows.windows, vertex_sky, NULL);
    sfVertexArray_destroy(vertex_array);
    sfVertexArray_destroy(vertex_sky);
    sfVertexArray_destroy(vertex_floor);
}

sfVertexArray *create_sky(float top, float column)
{
    sfVertexArray *vertex_sky = sfVertexArray_create();
    sfVertex vertex1 = {{column, top}, SKY_BLUE, {0, 0}};
    sfVertex vertex2 = {{column, 0}, SKY_BLUE, {0, 0}};

    sfVertexArray_append(vertex_sky, vertex1);
    sfVertexArray_append(vertex_sky, vertex2);
    sfVertexArray_setPrimitiveType(vertex_sky, sfLinesStrip);
    return vertex_sky;
}

sfVertexArray *create_floor(float column, float bottom)
{
    sfVertexArray *vertex_floor = sfVertexArray_create();
    sfVertex vertex1 = {{column, bottom}, GREEN_GRASS, {0, 0}};
    sfVertex vertex2 = {{column, WINDOW_HEIGHT}, GREEN_GRASS, {0, 0}};

    sfVertexArray_append(vertex_floor, vertex1);
    sfVertexArray_append(vertex_floor, vertex2);
    sfVertexArray_setPrimitiveType(vertex_floor, sfLinesStrip);
    return vertex_floor;
}

void render_wall_column(game_t *game, float column,
    float wall_height, sfColor color)
{
    float top = (WINDOW_HEIGHT / wall_height) + game->camera_y;
    float bottom = top + wall_height;
    sfVertexArray *vertex_sky = create_sky(top, column);
    sfVertexArray *vertex_floor = create_floor(column, bottom);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {{column, top}, color, {0, 0}};
    sfVertex vertex2 = {{column, bottom}, color, {0, 0}};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    draw_vertex(game, vertex_sky, vertex_floor, vertex_array);
}
