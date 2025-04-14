/*
** EPITECH PROJECT, 2024
** Delivery (Espace de travail)
** File description:
** flag_s.c
*/

#include <stdarg.h>
#include "../my.h"

char flag_s(va_list list_arg, int v)
{
    my_putstr(va_arg(list_arg, char *));
}
