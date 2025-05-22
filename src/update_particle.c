/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** update_particle.c
*/

#include "proto.h"

static void delete_particle(particle_t *prev,
    particle_t **current, particle_t **begin)
{
    if (prev == NULL) {
        *begin = (*current)->next;
        sfRectangleShape_destroy((*current)->shape);
        free((*current));
        (*current) = *begin;
    } else {
        prev->next = (*current)->next;
        sfRectangleShape_destroy((*current)->shape);
        free((*current));
        (*current) = prev->next;
    }
}

void update_particles(float dt, particle_t **begin, game_t *game)
{
    particle_t *current = *begin;
    particle_t *prev = NULL;

    while (current != NULL) {
        current->lifetime -= dt;
        if (current->lifetime <= 0) {
            delete_particle(prev, &current, begin);
        } else {
            current->position.x += current->velocity.x * dt;
            current->position.y += current->velocity.y * dt;
            sfRectangleShape_setPosition(current->shape, current->position);
            sfRenderWindow_drawRectangleShape(game->windows.windows,
            current->shape, NULL);
            prev = current;
            current = current->next;
        }
    }
}
