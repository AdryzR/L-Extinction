/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** draw_npc.c
*/

#include "proto.h"

void draw_sprite(game_t *game, int column, list_object_t *object, sfTexture *zombie)
{
    // --- Initialisation des variables ---
    float sprite_height = WINDOW_HEIGHT / object->data_entity;
    float draw_start = (WINDOW_HEIGHT / 2.0f) - (sprite_height / 2.0f);
    float draw_end = draw_start + sprite_height;

    // Clamp draw_start et draw_end pour rester dans l'écran
    if (draw_start < 0) draw_start = 0;
    if (draw_end > WINDOW_HEIGHT) draw_end = WINDOW_HEIGHT;

    sfVector2u tex_size = sfTexture_getSize(zombie);
    float tex_x = tex_size.x / 2.0f; // Slice centrale du sprite

    // --- Construction du quad ---
    sfVertex quad[4];

    quad[0].position = (sfVector2f){column, draw_start};
    quad[1].position = (sfVector2f){column + 1, draw_start};
    quad[2].position = (sfVector2f){column + 1, draw_end};
    quad[3].position = (sfVector2f){column, draw_end};

    quad[0].texCoords = (sfVector2f){tex_x, 0};
    quad[1].texCoords = (sfVector2f){tex_x + 1, 0};
    quad[2].texCoords = (sfVector2f){tex_x + 1, tex_size.y};
    quad[3].texCoords = (sfVector2f){tex_x, tex_size.y};

    for (int i = 0; i < 4; i++)
        quad[i].color = sfWhite;

    // --- Création et affichage de l'array ---
    sfVertexArray *va = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(va, sfQuads);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(va, quad[i]);

    sfRenderStates state = {
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = zombie,
        .shader = NULL
    };

    sfRenderWindow_drawVertexArray(game->windows.windows, va, &state);
    sfVertexArray_destroy(va);
}

