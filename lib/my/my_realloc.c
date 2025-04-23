/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-esteban.munier
** File description:
** my_realloc.c
*/

#include "my.h"
#include <stdlib.h>

void safe_free(void **ptr)
{
    if (ptr || *ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(sizeof(void) * size);

    if (ptr == NULL || size < 0)
        return (NULL);
    my_memcpy(new_ptr, ptr, size);
    safe_free(&ptr);
    return (new_ptr);
}
