/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** allocates memory and copies the string
** given as an argument in it
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int k = 0;

    for (i; src[i]; i++);
    str = malloc(sizeof(char) * (i + 1));
    if (str == NULL)
        return (str);
    while (k < i) {
        str[k] = src[k];
        k++;
    }
    str[k] = '\0';
    return (str);
}
