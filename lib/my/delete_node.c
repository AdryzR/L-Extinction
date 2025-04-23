/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** delete_node.c
*/

#include "my.h"

void delete_function(linked_list_t *prev,
    linked_list_t **current, linked_list_t **begin)
{
    if (prev == NULL) {
        *begin = (*current)->next;
        free_object((*current)->object);
        free((*current));
        (*current) = *begin;
    } else {
        prev->next = (*current)->next;
        free_object((*current)->object);
        free((*current));
        (*current) = prev->next;
    }
}

int delete_in_list(linked_list_t **begin, int id)
{
    linked_list_t *current = *begin;
    linked_list_t *prev = NULL;
    int i = 0;

    while (current != NULL) {
        if (current->object->id == id) {
            i = 1;
            delete_function(prev, &current, begin);
        } else {
            prev = current;
            current = current->next;
        }
    }
    if (i == 0) {
        my_printf("ID unknow please check if this id exist.\n");
        return 84;
    }
    return 0;
}
