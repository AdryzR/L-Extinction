/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_main.c
*/

#include "proto.h"

key_struct_t init_key(void)
{
    key_struct_t key = {0};

    return key;
}

static int init_shot_struct(gunshot_t *gun_shot, sfTexture *shot,
    game_t *game)
{
    sfSprite_setTexture(gun_shot->shot, shot, sfTrue);
    sfSprite_setOrigin(gun_shot->shot, (sfVector2f){682 / 2, 682 / 2});
    sfSprite_setPosition(gun_shot->shot,
    (sfVector2f){WINDOW_WIDTH / 2 + 10, WINDOW_HEIGHT / 2 + 50});
    gun_shot->rect.top = 0;
    gun_shot->rect.left = 0;
    gun_shot->rect.height = 682;
    gun_shot->rect.width = 682;
    gun_shot->shot_sound = sfSound_create();
    if (!gun_shot->shot_sound) {
        sfSprite_destroy(gun_shot->shot);
        sfClock_destroy(game->clock);
        return 84;
    }
    gun_shot->shot_soundbuffer = sfSoundBuffer_createFromFile(SHOT_SOUND);
    sfSound_setBuffer(gun_shot->shot_sound, gun_shot->shot_soundbuffer);
    return 0;
}

static int abort_fx(game_t *game)
{
    destroy_fx(game);
    return 84;
}

static int create_shot(game_t *game, gunshot_t *shot_struct, sfTexture *tex)
{
    shot_struct->gunshot = false;
    shot_struct->shot = sfSprite_create();
    if (!shot_struct->shot)
        return 84;
    return init_shot_struct(shot_struct, tex, game);
}

static int init_fx(game_t *game, sfTexture *gun_shot_tex,
    sfTexture *ak_tex, sfTexture *weapon_tex)
{
    game->clock = sfClock_create();
    if (!game->clock)
        return abort_fx(game);
    game->lastchance = 0.0f;
    game->multiplicator = 1;
    game->key = init_key();
    game->ak_obj = init_object(ak_tex,
        (sfVector2f){WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f});
    sfSprite_setOrigin(game->ak_obj.sprite,
        (sfVector2f){1020 / 2.f, 0.f});
    game->weapon = init_object(weapon_tex,
        (sfVector2f){WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f});
    sfSprite_setOrigin(game->weapon.sprite,
        (sfVector2f){1020 / 2.f, 0.f});
    game->wall_height = NULL;
    if (create_shot(game, &game->gun_shot, gun_shot_tex) == 84)
        return abort_fx(game);
    if (create_shot(game, &game->ak_shot, gun_shot_tex) == 84)
        return abort_fx(game);
    return 0;
}

static int init_other(game_t *game, sfTexture **texture)
{
    game->player = malloc(sizeof(player_t));
    if (!game->player)
        return 84;
    if (init_player(game, game->player) == 84) {
        destroy_main(game, texture);
        return 84;
    }
    game->player->ak_ammo = DEFAULT_AK_AMMO;
    game->npc = init_npc(game, game->npc);
    return 0;
}

int init_main(game_t *game, sfTexture **texture)
{
    if (init_fx(game, texture[1], texture[4], texture[3]) == 84) {
        destroy_window(game);
        for (int i = 0; texture[i]; i++)
            sfTexture_destroy(texture[i]);
        free(texture);
        destroy_fx(game);
        return 84;
    }
    if (init_map(game, texture[0]) == 84) {
        destroy_main(game, texture);
        return 84;
    }
    return init_other(game, texture);
}
