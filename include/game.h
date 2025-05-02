/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** game.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#ifndef GAME_H_
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include "../lib/my/mylist.h"
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

typedef struct {
    float angle;
    float x;
    float y;
    float distance_to_wall;
    float offset_x;
    float offset_y;
    int test_x;
    int test_y;
    float wall_height;
} ray_casting_t;

    #define TILE_SIZE 64
    #define MAP_WIDTH 8
    #define MAP_HEIGHT 8

typedef struct windows_s {
    sfRenderWindow *windows;
    object_t background;
} windows_t;

typedef struct button_s {
    sfFont *font;
    sfText *contain;
    sfFloatRect hitbox;
} button_t;

typedef struct {
    char **map2D;
    int height;
} map_t;

typedef struct {
    bool Z;
    bool S;
    bool Q;
    bool D;
    bool Up;
    bool Down;
    bool shift;
    bool Echap;
} key_struct_t;

typedef struct {
    sfSprite *shot;
    bool gunshot;
    sfIntRect rect;
    float last;
    sfSound *shot_sound;
    sfSoundBuffer *shot_soundbuffer;
} gunshot_t;

typedef struct game_s {
    windows_t windows;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    int multiplicator;
    gunshot_t shot_struct;
    button_t button;
    linked_list_t *wall_height;
    sfSprite *wall;
    sfClock *clock;
    float lastchance;
    bool i;
    float camera_y;
    object_t weapon;
    player_t *player;
    map_t map;
    key_struct_t key;
} game_t;

#endif /* GAME_H_ */
