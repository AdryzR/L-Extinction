/*
** EPITECH PROJECT, 2024
** B-CPE-101-STG-1-1-myprintf-kevser.akcan
** File description:
** flag_upper_F.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "../my.h"
#include "../my_printf_h.h"

int error_case_up_f(double nb)
{
    if (nb > 2147483647) {
        my_putstr("INF");
        return 1;
    }
    if (nb < -2147483647) {
        my_putstr("-INF");
        return 1;
    }
    if (nb >= -2147483648 && nb < 2147483648)
        return 0;
    else {
        my_putstr("-NAN");
        return 1;
    }
}

static void print_nb2(double nb, int v)
{
    my_put_nbr((int)nb);
    if (v > 0)
        my_putchar('.');
}

static int print_nb(double nb, int v)
{
    int l = 0;
    double n = nb;

    for (int i = 0; i < v; i++) {
        n = (n * 10) - (int)n *10;
        if (n >= 9)
            l++;
    }
    if (((n * 10) - (int)n *10) > 5)
        l++;
    if (l == (v + 1)) {
        my_put_nbr((int)nb + 1);
        if (v > 0)
            my_putchar('.');
        for (int i = 0; i < v; i++)
            my_put_nbr(0);
        return 1;
    }
    print_nb2(nb, v);
    return 0;
}

static void put_zero(int v, int i)
{
    if (v > i) {
        for (; v > i; i++)
            my_put_nbr(0);
    }
}

int my_put_float_nbr_up_f(double nb, int v)
{
    int i = 0;

    if (error_case_up_f(nb) == 1)
        return 0;
    if (nb < 0){
        nb = nb * (-1);
        my_putchar('-');
    }
    if (print_nb(nb, v) == 1)
        return 0;
    for (; v > i; i++) {
        nb = (nb * 10) - (int)nb *10;
        if (((i + 1) == v) && (((nb * 10) - (int)nb *10) > 5))
            my_put_nbr(nb + 1);
        else {
            my_put_nbr(nb);
        }
    }
    put_zero(v, i);
}

char flag_upper_f(va_list list_arg, int v)
{
    my_put_float_nbr_up_f((double)va_arg(list_arg, double), v);
}
