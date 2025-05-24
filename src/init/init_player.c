/*
** EPITECH PROJECT, 2024
** bs_wolf3D
** File description:
** init_player.c
*/

#include "proto.h"

static player_t *find_player_coord(game_t *game, player_t *player, int i)
{
    for (int k = 0; game->map.map2D[i][k]; ++k) {
        if (game->map.map2D[i][k] == 'P') {
            player->x = k * TILE_SIZE;
            player->y = i * TILE_SIZE;
            player->camera_x = 0.0f;
            return player;
        }
    }
    return player;
}

/**
 * Crée un sfText, lui assigne police, position et échelle.
 */
static sfText *create_ui_text(sfFont *font, sfVector2f position,
    sfVector2f scale)
{
    sfText *txt = sfText_create();

    if (!txt)
        return NULL;
    sfText_setFont(txt, font);
    sfText_setPosition(txt, position);
    sfText_setScale(txt, scale);
    return txt;
}

/**
* Crée un sfSprite, lui assigne texture, position et échelle.
*/
static sfSprite *create_ui_sprite(sfTexture *tex, sfVector2f position,
    sfVector2f scale)
{
    sfSprite *spr = sfSprite_create();

    if (!spr)
        return NULL;
    sfSprite_setTexture(spr, tex, sfTrue);
    sfSprite_setPosition(spr, position);
    sfSprite_setScale(spr, scale);
    return spr;
}

static void init_player_ui(player_t *player)
{
    player->wp_status = W_GUN;
    player->font = sfFont_createFromFile(UI_FONT);
    player->reserve_texture = sfTexture_createFromFile(RESERVE_ASSET, NULL);
    player->reserve_sprite = create_ui_sprite(player->reserve_texture,
    (sfVector2f){WINDOW_WIDTH - 140.f, WINDOW_HEIGHT - 180.f},
    (sfVector2f){0.9f, 0.75f});
    player->reserve_txt = create_ui_text(player->font, (sfVector2f)
    {WINDOW_WIDTH - 60.f, WINDOW_HEIGHT - 170.f}, (sfVector2f){1.f, 1.f});
    player->hp_txt = create_ui_text(player->font, (sfVector2f){WINDOW_WIDTH
    - 60.f, WINDOW_HEIGHT - 80.f}, (sfVector2f){1.f, 1.f});
    player->hp_texture = sfTexture_createFromFile(HP_ASSET, NULL);
    player->ammo_txt = create_ui_text(player->font, (sfVector2f)
    {WINDOW_WIDTH - 60.f, WINDOW_HEIGHT - 130.f}, (sfVector2f){1.f, 1.f});
    player->ammo_texture = sfTexture_createFromFile(AMMO_ASSET, NULL);
    player->ammo_sprite = create_ui_sprite(player->ammo_texture, (sfVector2f)
    {WINDOW_WIDTH - 170.f, WINDOW_HEIGHT - 160.f}, (sfVector2f){2.f, 1.5f});
    player->hp_sprite = create_ui_sprite(player->hp_texture, (sfVector2f)
    {WINDOW_WIDTH - 170.f, WINDOW_HEIGHT - 115.f}, (sfVector2f){2.f, 1.8f});
}

int init_player(game_t *game, player_t *player)
{
    if (!player)
        return 84;
    player->x = -1;
    player->y = -1;
    player->camera_y = 100.0;
    print_tab(game->map.map2D);
    for (int i = 0; game->map.map2D[i]; ++i)
        player = find_player_coord(game, player, i);
    if (player->x == -1 && player->y == -1)
        return 84;
    player->gun_mag = GUN_MAG_SIZE;
    player->gun_reserve = DEFAULT_GUN_AMMO - GUN_MAG_SIZE;
    player->ak_mag = AK_MAG_SIZE;
    player->ak_reserve = DEFAULT_AK_AMMO - AK_MAG_SIZE;
    game->player->reloading = false;
    game->player->reload_end = 0.f;
    player->hp = DEFAULT_HP;
    init_player_ui(player);
    return (player->x == -1 && player->y == -1) ? 84 : 0;
}
