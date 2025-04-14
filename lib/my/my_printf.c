/*
** EPITECH PROJECT, 2024
** Delivery (Espace de travail)
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf_h.h"
#include <stdio.h>

static int find_flag(const char *format)
{
    if (format[0] == '%' && format[1] != '\0') {
        return 1;
    }
    return 0;
}

char affiche_tkt(va_list list_arg, char flag, int v)
{
    char (*affiche[18])(va_list, int) = {
        &flag_integer, &flag_integer,
        &flag_s, &flag_upper_s, &flag_c,
        &flag_c, &flag_pourcent, &flag_u,
        &flag_o, &flag_x, &flag_upper_x,
        &flag_p, &flag_f, &flag_upper_f,
        &flag_e, &flag_upper_e, &flag_g,
        &flag_upper_g
    };
    char *flag_bis = "disScC%uoxXpfFeEgG";

    for (int k = 0; flag_bis[k]; k++) {
        if (flag_bis[k] == flag)
            return affiche[k](list_arg, v);
    }
}

int comparaison_flag(va_list list_arg, char flag, int i, const char *format)
{
    int v = 6;
    int b = 1;

    if (flag == format[i]) {
        if (format[i] == 'i' || format[i] == 'd')
            v = 0;
        if (format[i - 1] == '.')
            v = 0;
        if (my_char_isnum(format[i - 1]) == 1 && format[i - 2] == '.')
            v = format[i - 1] - 48;
        b = sf_plus(format, i, list_arg);
        if (b == 1)
            sf_space(format, i, list_arg);
        sf_hashtag(format, i, list_arg);
        affiche_tkt(list_arg, flag, v);
        return 0;
    }
    return 1;
}

int print_flag2(va_list list_arg, const char *format, int i)
{
    char *flag = "disScC%uoxXpfFeEgG";

    for (int j = 0; flag[j] != '\0'; j++) {
        if (comparaison_flag(list_arg, flag[j], i, format) == 0)
            return 0;
    }
    return 1;
}

int print_flag(va_list list_arg, const char *format, int i)
{
    i++;
    for (; format[i]; i++) {
        if (print_flag2(list_arg, format, i) == 0) {
            return 0;
        }
    }
}

static int find_under_flag(const char *format, int i)
{
    for (; format[i] == ' ' || format[i] == '#'
    || format[i] == '+' || format[i] == '0' || format[i] == '.'; i++)
    if (my_char_isnum(format[i + 1]) == 1)
        i++;
    return i;
}

int my_printf(const char *format, ...)
{
    va_list list_arg;
    int i = 0;

    va_start(list_arg, format);
    while (format[i] != '\0') {
        if (find_flag(&format[i])) {
            print_flag(list_arg, format, i);
            i++;
            i = find_under_flag(format, i);
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(list_arg);
    return 0;
}
