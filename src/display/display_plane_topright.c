/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** display_plane_topright.c
*/

#include "proto.h"

static void update_current_plane(plane_t **current_right, entity_t *entity,
    game_t *game)
{
    (*current_right)->safe = update_tower(current_right, entity);
    if (game->i == true) {
        update_plane(*current_right, game, &entity->plane_toprht, entity);
    }
}

static void handle_plane_status_bis(plane_t **current_right, game_t *game,
    entity_t *entity, int k)
{
    if (k == 0 && (*current_right)->status == FLY && calcul_screen_loc
        ((*current_right)->object.position, sfRectangleShape_getPosition
        (game->bot_lft), sfRectangleShape_getSize(game->bot_lft))) {
        entity->plane_botlft = move_pln(*current_right, &entity->plane_botlft);
        (*current_right)->status = TODELETE;
    }
    if ((*current_right)->status == FLY) {
        rotation(entity, *current_right);
        display_plane_bis(game, *current_right, entity);
    }
    if ((*current_right)->status == DEAD) {
        game->dead += 1;
    }
    if ((*current_right)->status == LAND) {
        game->land += 1;
    }
}

static void handle_plane_status(plane_t **current_right, game_t *game,
    entity_t *entity)
{
    int k = 0;

    if ((*current_right)->status == FLY && calcul_screen_loc((*current_right)
        ->object.position, sfRectangleShape_getPosition(game->top_lft),
        sfRectangleShape_getSize(game->top_lft))) {
        entity->plane_toplft = move_pln(*current_right, &entity->plane_toplft);
        (*current_right)->status = TODELETE;
        k = 1;
    }
    if (k == 0 && (*current_right)->status == FLY && calcul_screen_loc
        ((*current_right)->object.position, sfRectangleShape_getPosition
        (game->bot_rht), sfRectangleShape_getSize(game->bot_rht))) {
        entity->plane_botrht = move_pln(*current_right, &entity->plane_botrht);
        (*current_right)->status = TODELETE;
        k = 1;
    }
    handle_plane_status_bis(current_right, game, entity, k);
}

void display_plane_top_right(plane_t *prev_right, plane_t **cur_right,
    game_t *game, entity_t *entity)
{
    int k = 0;

    while (*cur_right != NULL) {
        k = 0;
        update_current_plane(cur_right, entity, game);
        handle_plane_status(cur_right, game, entity);
        if ((*cur_right)->status == DEAD || (*cur_right)->status == LAND) {
            del_funct(prev_right, cur_right, &entity->plane_toprht);
            k = 1;
        }
        if (k == 0 && (*cur_right)->status == TODELETE) {
            del_funct_bis(prev_right, cur_right, &entity->plane_toprht);
            k = 1;
        }
        if (k == 0 && ((*cur_right)->status == FLY ||
            (*cur_right)->status == WAIT)) {
            prev_right = *cur_right;
            *cur_right = (*cur_right)->next;
        }
    }
}
