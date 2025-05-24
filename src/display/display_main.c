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

    sfRectangleShape_setSize(tile, (sfVector2f){TILE_SIZE / 6 + 1,
    TILE_SIZE / 6 + 1});
    sfRectangleShape_setPosition(tile,
    (sfVector2f){x * TILE_SIZE / 6, y * TILE_SIZE / 6});
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
    float top = (game->windows.height / wall_height) + game->player->camera_y;
    float bottom = top + wall_height;
    sfVertexArray *vertex_sky = create_sky(top, column);
    sfVertexArray *vertex_floor = create_floor(game, column, bottom);

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

int draw_all(linked_list_t *temp, game_t *game, int temp_data, float x)
{
    if (temp->object->id == -1) {
            draw_floor_and_ceiling(game, x, temp_data);
            return 1;
    }
    if (temp->object->id == -2) {
        game->buffer[(int)x] = WALL_DISTANCE;
        temp->object->data = WALL_DISTANCE / 3.5 * (cosf(fmodf(
        game->player->camera_x, 2 * M_PI) - temp->object->angle));
        draw_fog(game, x, temp->object, game->fog);
        return 1;
    }
    return 0;
}

static void draw_wall(linked_list_t *temp, game_t *game, sfTexture **texture)
{
    int temp_data = 0;

    for (float x = 0.0; x < game->windows.width && temp; ++x) {
        if (x != 0.0 && (int)x % (game->windows.width / 800) == 0)
            temp = temp->next;
        if (!temp)
            break;
        game->buffer[(int)x] = temp->object->distance;
        if (draw_all(temp, game, temp_data, x) == 1)
            continue;
        temp_data = temp->object->data;
        render_wall_column(game, x, temp->object, set_wall_color(temp->
        object->offset_x, temp->object->offset_y, texture));
    }
}

static void display_shot(sfRenderWindow *window, gunshot_t *gun_shot,
    game_t *game)
{
    sfSprite_setTextureRect(gun_shot->shot, gun_shot->rect);
    sfRenderWindow_drawSprite(window, gun_shot->shot,
    NULL);
    if (get_action_time(game->clock, 0.05, &gun_shot->last) == false)
        return;
    gun_shot->rect.left += 682;
    if (gun_shot->rect.left >= 682 * 3) {
        gun_shot->gunshot = false;
        gun_shot->rect.left = 0;
    }
}

void render_weapon(game_t *game)
{
    if (game->player->wp_status == W_GUN && game->gun_shot.gunshot) {
        sfRenderWindow_drawSprite(game->windows.windows,
            game->gun_shot.shot, NULL);
        display_shot(game->windows.windows, &game->gun_shot, game);
    } else if (game->player->wp_status == W_AK && game->ak_shot.gunshot) {
        sfRenderWindow_drawSprite(game->windows.windows,
            game->ak_shot.shot, NULL);
        display_shot(game->windows.windows, &game->ak_shot, game);
    }
    sfRenderWindow_drawSprite(game->windows.windows,
        game->weapon.sprite, NULL);
}

void display_main(game_t *game, sfTexture **texture)
{
    linked_list_t *temp = game->wall_height;

    sfRenderWindow_clear(game->windows.windows, sfBlack);
    draw_wall(temp, game, texture);
    manage_npc(game);
    display_map(game);
    for (ammo_drop_t *d = game->drops; d; d = d->next) {
        draw_ammo_map(game, d);
        draw_ammo(game, d);
    }
    for (npc_t *temp = game->npc; temp; temp = temp->next)
        draw_npc(game, temp);
    draw_player(game);
    draw_ui(game);
    render_weapon(game);
    sfRenderWindow_display(game->windows.windows);
}
