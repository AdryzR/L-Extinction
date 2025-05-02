/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** free_linklist.c
*/

#include "my.h"

list_object_t *free_object(list_object_t *object)
{
    if (object)
        free(object);
    return NULL;
}

linked_list_t *free_linklist(linked_list_t *link)
{
    linked_list_t *to_free = NULL;

    while (link != NULL) {
        to_free = link;
        link->object = free_object(link->object);
        link = link->next;
        free(to_free);
    }
    return NULL;
}
