/*
** EPITECH PROJECT, 2024
** my_rev_list
** File description:
** reverse a list
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *current = *begin;
    linked_list_t *next = (*begin)->next;
    linked_list_t *prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        *begin = current;
        current = next;
    }
}
