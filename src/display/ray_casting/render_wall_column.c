/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** render_wall_column.c
*/

#include "proto.h"

void draw_vertex(game_t *game, sfVertexArray *vertex_sky,
    sfVertexArray *vertex_floor)
{
    sfRenderWindow_drawVertexArray(game->windows.windows, vertex_floor, NULL);
    sfRenderWindow_drawVertexArray(game->windows.windows, vertex_sky, NULL);
    sfVertexArray_destroy(vertex_sky);
    sfVertexArray_destroy(vertex_floor);
}

sfVertexArray *create_sky(float top, int column)
{
    sfVertexArray *vertex_sky = sfVertexArray_create();
    sfVertex vertex1 = {{column, top}, GREY, {0, 0}, };
    sfVertex vertex2 = {{column, 0}, GREY, {0, 0}};

    sfVertexArray_append(vertex_sky, vertex1);
    sfVertexArray_append(vertex_sky, vertex2);
    sfVertexArray_setPrimitiveType(vertex_sky, sfLinesStrip);
    return vertex_sky;
}

sfVertexArray *create_floor(game_t *game, int column, float bottom)
{
    sfVertexArray *vertex_floor = sfVertexArray_create();
    sfVertex vertex1 = {{column, bottom}, LIGHT_GREY, {0, 0}};
    sfVertex vertex2 = {{column, game->windows.height}, LIGHT_GREY, {0, 0}};

    sfVertexArray_append(vertex_floor, vertex1);
    sfVertexArray_append(vertex_floor, vertex2);
    sfVertexArray_setPrimitiveType(vertex_floor, sfLinesStrip);
    return vertex_floor;
}

static float init_texu(list_object_t *object, sfTexture *wall_texture)
{
    if (fabsf(object->offset_x) > fabsf(object->offset_y))
        return object->hit_y / TILE_SIZE * sfTexture_getSize(wall_texture).x;
    return object->hit_x / TILE_SIZE * sfTexture_getSize(wall_texture).y;
}

static sfVertex *init_quad(game_t *game, int column, sfTexture *wall_texture,
    list_object_t *object)
{
    const float top = (game->windows.height /
    object->data) + game->player->camera_y;
    const float bottom = top + object->data;
    const float texU = init_texu(object, wall_texture);
    sfVertex *quad = malloc(sizeof(sfVertex) * 4);

    quad[0].position = (sfVector2f){column, top};
    quad[1].position = (sfVector2f){column + 1, top};
    quad[2].position = (sfVector2f){column + 1, bottom};
    quad[3].position = (sfVector2f){column, bottom};
    quad[0].texCoords = (sfVector2f){texU, 0};
    quad[1].texCoords = (sfVector2f){texU + 1, 0};
    quad[2].texCoords = (sfVector2f){texU + 1,
    sfTexture_getSize(wall_texture).y};
    quad[3].texCoords = (sfVector2f){texU, sfTexture_getSize(wall_texture).y};
    quad[0].color = sfColor_fromRGBA(255, 255, 255, 255);
    quad[1].color = sfColor_fromRGBA(255, 255, 255, 255);
    quad[2].color = sfColor_fromRGBA(255, 255, 255, 255);
    quad[3].color = sfColor_fromRGBA(255, 255, 255, 255);
    return quad;
}

void manage_quad(game_t *game, int column,
    list_object_t *object, sfTexture *wall_texture)
{
    sfVertex *quad =
    init_quad(game, column, wall_texture, object);
    sfRenderStates states = {0};

    states.texture = wall_texture;
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    sfRenderWindow_drawPrimitives(game->windows.windows, quad, 4,
    sfQuads, &states);
    free(quad);
}

void render_wall_column(game_t *game, int column,
    list_object_t *object, sfTexture *wall_texture)
{
    float top = (game->windows.height / object->data) + game->player->camera_y;
    float bottom = top + object->data;
    sfVertexArray *vertex_sky = create_sky(top, column);
    sfVertexArray *vertex_floor = create_floor(game, column, bottom);

    manage_quad(game, column, object, wall_texture);
    draw_vertex(game, vertex_sky, vertex_floor);
}
