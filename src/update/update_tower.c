/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** update_tower.c
*/

#include "proto.h"

static bool safe_plane(sfCircleShape *circle, sfVector2f *pos)
{
    sfVector2f circlepos = sfCircleShape_getPosition(circle);
    float radius = sfCircleShape_getRadius(circle);

    return (((circlepos.x - pos->x) * (circlepos.x - pos->x) +
    (circlepos.y - pos->y) * (circlepos.y - pos->y)) <= (radius * radius) &&
    ((circlepos.x - pos->x + 20) * (circlepos.x - pos->x + 20) +
    (circlepos.y - pos->y) * (circlepos.y - pos->y)) <= (radius * radius) &&
    ((circlepos.x - pos->x + 20) * (circlepos.x - pos->x + 20) +
    (circlepos.y - pos->y + 20) * (circlepos.y - pos->y + 20))
    <= (radius * radius) && ((circlepos.x - pos->x) *
    (circlepos.x - pos->x) + (circlepos.y - pos->y + 20) *
    (circlepos.y - pos->y + 20)));
}

static bool tower_safety(tower_t *tower, plane_t **plane)
{
    return (safe_plane(tower->hitbox, &(*plane)->object.position) == true ||
    safe_plane(tower->hitbox, &(sfVector2f) {(*plane)->object.position.x + 20,
    (*plane)->object.position.y + 20})
    == true || safe_plane(tower->hitbox, &(sfVector2f)
    {(*plane)->object.position.x, (*plane)->object.position.y + 20})
    == true || safe_plane(tower->hitbox, &(sfVector2f)
    {(*plane)->object.position.x + 20, (*plane)->object.position.y})
    == true);
}

int update_tower(plane_t **plane, entity_t *entity)
{
    int rep = 0;

    for (tower_t *temp = entity->tower; temp != NULL; temp = temp->next) {
        if (rep == 0 && tower_safety(temp, plane))
            rep = 1;
        if (rep == 0 && tower_safety(temp, plane) == false)
            rep = 0;
    }
    if (rep == 1 && (*plane)->safe == 0)
        sfRectangleShape_setOutlineColor((*plane)->hitbox_dis, sfGreen);
    if (rep == 0 && (*plane)->safe == 1)
        sfRectangleShape_setOutlineColor((*plane)->hitbox_dis, sfRed);
    return rep;
}
