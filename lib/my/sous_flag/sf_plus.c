/*
** EPITECH PROJECT, 2024
** B-CPE-101-STG-1-1-myprintf-kevser.akcan
** File description:
** sf_plus.c
*/

#include <stdarg.h>
#include "../my.h"
#include "../my_printf_h.h"
#include <stdio.h>

char sf_plus(const char *format, int i, va_list list_arg)
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
    for (; format[i] != '%'; i--) {
        if (format[i] == '+' && (r > 0 || s > 0.00)) {
            my_putchar('+');
            return 0;
        }
    }
    return 1;
}
