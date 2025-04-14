/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** sound.h
*/

#ifndef SOUND_H
    #define SOUND_H
    #include "core.h"

typedef enum {
    MENU,
    MAIN_MUSIC,
    START,
    JUMP,
    SLIDE,
    DEAD
} music_type_t;

void change_music(game_t *game, int index);


#endif
