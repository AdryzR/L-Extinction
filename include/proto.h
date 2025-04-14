/*
** EPITECH PROJECT, 2024
** my
** File description:
** contain the prototype of all the function in libmy.a
*/

#include "circle.h"
#include "mylist.h"
#include "script.h"
#include "macro.h"
#include "enum.h"
#include "display.h"
#include "../lib/my/my.h"
#include <math.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
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
    #define PROTO_H_

int open_script(script_t *script, char *filepath);

sfSprite *init_sprite(sfTexture *texture);

entity_t *init_entity(game_t *game, sfTexture **texture, script_t *script);

void destroy_main(game_t *game, entity_t *entity, sfTexture **texture);

void destroy_window(game_t *game, sfTexture *texture_background);

void destroy_entity(entity_t *entity, sfTexture **texture);

int init_main(game_t *game, entity_t **entity, sfTexture **texture,
    script_t *script);

int init_background(game_t *game, sfTexture *texture);

int init_text_start(text_t *text_start);

int init_text_quit(text_t *text_quit);

int init_window(game_t *game);

int display_loop(game_t *game, entity_t *entity);

int display_main(game_t *game, entity_t *entity);

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

void del_funct_bis(plane_t *prev,
    plane_t **current, plane_t **begin);

void display_plane_bot_left(plane_t *prev_left, plane_t **cur_left,
    game_t *game, entity_t *entity);

void display_plane_bot_right(plane_t *prev_right, plane_t **cur_right,
    game_t *game, entity_t *entity);

void display_plane_top_left(plane_t *prev_left, plane_t **cur_left,
    game_t *game, entity_t *entity);

void display_plane_top_right(plane_t *prev_right, plane_t **cur_right,
    game_t *game, entity_t *entity);

float calculate_angle(sfVector2f *direction, plane_t *plane);

void rotation(entity_t *entity, plane_t *plane);

void display_plane_bis(game_t *game, plane_t *current, entity_t *entity);

player_t *init_player(game_t *game, player_t *player);

int init_map(game_t *game, script_t *script);

#endif /* PROTO_H_ */
