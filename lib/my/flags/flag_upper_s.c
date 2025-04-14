/*
** EPITECH PROJECT, 2024
** Delivery (Espace de travail)
** File description:
** flag_upper_s.c
*/

#include <stdarg.h>
#include "../my.h"

char flag_upper_s(va_list list_arg, int v)
{
    char *str = va_arg(list_arg, char *);

    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            my_putchar(str[i] - 32);
        else
            my_putchar(str[i]);
    }
}
