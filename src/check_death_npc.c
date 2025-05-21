/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** check_death_npc.c
*/

#include "proto.h"

void delete_npc(npc_t *prev,
    npc_t **current, npc_t **begin)
{
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

int check_death_npc(npc_t **begin)
{
    npc_t *current = *begin;
    npc_t *prev = NULL;
    int i = 0;

    while (current != NULL) {
        if (current->health <= 0) {
            i = 1;
            delete_npc(prev, &current, begin);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return 0;
}
