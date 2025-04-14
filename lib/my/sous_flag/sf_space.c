/*
** EPITECH PROJECT, 2024
** lib (Espace de travail)
** File description:
** sf_space.c
*/

#include <stdarg.h>
#include "../my.h"
#include "../my_printf_h.h"
#include <stdio.h>

int sf_space(const char *format, int i, va_list list_arg)
{
    int r = 0;
    double s = 0.00;
    va_list copy;

    va_copy(copy, list_arg);
    if (format[i] == 'f' || format[i] == 'F' ||
        format[i] == 'e' || format[i] == 'E' ||
        format[i] == 'g' || format[i] == 'G')
        s = va_arg(copy, double);
    if (format[i] == 'd' || format[i] == 'i')
        r = va_arg(copy, int);
    if (((format[i - 2] == ' ' && format[i - 1] == '.') ||
        (format[i - 1] == ' ') || (format[i - 3] == ' ' &&
        format[i - 2] == '.' && (my_char_isnum(format[i - 1]) == 1))) &&
        (format[i] == 'p' || r > 0 || s > 0.00))
        my_putchar(' ');
}
