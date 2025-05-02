/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_text_start.c
*/

#include "proto.h"

int init_button_start(button_t *button_start)
{
    create_button(button_start, "Start", 850, 390);
    return 0;
}
