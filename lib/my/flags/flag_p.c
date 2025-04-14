/*
** EPITECH PROJECT, 2024
** B-CPE-101-STG-1-1-myprintf-kevser.akcan
** File description:
** flag_p.c
*/

#include <stdarg.h>
#include "../my.h"
#include <unistd.h>
#include <stdio.h>

static int my_put_hexa_upper_nbr(unsigned long nb)
{
    char tab[] = "0123456789abcdef";
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

char flag_p(va_list list_arg, int v)
{
    unsigned long nb;

    nb = va_arg(list_arg, unsigned long);
    my_putstr("0x");
    my_put_hexa_upper_nbr(nb);
}
