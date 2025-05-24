/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** manage_npc.c
*/

#include "proto.h"

void manage_npc(game_t *game)
{
    for (npc_t *temp_npc = game->npc; temp_npc;
        temp_npc = temp_npc->next) {
        draw_sprite(game, temp_npc);
        temp_npc->hit = false;
        if (game->i == true)
            temp_npc->position = move_npc(game, temp_npc->position);
    }
    update_particles(1.f, &game->particle, game);
    check_death_npc(&game->npc, game);
}
