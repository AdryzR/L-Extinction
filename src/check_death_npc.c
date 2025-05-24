/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** check_death_npc.c
*/

#include "proto.h"

void delete_npc(npc_t *prev,
    npc_t **current, npc_t **begin, game_t *game)
{
    if ((rand() % 100) < DROP_CHANCE_PCT)
        add_ammo_drop(game, (*current)->position);
    if (prev == NULL) {
        *begin = (*current)->next;
        free((*current));
        (*current) = *begin;
    } else {
        prev->next = (*current)->next;
        free((*current));
        (*current) = prev->next;
    }
}

int check_death_npc(npc_t **begin, game_t *game)
{
    npc_t *current = *begin;
    npc_t *prev = NULL;

    while (current != NULL) {
        if (current->health <= 0) {
            delete_npc(prev, &current, begin, game);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return 0;
}
