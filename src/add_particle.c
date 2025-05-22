/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** add_particle.c
*/

#include "proto.h"

static void add_particle_element(particle_t *element, sfColor color,
    sfVector2f position, int size)
{
    float angle = ((float)rand() / RAND_MAX) * 2 * M_PI;
    float speed = ((float)rand() / RAND_MAX) + 50;

    element->position = position;
    element->velocity.x = cosf(angle) * speed;
    element->velocity.y = sinf(angle) * speed;
    element->lifetime = 5.0f;
    element->color = color;
    element->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(element->shape, (sfVector2f){size, size});
    sfRectangleShape_setFillColor(element->shape, element->color);
    sfRectangleShape_setPosition(element->shape, element->position);
}

int add_particle(particle_t **begin, sfColor color,
    sfVector2f position, int size)
{
    particle_t *element = malloc(sizeof(particle_t));
    particle_t *lastNode = (*begin);

    if (!element)
        return 84;
    add_particle_element(element, color, position, size);
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
