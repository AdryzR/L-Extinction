/*
** EPITECH PROJECT, 2024
** Delivery (Espace de travail)
** File description:
** flag_c.c
*/

#include <stdarg.h>
#include "../my.h"

char flag_c(va_list list_arg, int v)
{
    my_putchar(va_arg(list_arg, int));
}
