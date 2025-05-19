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
#include "display.h"
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

sfSprite *init_sprite(sfTexture *texture);

entity_t *init_entity(game_t *game, sfTexture **texture, script_t *script);

void destroy_main(game_t *game, sfTexture **texture);

void destroy_window(game_t *game);

void destroy_fx(game_t *game);

int init_main(game_t *game, sfTexture **texture);

int init_background(game_t *game, sfTexture *texture);

int init_text_start(button_t *button_start);

int init_text_quit(button_t *button_start);

int init_window(game_t *game);

int display_loop(game_t *game, sfTexture **texture);

int display_main(game_t *game, sfTexture **texture);

void display_window(game_t *game);

void update_plane(plane_t *plane, game_t *game, plane_t **origin,
    entity_t *entity);

void display_entity(game_t *game, entity_t *entity);

bool get_action_time(sfClock *clock, const float every, float *last_action);

void del_funct(plane_t *prev,
    plane_t **current, plane_t **begin);

int update_timer(game_t *game);

int display_text(game_t *game);

object_t init_object(sfTexture *texture, sfVector2f position);

int update_tower(plane_t **plane, entity_t *entity);

bool calcul_screen_loc(sfVector2f plane_position, sfVector2f screen_part,
    sfVector2f size);

plane_t *move_pln(plane_t *current, plane_t **head);

player_t *init_player(game_t *game, player_t *player);

int init_map(game_t *game, sfTexture *texture);

void destroy_button(button_t *button);

void update_menu(game_t *game, button_t *button_start, button_t *button_quit);

int init_button_quit(button_t *button_quit);

int init_button_start(button_t *button_start);

int init_menu(button_t *button_quit, button_t *button_start, game_t *game,
    sfTexture *texture_menu);

int display_menu_loop(game_t *game, button_t *, button_t *);

int int_pointer_len(int *pointer);

int is_wall(game_t *game, int x, int y);

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

sfVertexArray *create_floor(int column, float bottom);

sfVertexArray *create_sky(float top, int column);

void draw_player(game_t *game);

void draw_ui(game_t *game);

void update_ammo(game_t *game);

bool check_back_collision(game_t *game, int b);

bool check_front_collision(game_t *game, int b);

void open_settings(game_t *game);

int create_button(button_t *button, char *text, int x_pos, int y_pos);

key_struct_t init_key(void);

#endif /* PROTO_H_ */
