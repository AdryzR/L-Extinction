/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** push_to_begin_list.c
*/

#include "my.h"

int push_to_begin_list(linked_list_t **begin, list_object_t *object)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));
    linked_list_t *lastNode = (*begin);

    if (!element)
        return 84;
    element->object = object;
    element->next = *begin;
    *begin = element;
    return 0;
}
