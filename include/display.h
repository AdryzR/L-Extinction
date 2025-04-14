/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** display.h
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Graphics/Color.h>
#include "game.h"
#include <stdlib.h>
#ifndef DISPLAY_H_
    #define DISPLAY_H_

typedef struct tower_s {
    object_t object;
    sfCircleShape *hitbox;
    int id;
    int screen_part;
    struct tower_s *next;
} tower_t;

typedef struct plane_s {
    object_t object;
    float speed;
    float delay;
    sfVector2f arival;
    sfVector2f vector;
    sfFloatRect hit_box;
    int screen_part;
    sfRectangleShape *hitbox_dis;
    int id;
    int status;
    int safe;
    struct plane_s *next;
} plane_t;

typedef struct entity_s {
    plane_t *plane_toplft;
    plane_t *plane_toprht;
    plane_t *plane_botlft;
    plane_t *plane_botrht;
    tower_t *tower;
    sfSprite *sprite_plane;
    sfSprite *sprite_tower;
} entity_t;

#endif /* DISPLAY_H_ */
