/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** print_tab.c
*/

#include "my.h"

void print_tab(char **tab)
{
    int size = my_strlen(tab[0]);

    for (int i = 0; i < size + 2; ++i)
        my_printf("+");
    my_printf("\n");
    for (int i = 0; tab[i]; ++i)
        my_printf("|%s|\n", tab[i]);
    for (int i = 0; i < size + 2; ++i)
        my_printf("+");
    my_printf("\n");
}
