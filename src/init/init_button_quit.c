/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_text_quit.c
*/

#include "proto.h"

int init_button_quit(button_t *button_quit)
{
    create_button(button_quit, "Quit", 870, 690);
    return 0;
}
