/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** Displays either N of the integer passed as parameter
** is negative or P if positive or null
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    my_putchar('\n');
}
