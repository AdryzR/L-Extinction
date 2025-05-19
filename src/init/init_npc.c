/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** init_npc.c
*/

#include "proto.h"

static int add_npc(npc_t **begin, object_t *object)
{
    npc_t *element = malloc(sizeof(npc_t));
    npc_t *lastNode = (*begin);

    if (!element)
        return 84;
    element->health = 100;
    element->hit_box = (sfIntRect){0};
    element->zombie = object;
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
    object_t object;

    for (int k = 0; k < my_strlen(game->map.map2D[i]); ++k)
        if (game->map.map2D[i][k] == 'z') {
            object = init_object_sprite(game->zombie, (sfVector2f)
            {k * TILE_SIZE, i * TILE_SIZE});
            add_npc(&npc, &object);
        }
}

npc_t *init_npc(game_t *game, npc_t *npc)
{
    for (int i = 0; i < game->map.height; ++i)
        find_spawn_point(game, npc, i);
    return npc;
}
