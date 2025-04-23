/*
** EPITECH PROJECT, 2024
** my_str_isnum
** File description:
** Returns 1 if the string only contains digits and
** 0 otherwise
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '-')
        i = 1;
    for (; str[i]; i++) {
        if (my_char_isnum(str[i]) == 0)
            return 0;
    }
    return 1;
}
