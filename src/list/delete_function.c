/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** delete_function.c
*/

#include "proto.h"

void del_funct(plane_t *prev,
    plane_t **current, plane_t **begin)
{
    plane_t *tmp = *current;

    if (prev == NULL) {
        *begin = (*current)->next;
        sfRectangleShape_destroy((*current)->hitbox_dis);
        free(tmp);
        (*current) = *begin;
    } else {
        prev->next = (*current)->next;
        sfRectangleShape_destroy((*current)->hitbox_dis);
        free(tmp);
        (*current) = prev->next;
    }
}

void del_funct_bis(plane_t *prev,
    plane_t **current, plane_t **begin)
{
    plane_t *tmp = *current;

    if (prev == NULL) {
        *begin = (*current)->next;
        free(tmp);
        (*current) = *begin;
    } else {
        prev->next = (*current)->next;
        free(tmp);
        (*current) = prev->next;
    }
}
