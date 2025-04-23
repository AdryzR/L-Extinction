/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** safe_open.c
*/

#include "my.h"

FILE *safe_fopen(char *filepath, char *mode)
{
    FILE *fd = fopen(filepath, mode);

    if (!fd)
        return NULL;
    return fd;
}
