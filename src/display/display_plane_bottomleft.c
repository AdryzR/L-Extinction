/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** display_plane_bottomleft.c
*/

#include "proto.h"

static void update_current_plane(plane_t **current_left, entity_t *entity,
    game_t *game)
{
    (*current_left)->safe = update_tower(current_left, entity);
    if (game->i == true) {
        update_plane(*current_left, game, &entity->plane_botlft, entity);
    }
    if ((*current_left)->status == FLY) {
        rotation(entity, *current_left);
        display_plane_bis(game, *current_left, entity);
    }
}

static void handle_plane_status_bis(plane_t **current_left, game_t *game,
    entity_t *entity, int k)
{
    if (k == 0 && (*current_left)->status == FLY && calcul_screen_loc
        ((*current_left)->object.position, sfRectangleShape_getPosition
        (game->bot_rht), sfRectangleShape_getSize(game->bot_rht))) {
        entity->plane_botrht = move_pln(*current_left, &entity->plane_botrht);
        (*current_left)->status = TODELETE;
    }
    if ((*current_left)->status == DEAD) {
        game->dead += 1;
    }
    if ((*current_left)->status == LAND) {
        game->land += 1;
    }
}

static void handle_plane_status(plane_t **current_left, game_t *game,
    entity_t *entity)
{
    int k = 0;

    if ((*current_left)->status == FLY && calcul_screen_loc((*current_left)
        ->object.position, sfRectangleShape_getPosition(game->top_lft),
        sfRectangleShape_getSize(game->top_lft))) {
        entity->plane_toplft = move_pln(*current_left, &entity->plane_toplft);
        (*current_left)->status = TODELETE;
        k = 1;
    }
    if (k == 0 && (*current_left)->status == FLY && calcul_screen_loc
        ((*current_left)->object.position, sfRectangleShape_getPosition
        (game->top_rht), sfRectangleShape_getSize(game->top_rht))) {
        entity->plane_toprht = move_pln(*current_left, &entity->plane_toprht);
        (*current_left)->status = TODELETE;
        k = 1;
    }
    handle_plane_status_bis(current_left, game, entity, k);
}

void display_plane_bot_left(plane_t *prev_left, plane_t **cur_left,
    game_t *game, entity_t *entity)
{
    int k = 0;

    while (*cur_left != NULL) {
        k = 0;
        update_current_plane(cur_left, entity, game);
        handle_plane_status(cur_left, game, entity);
        if ((*cur_left)->status == DEAD || (*cur_left)->status == LAND) {
            del_funct(prev_left, cur_left, &entity->plane_botlft);
            k = 1;
        }
        if (k == 0 && (*cur_left)->status == TODELETE) {
            del_funct_bis(prev_left, cur_left, &entity->plane_botlft);
            k = 1;
        }
        if (k == 0 && ((*cur_left)->status == FLY ||
            (*cur_left)->status == WAIT)) {
            prev_left = *cur_left;
            *cur_left = (*cur_left)->next;
        }
    }
}
