/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** moove_data.c
*/

#include "proto.h"

static plane_t *move_plane_bis(plane_t *new_plane, plane_t *current)
{
    new_plane->object.position = current->object.position;
    new_plane->speed = current->speed;
    new_plane->arival = current->arival;
    new_plane->delay = current->delay;
    new_plane->hitbox_dis = current->hitbox_dis;
    new_plane->vector = current->vector;
    new_plane->safe = current->safe;
    new_plane->status = current->status;
    new_plane->id = current->id;
    return new_plane;
}

plane_t *move_pln(plane_t *current, plane_t **head)
{
    plane_t *temp = *head;
    plane_t *new_plane = malloc(sizeof(plane_t));

    if (!new_plane)
        return NULL;
    new_plane = move_plane_bis(new_plane, current);
    if (!temp) {
        new_plane->next = NULL;
        *head = new_plane;
        return *head;
    }
    for (; temp->next != NULL; temp = temp->next);
    temp->next = new_plane;
    new_plane->next = NULL;
    return *head;
}
