/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_bird.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <time.h>
#include "proto.h"

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfBlue);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(circle, (sfVector2f){position.x + 4,
    position.y + 4});
    return circle;
}

static plane_t *add_plane_bis(plane_t *new_plane, script_t *script, int i)
{
    new_plane->object.position = (sfVector2f){my_getnbr(script->tab[i + 1]),
    my_getnbr(script->tab[i + 2])};
    new_plane->speed = my_getnbr(script->tab[i + 5]);
    new_plane->arival.x = my_getnbr(script->tab[i + 3]);
    new_plane->arival.y = my_getnbr(script->tab[i + 4]);
    new_plane->hitbox_dis = sfRectangleShape_create();
    sfRectangleShape_setSize(new_plane->hitbox_dis, (sfVector2f) {20, 20});
    sfRectangleShape_setPosition(new_plane->hitbox_dis, (sfVector2f)
    {new_plane->object.position.x, new_plane->object.position.y});
    sfRectangleShape_setFillColor(new_plane->hitbox_dis, sfTransparent);
    sfRectangleShape_setOutlineThickness(new_plane->hitbox_dis, 1);
    sfRectangleShape_setOrigin(new_plane->hitbox_dis, (sfVector2f){10, 10});
    new_plane->delay = my_getnbr(script->tab[i + 6]);
    sfRectangleShape_setOutlineColor(new_plane->hitbox_dis, sfGreen);
    new_plane->hit_box.left = new_plane->object.position.x - 10;
    new_plane->hit_box.top = new_plane->object.position.y - 10;
    return new_plane;
}

static plane_t *add_plan(plane_t *head, int i,
    script_t *script)
{
    plane_t *new_plane = malloc(sizeof(plane_t));

    if (!new_plane)
        return NULL;
    for (int k = i; k < i + 7; k++) {
        if (my_strcmp(script->tab[k], "\n") == 0 || script->tab[k] == NULL)
            return NULL;
    }
    new_plane = add_plane_bis(new_plane, script, i);
    new_plane->hit_box.height = 20;
    new_plane->hit_box.width = 20;
    new_plane->vector = (sfVector2f){new_plane->arival.x -
    new_plane->object.position.x, new_plane->arival.y -
    new_plane->object.position.y};
    new_plane->safe = 1;
    new_plane->status = WAIT;
    new_plane->id = i / 7;
    new_plane->next = head;
    return new_plane;
}

static tower_t *add_tower(tower_t *head, int i, script_t *script)
{
    tower_t *new_tower = malloc(sizeof(tower_t));

    if (!new_tower)
        return NULL;
    new_tower->object.position = (sfVector2f){my_getnbr(script->tab[i + 1]),
    my_getnbr(script->tab[i + 2])};
    new_tower->id = i / 4;
    new_tower->hitbox = create_circle(new_tower->object.position,
    5 * my_getnbr(script->tab[i + 3]));
    new_tower->next = head;
    return new_tower;
}

bool calcul_screen_loc(sfVector2f plane_position, sfVector2f screen_part,
    sfVector2f size)
{
    return (plane_position.x < screen_part.x + size.x &&
    plane_position.x + 10 > screen_part.x &&
    plane_position.y < screen_part.y + size.y &&
    plane_position.y + 10 > screen_part.y);
}

static int init_entity_tierce(game_t *game, entity_t **entity,
    script_t *script, int i)
{
    if (calcul_screen_loc((sfVector2f){my_getnbr(script->tab[i + 1]),
        my_getnbr(script->tab[i + 2])}, sfRectangleShape_getPosition(game->
        top_lft), sfRectangleShape_getSize(game->top_lft))) {
        (*entity)->plane_toplft = add_plan((*entity)->plane_toplft, i, script);
        return 1;
    }
    if (calcul_screen_loc((sfVector2f){my_getnbr(script->tab[i + 1]),
        my_getnbr(script->tab[i + 2])}, sfRectangleShape_getPosition(game->
        top_rht), sfRectangleShape_getSize(game->top_rht))) {
        (*entity)->plane_toprht = add_plan((*entity)->plane_toprht, i, script);
        return 1;
    }
    if (calcul_screen_loc((sfVector2f){my_getnbr(script->tab[i + 1]),
        my_getnbr(script->tab[i + 2])}, sfRectangleShape_getPosition(game->
        bot_rht), sfRectangleShape_getSize(game->bot_rht))) {
        (*entity)->plane_botrht = add_plan((*entity)->plane_botrht, i, script);
        return 1;
    }
    return 0;
}

static int init_entity_bis(game_t *game, entity_t **entity,
    script_t *script, int i)
{
    int k = 0;

    if (my_strcmp(script->tab[i], "A") == 0) {
        k = init_entity_tierce(game, entity, script, i);
        if (k == 0 && calcul_screen_loc((sfVector2f){my_getnbr(script->tab[i +
            1]), my_getnbr(script->tab[i + 2])}, sfRectangleShape_getPosition(
            game->bot_lft), sfRectangleShape_getSize(game->bot_lft))) {
            (*entity)->plane_botlft =
            add_plan((*entity)->plane_botlft, i, script);
        }
        return (i + 7);
    } else if (my_strcmp(script->tab[i], "T") == 0) {
        (*entity)->tower = add_tower((*entity)->tower, i, script);
        return (i + 4);
    } else {
        write(2, "The file not contain the good information or doesn't"
        " exist.\n", 60);
        return -1;
    }
    return 0;
}

entity_t *init_entity(game_t *game, sfTexture **texture, script_t *script)
{
    entity_t *entity = malloc(sizeof(entity_t));
    int i = 0;

    if (!entity)
        return NULL;
    entity->sprite_plane = init_sprite(texture[1]);
    entity->sprite_tower = init_sprite(texture[2]);
    entity->plane_toplft = NULL;
    entity->plane_toprht = NULL;
    entity->plane_botlft = NULL;
    entity->plane_botrht = NULL;
    entity->tower = NULL;
    while (script->tab[i] != NULL) {
        i = init_entity_bis(game, &entity, script, i);
        if (i == -1) {
            destroy_entity(entity, texture);
            return NULL;
        }
    }
    return entity;
}
