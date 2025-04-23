/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** pop_back.c
*/

#include "my.h"

void pop_back(linked_list_t **begin)
{
    linked_list_t *current = *begin;
    linked_list_t *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    delete_function(prev, &current, begin);
}
