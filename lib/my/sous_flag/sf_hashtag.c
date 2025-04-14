/*
** EPITECH PROJECT, 2024
** lib (Espace de travail)
** File description:
** sf_hashtag.c
*/

#include <stdarg.h>
#include "../my.h"
#include "../my_printf_h.h"
#include <stdio.h>

char sf_hashtag(const char *format, int i, va_list list_arg)
{
    int r = 0;
    va_list copy;

    va_copy(copy, list_arg);
    if (format[i] == 'o' || format[i] == 'x' || format[i] == 'X')
        r = va_arg(copy, int);
    for (; format[i] != '%'; i--) {
        if (format[i - 1] == '#' && format[i] == 'o' && r > 0) {
            my_putchar('0');
            return 0;
        }
        if (format[i - 1] == '#' && format[i] == 'x' && r > 0) {
            my_putstr("0x");
            return 0;
        }
        if (format[i - 1] == '#' && format[i] == 'X' && r > 0) {
            my_putstr("0X");
            return 0;
        }
    }
}
