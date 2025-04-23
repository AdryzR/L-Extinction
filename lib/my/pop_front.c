/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** pop_front.c
*/

#include "my.h"

void pop_front(linked_list_t **begin)
{
    linked_list_t *current = *begin;
    linked_list_t *prev = NULL;

    delete_function(prev, &current, begin);
}
