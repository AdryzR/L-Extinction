/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** free_tab.c
*/

#include "my.h"

void free_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; ++i)
        free(tab[i]);
    free(tab);
}
