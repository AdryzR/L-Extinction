/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** game.h
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Graphics/Color.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#ifndef GAME_H_
    #define GAME_H_

typedef struct object_s {
    sfSprite *sprite;
    sfVector2f position;
} object_t;

typedef struct {
    float x;
    float y;
    float angle;
} player_t;

    #define TILE_SIZE 64
    #define MAP_WIDTH 8
    #define MAP_HEIGHT 8


typedef struct windows_s {
    sfRenderWindow *windows;
    object_t background;
} windows_t;

typedef struct text_s {
    sfFont *font;
    sfText *contain;
} text_t;

typedef struct game_s {
    windows_t windows;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    object_t cursor;
    int multiplicator;
    int land;
    int dead;
    text_t text;
    int time;
    sfRectangleShape *bot_lft;
    sfRectangleShape *bot_rht;
    sfRectangleShape *top_lft;
    sfRectangleShape *top_rht;
    sfClock *clock;
    bool box_visible;
    bool sprite_visible;
    float lastchance;
    float lastchancebis;
    bool i;
    player_t *player;
    int map[MAP_HEIGHT][MAP_WIDTH];
} game_t;

#endif /* GAME_H_ */
