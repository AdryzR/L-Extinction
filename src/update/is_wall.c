/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** is_wall.c
*/

#include "proto.h"

int is_wall(int x, int y)
{
    if (map[x][y] == 1)
        return 1;
    return 0;
}
