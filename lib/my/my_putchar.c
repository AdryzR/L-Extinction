/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** Display a character
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
