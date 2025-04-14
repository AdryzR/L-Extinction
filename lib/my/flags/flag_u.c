/*
** EPITECH PROJECT, 2024
** Delivery (Espace de travail)
** File description:
** flag_u.c
*/

#include <stdarg.h>
#include "../my.h"

int my_put_unsigned_nbr(unsigned int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_put_nbr(nb);
    }
}

char flag_u(va_list list_arg, int v)
{
    my_put_unsigned_nbr((unsigned int)va_arg(list_arg, int));
}
