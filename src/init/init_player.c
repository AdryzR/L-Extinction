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

static void init_player_ui(player_t *player)
{
    player->wp_status = W_GUN;
    player->ammo_txt = sfText_create();
    player->hp_txt = sfText_create();
    player->font = sfFont_createFromFile(UI_FONT);
    player->hp_texture = sfTexture_createFromFile(HP_ASSET, NULL);
    player->ammo_texture = sfTexture_createFromFile(AMMO_ASSET, NULL);
    player->ammo_sprite = sfSprite_create();
    player->hp_sprite = sfSprite_create();
    sfSprite_setTexture(player->hp_sprite, player->hp_texture, false);
    sfSprite_setTexture(player->ammo_sprite, player->ammo_texture, false);
    sfText_setFont(player->ammo_txt, player->font);
    sfText_setFont(player->hp_txt, player->font);
    sfText_setPosition(player->ammo_txt, (sfVector2f){1860.0, 950.0});
    sfText_setPosition(player->hp_txt, (sfVector2f){1860.0, 1000.0});
    sfSprite_setPosition(player->ammo_sprite, (sfVector2f){1750.0, 920.0});
    sfSprite_setPosition(player->hp_sprite, (sfVector2f){1750.0, 965.0});
    sfSprite_setScale(player->hp_sprite, (sfVector2f){2.0, 1.8});
    sfSprite_setScale(player->ammo_sprite, (sfVector2f){2.0, 1.5});
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
    player->gun_ammo = DEFAULT_GUN_AMMO;
    player->hp = DEFAULT_HP;
    init_player_ui(player);
    return 0;
}
