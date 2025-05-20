/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** init_npc.c
*/

#include "proto.h"

static int add_npc(npc_t **begin, sfTexture *texture, int y, int x)
{
    npc_t *element = malloc(sizeof(npc_t));
    npc_t *lastNode = (*begin);

    if (!element)
        return 84;
    element->health = 100;
    element->hit_box = (sfIntRect){0};
    element->texture = texture;
    element->position = (sfVector2f) {y * TILE_SIZE, x * TILE_SIZE};
    element->next = NULL;
    if (*begin == NULL) {
        (*begin) = element;
        return 0;
    }
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = element;
    return 0;
}

static void find_spawn_point(game_t *game, npc_t *npc, int i)
{
    for (int k = 0; k < my_strlen(game->map.map2D[i]); ++k)
        if (game->map.map2D[i][k] == 'z') {
            add_npc(&npc, game->zombie_texture, i, k);
        }
}

npc_t *init_npc(game_t *game, npc_t *npc)
{
    for (int i = 0; i < game->map.height; ++i)
        find_spawn_point(game, npc, i);
    return npc;
}
