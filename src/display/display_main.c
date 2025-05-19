/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** display_main.c
*/

#include "proto.h"

bool get_action_time(sfClock *clock, const float every, float *last_action)
{
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    if (elapsed - *last_action >= every) {
        *last_action = elapsed;
        return 1;
    }
    return 0;
}

static void draw_map(game_t *game, int x, int y)
{
    sfRectangleShape* tile = sfRectangleShape_create();

    sfRectangleShape_setSize(tile, (sfVector2f){TILE_SIZE / 2, TILE_SIZE / 2});
    sfRectangleShape_setPosition(tile,
    (sfVector2f){x * TILE_SIZE / 2, y * TILE_SIZE / 2});
    if (game->map.map2D[y][x] == '#')
        sfRectangleShape_setFillColor(tile, sfColor_fromRGB(100, 100, 100));
    else
        sfRectangleShape_setFillColor(tile, sfBlue);
    sfRenderWindow_drawRectangleShape(game->windows.windows, tile, NULL);
    sfRectangleShape_destroy(tile);
}

static void display_map(game_t *game)
{
    for (int y = 0; game->map.map2D[y]; ++y) {
        for (int x = 0; game->map.map2D[y][x]; ++x)
            draw_map(game, x, y);
    }
}

static void draw_floor_and_ceiling(game_t *game, int column, float wall_height)
{
    float top = (WINDOW_HEIGHT / wall_height) + game->camera_y;
    float bottom = top + wall_height;
    sfVertexArray *vertex_sky = create_sky(top, column);
    sfVertexArray *vertex_floor = create_floor(column, bottom);

    sfRenderWindow_drawVertexArray(game->windows.windows, vertex_floor, NULL);
    sfRenderWindow_drawVertexArray(game->windows.windows, vertex_sky, NULL);
    sfVertexArray_destroy(vertex_sky);
    sfVertexArray_destroy(vertex_floor);
}

bool is_movement(key_struct_t *key)
{
    if (key->D == true || key->Down == true || key->Q == true ||
        key->S == true || key->Up == true || key->Z == true)
        return true;
    return false;
}

static void draw_wall(linked_list_t *temp, game_t *game, sfTexture **texture)
{
    int temp_data = 0;

    for (float x = 0.0; x < WINDOW_WIDTH && temp; ++x) {
        if (x != 0.0 && (int)x % 5 == 0)
            temp = temp->next;
        if (temp->object->id < 0) {
            draw_floor_and_ceiling(game, x, temp_data);
            continue;
        }
        temp_data = temp->object->data;
        render_wall_column(game, x, temp->object, set_wall_color(temp->
        object->offset_x, temp->object->offset_y, texture));
    }
}

static void display_shot(sfRenderWindow *window, gunshot_t *shot_struct,
    game_t *game)
{
    sfSprite_setTextureRect(shot_struct->shot, shot_struct->rect);
    sfRenderWindow_drawSprite(window, shot_struct->shot,
    NULL);
    if (get_action_time(game->clock, 0.05, &shot_struct->last) == false)
        return;
    shot_struct->rect.left += 682;
    if (shot_struct->rect.left >= 682 * 3) {
        shot_struct->gunshot = false;
        shot_struct->rect.left = 0;
    }
}

int display_main(game_t *game, sfTexture **texture)
{
    linked_list_t *temp = game->wall_height;

    sfRenderWindow_clear(game->windows.windows, sfBlack);
    draw_wall(temp, game, texture);
    display_map(game);
    draw_player(game);
    draw_ui(game);
    if (game->shot_struct.gunshot == true)
        display_shot(game->windows.windows, &game->shot_struct, game);
    sfRenderWindow_drawSprite(game->windows.windows,
    game->weapon.sprite, NULL);
    sfRenderWindow_display(game->windows.windows);
    return 0;
}
