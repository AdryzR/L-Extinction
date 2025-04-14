/*
** EPITECH PROJECT, 2024
** Delivery (Espace de travail)
** File description:
** flag_o.c
*/

#include <stdarg.h>
#include "../my.h"
#include <unistd.h>

static int le_cas_de_merde(int a)
{
    long int merde = -2147483648;
    char *merde2 = "-2147483648";

    if (a == merde) {
        for (int i = 0; merde2[i] != '\0'; i++) {
            my_putchar(merde2[i]);
        }
        return 0;
    }
    return 1;
}

int my_put_octal_nbr(int a)
{
    if (le_cas_de_merde(a) == 0)
        return 0;
    if (a < 0){
        a = a * (-1);
        my_putchar('-');
    }
    le_cas_de_merde(a);
    if (a == 0) {
        my_putchar('0');
        return 0;
    }
    if (a > 9){
        my_put_octal_nbr(a / 8);
        my_putchar((a % 8) + 48);
        return 0;
    }
    if (a != 0)
        my_putchar(a + 48);
}

int my_octal_nbr(unsigned int nb)
{
    long n = nb;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 9) {
        my_put_octal_nbr(nb / 8);
        my_put_octal_nbr(nb % 8);
    } else {
        my_put_octal_nbr(nb);
    }
}

char flag_o(va_list list_arg, int v)
{
    my_octal_nbr((unsigned int)va_arg(list_arg, int));
}
