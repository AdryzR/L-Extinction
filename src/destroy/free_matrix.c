/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** free_matrix.c
*/

#include "proto.h"

int **free_matrix(int **matrix)
{
    if (!matrix)
        return NULL;
    for (int i = 0; matrix[i]; ++i)
        free(matrix[i]);
    free(matrix);
    return NULL;
}
