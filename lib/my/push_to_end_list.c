/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** push_to_list.c
*/

#include "my.h"

int push_to_end_list(linked_list_t **begin, list_object_t *object)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));
    linked_list_t *lastNode = (*begin);

    if (!element)
        return 84;
    element->object = object;
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
