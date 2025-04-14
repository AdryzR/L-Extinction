/*
** EPITECH PROJECT, 2024
** Delivery (Espace de travail)
** File description:
** flag_i_d.c
*/

#include <stdarg.h>
#include "../my.h"

static int num_sign(int q, int i)
{
    if (q < 0) {
        my_putchar('-');
        i++;
    }
    return i;
}

char flag_integer(va_list list_arg, int v)
{
    int i = 0;
    int r = 0;
    int q = 0;

    q = va_arg(list_arg, int);
    i = num_sign(q, i);
    if (i == 1)
        q = q * (-1);
    r = q;
    if (v > 0) {
        for (i = 0; r > 0; i++)
            r = r / 10;
    }
    if (v > i) {
        for (; v > i; i++)
            my_put_nbr(0);
    }
    my_put_nbr(q);
}
