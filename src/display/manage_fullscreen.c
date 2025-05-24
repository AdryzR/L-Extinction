/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** manage_fullscreen.c
*/

#include "proto.h"

static void update_position(game_t *game)
{
    sfSprite_setPosition(game->gun_shot.shot, (sfVector2f)
    {game->windows.width / 2.f, game->windows.height / 2.f});
    game->weapon.position.x = game->windows.width / 2.f;
    game->weapon.position.y = game->windows.height / 2.f;
    sfSprite_setPosition(game->ak_shot.shot, (sfVector2f)
    {game->windows.width / 2.f, game->windows.height / 2.f});
    sfSprite_setPosition(game->weapon.sprite, game->weapon.position);
    sfSprite_setPosition(game->player->reserve_sprite, (sfVector2f)
    {game->windows.width - 140.f, game->windows.height - 180.f});
    sfText_setPosition(game->player->reserve_txt, (sfVector2f)
    {game->windows.width - 60.f, game->windows.height - 170.f});
    sfText_setPosition(game->player->hp_txt, (sfVector2f)
    {game->windows.width - 60.f, game->windows .height - 80.f});
    sfText_setPosition(game->player->ammo_txt, (sfVector2f)
    {game->windows.width - 60.f, game->windows.height - 130.f});
    sfSprite_setPosition(game->player->hp_sprite, (sfVector2f)
    {game->windows.width - 170.f, game->windows.height - 115.f});
    sfSprite_setPosition(game->player->ammo_sprite, (sfVector2f)
    {game->windows.width - 170.f, game->windows.height - 160.f});
}

void manage_fullscreen(game_t *game, sfEvent event)
{
    size_t count;
    const sfVideoMode *mode = sfVideoMode_getFullscreenModes(&count);

    if (event.key.code == sfKeyF11 && game->fullscreen == false) {
        sfRenderWindow_close(game->windows.windows);
        game->windows.windows = createmywindow(game, mode[0].width,
        mode[0].height, sfFullscreen);
        game->fullscreen = true;
        update_position(game);
        return;
    }
    if (event.key.code == sfKeyF11 && game->fullscreen == true) {
        sfRenderWindow_close(game->windows.windows);
        game->windows.windows = createmywindow(game,
        1920, 1080, sfClose | sfResize);
        game->fullscreen = false;
        update_position(game);
        return;
    }
}
