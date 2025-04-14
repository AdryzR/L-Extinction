/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** update_bird.c
*/

#include "proto.h"

static void move(plane_t *plane, game_t *game)
{
    int norme = sqrt((plane->vector.x * plane->vector.x) +
    (plane->vector.y * plane->vector.y));
    sfVector2f direction = {(plane->vector.x) / norme,
    (plane->vector.y) / norme};

    plane->object.position.x = plane->object.position.x +
    (direction.x * (plane->speed * 0.05) * game->multiplicator);
    plane->object.position.y = plane->object.position.y +
    (direction.y * (plane->speed * 0.05) * game->multiplicator);
}

static void check_collide(plane_t *plane, plane_t **origin)
{
    for (plane_t *temp = *origin; temp != NULL; temp = temp->next) {
        if (temp->status == FLY && plane->id != temp->id && temp->safe == 0
            && plane->safe == 0 && (sfFloatRect_intersects(&plane->hit_box,
            &temp->hit_box, NULL) || sfFloatRect_intersects(&temp->hit_box,
            &plane->hit_box, NULL))) {
            plane->status = DEAD;
            temp->status = DEAD;
        }
    }
}

static bool check_if_land(plane_t *plane)
{
    return ((plane->object.position.x < plane->arival.x + 20 &&
    plane->object.position.x + 10 > plane->arival.x &&
    plane->object.position.y < plane->arival.y + 20 &&
    plane->object.position.y + 10 > plane->arival.y) ||
    (plane->object.position.x < plane->arival.x - 20 &&
    plane->object.position.x - 10 > plane->arival.x &&
    plane->object.position.y < plane->arival.y - 20 &&
    plane->object.position.y - 10 > plane->arival.y));
}

void update_plane(plane_t *plane, game_t *game, plane_t **origin,
    entity_t *entity)
{
    sfTime elapsed = sfClock_getElapsedTime(game->clock);

    if (elapsed.microseconds * 0.000001 >= plane->delay &&
        plane->status == WAIT) {
        sfSprite_setPosition(entity->sprite_plane, plane->object.position);
        plane->status = FLY;
    }
    if (plane->status == FLY) {
        move(plane, game);
        if (check_if_land(plane))
            plane->status = LAND;
        plane->hit_box.left = plane->object.position.x - 10;
        plane->hit_box.top = plane->object.position.y - 10;
        sfRectangleShape_setPosition(plane->hitbox_dis, (sfVector2f)
        {plane->object.position.x, plane->object.position.y});
        check_collide(plane, origin);
    }
}
