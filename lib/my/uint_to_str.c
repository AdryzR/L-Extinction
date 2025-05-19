/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** uint_to_str
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Convertit un unsigned int en chaîne de caractères.
 *
 * @param value la valeur à convertir
 * @return pointeur vers une nouvelle chaîne malloc()ée contenant la
 * représentation décimale, ou NULL en cas d'échec d'allocation.
 */
char *uint_to_str(unsigned int value)
{
    int len = snprintf(NULL, 0, "%u", value);
    char *str;

    if (len < 0)
        return NULL;
    str = malloc((size_t)len + 1);
    if (!str)
        return NULL;
    snprintf(str, (size_t)len + 1, "%u", value);
    return str;
}
