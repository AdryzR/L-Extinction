/*
** EPITECH PROJECT, 2024
** my_list_size
** File description:
** return the list size
*/

#include "my.h"
#include <stddef.h>

int my_list_size(linked_list_t const *begin)
{
    int i = 0;

    for (; begin != NULL; i++) {
        begin = begin->next;
    }
    return i;
}
