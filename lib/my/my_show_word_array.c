/*
** EPITECH PROJECT, 2024
** my_show_word_array
** File description:
** Display the content of an array of word
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (int k = 0; tab[k]; k++) {
        my_putstr(tab[k]);
    }
}
