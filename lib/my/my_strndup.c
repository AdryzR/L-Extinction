/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-esteban.munier
** File description:
** my_strndup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strndup(char const *src, int n)
{
    char *str;
    int i = 0;
    int k = 0;

    for (; src[i]; i++);
    str = malloc(sizeof(char) * (n + 1));
    if (str == NULL)
        return (str);
    while (k < i) {
        str[k] = src[k];
        k++;
    }
    str[k] = '\0';
    return (str);
}
