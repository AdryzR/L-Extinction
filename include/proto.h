/*
** EPITECH PROJECT, 2024
** my
** File description:
** contain the prototype of all the function in libmy.a
*/

#include "circle.h"
#include "script.h"
#include "macro.h"
#include "enum.h"
#include "game.h"
#include "../lib/my/my.h"
#include <math.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <stdbool.h>
#ifndef PROTO_H_
    #include "../lib/my/mylist.h"
    #define PROTO_H_

int open_script(script_t *script, char *filepath, game_t *game);

npc_t *free_npc(game_t *game);

sfSprite *init_sprite(sfTexture *texture);

void destroy_main(game_t *game, sfTexture **texture);

void destroy_window(game_t *game);

void destroy_fx(game_t *game);

void refresh_ammo_sprite(game_t *game);

bool is_mag_empty(game_t *game);

int init_main(game_t *game, sfTexture **texture);

void init_weapons(game_t *game, sfTexture *ak_tex, sfTexture *weapon_tex);

int init_background(game_t *game, sfTexture *texture);

int init_text_start(button_t *button_start);

int init_text_quit(button_t *button_start);

int init_music(game_t *game);

int init_other(game_t *game, sfTexture **texture);

int abort_fx(game_t *game);

int init_window(game_t *game);

void pickup_drops(game_t *game);

int display_loop(game_t *game, sfTexture **texture);

void display_main(game_t *game, sfTexture **texture);

void update_hp(game_t *game);

void display_window(game_t *game);

bool get_action_time(sfClock *clock, const float every, float *last_action);

int update_timer(game_t *game);

void draw_drop(game_t *game, ammo_drop_t *drop);

void update_gun(game_t *game);

void update_ak(game_t *game);

void update_weapons(game_t *game);

void reload_gun(game_t *game);

void reload_ak(game_t *game);

void add_ammo_drop(game_t *game, sfVector2f pos);

int display_text(game_t *game);

object_t init_object(sfTexture *texture, sfVector2f position);

bool calcul_screen_loc(sfVector2f plane_position, sfVector2f screen_part,
    sfVector2f size);

int init_player(game_t *game, player_t *player);

void set_gun_texture(game_t *game);

void set_ak_texture(game_t *game);

void set_knife_texture(game_t *game);

int init_map(game_t *game);

sprite_t init_sprite_npc(game_t *game, float tx, float ty);

void destroy_button(button_t *button);

void update_menu(game_t *game, button_t *button_start, button_t *button_quit);

int init_button_quit(button_t *button_quit);

int init_button_start(button_t *button_start);

int init_menu(button_t *button_quit, button_t *button_start, game_t *game,
    sfTexture *texture_menu);

int display_menu_loop(game_t *game, button_t *, button_t *);

int int_pointer_len(int *pointer);

int is_entity(game_t *game, int x, int y, char *c);

ray_casting_t *cast_single_ray(ray_casting_t *ray_struct, game_t **game);

void render_wall_column(game_t *game, int column,
    list_object_t *object, sfTexture *wall_texture);

void cast_all_rays(player_t *player, game_t **game);

int **free_matrix(int **matrix);

void destroy_window_menu(game_t *game, sfTexture *texture_background);

int wolf(game_t *game);

int menu(game_t *game);

sfTexture *set_wall_color(float offset_x, float offset_y, sfTexture **texture);

bool is_movement(key_struct_t *key);

sfVertexArray *create_floor(game_t *game, int column, float bottom);

sfVertexArray *create_sky(float top, int column);

void draw_player(game_t *game);

void draw_ui(game_t *game);

void update_ammo(game_t *game);

bool check_back_collision(game_t *game, sfVector2f position, int b);

bool check_front_collision(game_t *game, sfVector2f position, int b);

void open_settings(game_t *game);

int create_button(button_t *button, char *text, int x_pos, int y_pos);

key_struct_t init_key(void);

void manage_quad_floor(game_t *game, int column,
    list_object_t *object);

float deg_to_rad(float degrees);

float rad_to_deg(float radian);

void draw_fog(game_t *game, int column,
    list_object_t *object, sfTexture *fog_texture);

void manage_quad(game_t *game, int column,
    list_object_t *object, sfTexture *wall_texture);

object_t init_object_sprite(sfSprite *sprite, sfVector2f position);

npc_t *init_npc(game_t *game, npc_t *npc);

void draw_vertex(game_t *game, sfVertexArray *vertex_sky,
    sfVertexArray *vertex_floor);

void draw_sprite(game_t *game, npc_t *npc);

void destroy_map(game_t *game);

bool check_side_x_collision(game_t *game, sfVector2f position);

bool check_side_y_collision(game_t *game, sfVector2f position);

void destroy_texture(sfTexture **texture);

void draw_npc(game_t *game, npc_t *npc);

void check_npc_hit(game_t *game);

int check_death_npc(npc_t **begin, game_t *game);

sfVector2f move_npc(game_t *game, sfVector2f position);

void manage_npc(game_t *game);

int add_particle(particle_t **begin, sfColor color,
    sfVector2f position, int size);

void update_particles(float dt, particle_t **begin, game_t *game);

sfRenderWindow *createmywindow(game_t *game, unsigned int width,
    unsigned int height, sfUint32 style);

void manage_fullscreen(game_t *game, sfEvent event);

int create_button(button_t *button, char *text, int x_pos, int y_pos);

void settings_button(game_t *game, button_t *bsound);

void draw_ammo(game_t *game, ammo_drop_t *ammo);

particle_t *free_particle(game_t *game);

void draw_ammo_map(game_t *game, ammo_drop_t *ammo);

#endif /* PROTO_H_ */
