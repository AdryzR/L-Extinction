/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** destroy_texture.c
*/

#include "proto.h"

void destroy_texture(sfTexture **texture)
{
    for (int i = 0; texture[i]; ++i)
        sfTexture_destroy(texture[i]);
    free(texture);
}
