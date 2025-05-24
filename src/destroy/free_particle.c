/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** free_particle.c
*/

#include "proto.h"

npc_t *free_npc(game_t *game)
{
    npc_t *to_free = NULL;

    while (game->npc != NULL) {
        to_free = game->npc;
        game->npc = game->npc->next;
        free(to_free);
    }
    return NULL;
}

particle_t *free_particle(game_t *game)
{
    particle_t *to_free = NULL;

    while (game->particle != NULL) {
        to_free = game->particle;
        game->particle = game->particle->next;
        free(to_free);
    }
    return NULL;
}
