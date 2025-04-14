/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** Display one by one the characters of a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    for (int count = 0; str[count] != '\0'; count++) {
        my_putchar(str[count]);
    }
}
