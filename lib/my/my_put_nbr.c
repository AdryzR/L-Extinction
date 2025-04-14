/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Display number given as a parameter
*/

#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    long n = nb;

    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    if (nb < 0 && nb >= -2147483648 && nb != 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (2147483647 >= nb && nb >= -2147483648 && nb != 0) {
        if (nb / 10 != 0) {
            my_put_nbr(nb / 10);
        }
        my_putchar(nb % 10 + 48);
    }
    if (nb == 0) {
        my_putchar(48);
    }
}
