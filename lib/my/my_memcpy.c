/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-esteban.munier
** File description:
** my_memcpy.c
*/

#include "my.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    size_t len = ((size_t) my_strlen(((char *)src)));

    while (i < n) {
        if (i < len) {
            ((char *)dest)[i] = ((char *)src)[i];
            i++;
            continue;
        }
        ((char *)dest)[i] = '\0';
        i++;
    }
    return (dest);
}
