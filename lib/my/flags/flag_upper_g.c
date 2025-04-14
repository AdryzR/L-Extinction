/*
** EPITECH PROJECT, 2024
** B-CPE-101-STG-1-1-myprintf-kevser.akcan
** File description:
** flag_upper_g.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "../my.h"
#include "../my_printf_h.h"

static char my_put_expo_in_g(double nb, int v)
{
    int i = 0;

    if ((int)nb == 0) {
        for (; (int)nb < 2147483647 &&
            (int)nb > -2147483648 &&
            (((int)nb % 10) != 0 || (int)nb == 0) &&
            ((int)nb < 1 && (int)nb >= 0); i++)
            nb = (nb * 10);
        return i;
    }
    for (; (int)nb < 2147483647 &&
        (int)nb > -2147483648 &&
        (((int)nb % 10) != 0); i++)
        nb = (nb * 10);
    i--;
    return i;
}

static char my_put_expo_in_g2(double nb, int v)
{
    int b = 0;
    int n = (int)nb;

    if (n == 0)
        nb = nb + 1;
    for (; n > 0; b++)
        n = (n / 10);
    return b;
}

static int case_of_else(int b, int i, int v, int j)
{
    for (; (b > i || b == v) && b != 0; b--) {
        v--;
        j++;
    }
    if (j == 0 && b == 0)
        v = i + 1;
    if (j == 0 && b > 0)
        v = i;
    return v;
}

static int calcul_of_v(int v, int i, int b, double nb)
{
    if (v == 1)
        return 0;
    if (nb < 1 && nb > 0 && i > v)
        return i - v;
    if (nb < 1 && nb > 0 && i < v)
        return v - i;
    if (nb < 1 && nb > 0 && i == v)
        return 0;
    if (b > i)
        v = b - i - 1;
    if (i > b)
        v = i - b - 1;
    if (i == b)
        v = 0;
    return v;
}

static char flag_e_or_f_upper(double nb, int v)
{
    double n = nb;
    int i = my_put_expo_in_g(nb, v);
    int b = my_put_expo_in_g2(nb, v);
    int j = 0;

    if (error_case_up_f(nb) == 1)
        return 0;
    if (v == 0)
        v = 1;
    if (i > 4 || (b - 1) >= v) {
        v = calcul_of_v(v, b, i, nb);
        my_put_expo_up_e(nb, v);
    } else {
        v = case_of_else(b, i, v, j);
        my_put_float_nbr_up_f(nb, v);
    }
}

char flag_upper_g(va_list list_arg, int v)
{
    flag_e_or_f_upper((double)va_arg(list_arg, double), v);
}
