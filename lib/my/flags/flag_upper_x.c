/*
** EPITECH PROJECT, 2024
** Delivery (Espace de travail)
** File description:
** flag_upper_x.c
*/

#include <stdarg.h>
#include "../my.h"
#include <unistd.h>
#include <stdio.h>

int my_put_hexa_upper_nbr(unsigned int nb)
{
    char tab[] = "0123456789ABCDEF";
    int n = 0;

    if (nb < 17) {
        my_putchar(tab[nb]);
    } else {
        n = nb % 16;
        nb = nb / 16;
        my_put_hexa_upper_nbr(nb);
        my_putchar(tab[n]);
    }
}

char flag_upper_x(va_list list_arg, int v)
{
    my_put_hexa_upper_nbr((unsigned int)va_arg(list_arg, int));
}
