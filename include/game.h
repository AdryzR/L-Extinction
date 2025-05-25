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

typedef enum weapon_s {
    W_GUN,
    W_KNIFE,
    W_AK
} weapon_t;

typedef struct {
    float x;
    float y;
    float angle;
    unsigned int hp;
    unsigned int gun_mag;
    unsigned int gun_reserve;
    unsigned int ak_mag;
    unsigned int ak_reserve;
    sfFont *font;
    sfText *ammo_txt;
    sfTexture *reserve_texture;
    sfSprite *reserve_sprite;
    sfText *reserve_txt;
    sfText *hp_txt;
    sfTexture *hp_texture;
    sfTexture *ammo_texture;
    sfSprite *hp_sprite;
    sfSprite *ammo_sprite;
    float camera_x;
    float camera_y;
    weapon_t wp_status;
    bool reloading;
    float reload_end;
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
    bool entity;
} ray_casting_t;

    #define TILE_SIZE 64
    #define MAP_WIDTH 8
    #define MAP_HEIGHT 8

typedef struct windows_s {
    sfRenderWindow *windows;
    int width;
    int height;
    object_t background;
} windows_t;

typedef struct npc_s {
    sfVector2f position;
    sfTexture *texture;
    double health;
    bool hit;
    struct npc_s *next;
} npc_t;

typedef struct button_s {
    sfFont *font;
    sfText *contain;
    sfFloatRect hitbox;
} button_t;

typedef struct {
    char **map2D;
    float height;
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
    bool f11;
} key_struct_t;

typedef struct {
    sfSprite *shot;
    bool gunshot;
    sfIntRect rect;
    float last;
    sfSound *shot_sound;
    sfSoundBuffer *shot_soundbuffer;
} gunshot_t;

typedef struct {
    int sprite_height;
    int sprite_screen_x;
    int draw_start_y;
    int draw_start_x;
    int draw_end_y;
    int draw_end_x;
    float tex_x;
    float ty;
    sfVertex quad[4];
    sfRenderStates states;
} sprite_t;

typedef struct particle_s {
    sfVector2f position;
    sfVector2f velocity;
    float lifetime;
    sfColor color;
    sfRectangleShape* shape;
    struct particle_s *next;
} particle_t;

typedef struct ammo_drop_s {
    sfVector2f position;
    sfTexture *texture;
    struct ammo_drop_s *next;
} ammo_drop_t;

typedef struct game_s {
    windows_t windows;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    int multiplicator;
    gunshot_t gun_shot;
    gunshot_t ak_shot;
    button_t button;
    linked_list_t *wall_height;
    sfTexture *fog;
    sfClock *clock;
    float lastchance;
    float hit_couldown;
    bool i;
    object_t ak_obj;
    particle_t *particle;
    object_t weapon;
    player_t *player;
    map_t map;
    npc_t *npc;
    sfTexture *zombie_texture;
    key_struct_t key;
    sfTexture **textures;
    sfSound *reload_sound;
    sfSoundBuffer *reload_buffers[RELOAD_SOUNDS_COUNT];
    sfSoundBuffer *knife_buffers[KNIFE_SOUNDS_COUNT];
    sfSound *knife_sound;
    int knife_sound_idx;
    float *buffer;
    bool fullscreen;
    ammo_drop_t *drops;
    sfTexture *drop_texture;
    sfMusic *music;
    sfSoundBuffer *menu_btn_buffer;
    sfSound *menu_btn_sound;
} game_t;

#endif /* GAME_H_ */
