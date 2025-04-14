/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** display_entity.c
*/

#include "proto.h"

float calculate_angle(sfVector2f *direction, plane_t *plane)
{
    double AB[2] = {direction->x - (plane->object.position.x + 10),
    direction->y - (plane->object.position.y)};
    double AC[2] = {plane->arival.x - (plane->object.position.x + 10),
    plane->arival.y - (plane->object.position.y)};
    float rad = atan2(AC[1], AC[0]) - atan2(AB[1], AB[0]);

    return rad * (180 / 3.14);
}

void rotation(entity_t *entity, plane_t *plane)
{
    int norme = sqrt((plane->vector.x * plane->vector.x) +
    (plane->vector.y * plane->vector.y));
    sfVector2f direction = {(plane->vector.x) * norme,
    (plane->vector.y) / norme};
    float angle = calculate_angle(&direction, plane);

    if ((direction.x < 0 && direction.y < 0) ||
        (direction.y > 0 && direction.x < 0))
        angle += 180;
    sfSprite_setRotation(entity->sprite_plane, angle);
    sfRectangleShape_setRotation(plane->hitbox_dis, angle);
}

static void display_tower(game_t *game, entity_t *entity)
{
    for (tower_t *temp = entity->tower; temp != NULL; temp = temp->next) {
        if (game->sprite_visible == true) {
            sfSprite_setPosition(entity->sprite_tower, temp->object.position);
            sfRenderWindow_drawSprite(game->windows.windows,
            entity->sprite_tower, NULL);
        }
        if (game->box_visible == true)
            sfRenderWindow_drawCircleShape(game->windows.windows,
            temp->hitbox, NULL);
    }
}

void display_plane_bis(game_t *game, plane_t *current, entity_t *entity)
{
    if (game->sprite_visible == true) {
        sfSprite_setPosition(entity->sprite_plane,
        current->object.position);
        sfRenderWindow_drawSprite(game->windows.windows,
        entity->sprite_plane, NULL);
    }
    if (game->box_visible == true)
        sfRenderWindow_drawRectangleShape(game->windows.windows,
        current->hitbox_dis, NULL);
}

void display_entity(game_t *game, entity_t *entity)
{
    plane_t *prev_toplft = NULL;
    plane_t *prev_toprht = NULL;
    plane_t *prev_botlft = NULL;
    plane_t *prev_botrht = NULL;
    plane_t *current_toplft = entity->plane_toplft;
    plane_t *current_toprht = entity->plane_toprht;
    plane_t *current_botlft = entity->plane_botlft;
    plane_t *current_botrht = entity->plane_botrht;

    display_plane_top_left(prev_toplft, &current_toplft, game, entity);
    display_plane_top_right(prev_toprht, &current_toprht, game, entity);
    display_plane_bot_left(prev_botlft, &current_botlft, game, entity);
    display_plane_bot_right(prev_botrht, &current_botrht, game, entity);
    display_tower(game, entity);
}
