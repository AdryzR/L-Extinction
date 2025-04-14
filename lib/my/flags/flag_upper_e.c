/*
** EPITECH PROJECT, 2024
** B-CPE-101-STG-1-1-myprintf-kevser.akcan
** File description:
** flag_upper_e.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "../my.h"
#include "../my_printf_h.h"

int my_put_expo_up_e_deux(double nb, int v, int i)
{
    if (nb > -1 && nb < 1) {
        for (; nb < 1; i++)
            nb = nb * 10;
        my_put_float_nbr_up_f(nb, v);
        my_putstr("E-");
    }
    return i;
}

char my_put_expo_up_e(double nb, int v)
{
    int i = 0;

    if (nb < 0){
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb > 10) {
        for (; nb > 10; i++)
            nb = nb / 10;
        my_put_float_nbr_up_f(nb, v);
        my_putstr("E+");
    }
    if (nb < 10 && nb >= 1 && i == 0) {
        my_put_float_nbr_up_f(nb, v);
        my_putstr("E+");
    }
    i = my_put_expo_up_e_deux(nb, v, i);
    if (i < 10)
        my_put_nbr(0);
    my_put_nbr(i);
}

char flag_upper_e(va_list list_arg, int v)
{
    double nb = (double)va_arg(list_arg, double);

    if (error_case_up_f(nb) == 1)
        return 0;
    my_put_expo_up_e(nb, v);
}
