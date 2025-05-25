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
    (sfVector2f){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
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
    sfSound_setVolume(gun_shot->shot_sound, 45.f);
    return 0;
}

int abort_fx(game_t *game)
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

static int init_knife_sounds(game_t *game)
{
    const char *knife_paths[KNIFE_SOUNDS_COUNT] = {
        KNIFE_SOUND_1,
        KNIFE_SOUND_2
    };

    for (int i = 0; i < KNIFE_SOUNDS_COUNT; i++) {
        game->knife_buffers[i] = sfSoundBuffer_createFromFile(knife_paths[i]);
        if (!game->knife_buffers[i])
            return 84;
    }
    game->knife_sound = sfSound_create();
    if (!game->knife_sound)
        return abort_fx(game);
    game->knife_sound_idx = 0;
    return init_music(game);
}

static int init_menu_buttons(game_t *game)
{
    game->menu_btn_buffer = sfSoundBuffer_createFromFile(BUTTON_SOUND);
    if (!game->menu_btn_buffer) {
        fprintf(stderr,
            "Warning: impossible de charger le son de bouton '%s'\n",
            BUTTON_SOUND);
    }
    game->menu_btn_sound = sfSound_create();
    if (game->menu_btn_sound && game->menu_btn_buffer) {
        sfSound_setBuffer(game->menu_btn_sound, game->menu_btn_buffer);
    } else if (game->menu_btn_sound && !game->menu_btn_buffer) {
        sfSound_destroy(game->menu_btn_sound);
        game->menu_btn_sound = NULL;
    }
    return 0;
}

int init_sound(game_t *game)
{
    const char *paths[RELOAD_SOUNDS_COUNT] = {
        RELOAD_SOUND_1,
        RELOAD_SOUND_2,
        RELOAD_SOUND_3
    };

    init_menu_buttons(game);
    srand((unsigned)time(NULL));
    for (int i = 0; i < RELOAD_SOUNDS_COUNT; i++) {
        game->reload_buffers[i] = sfSoundBuffer_createFromFile(paths[i]);
        if (!game->reload_buffers[i])
            return 84;
    }
    game->reload_sound = sfSound_create();
    if (game->reload_sound == NULL)
        return abort_fx(game);
    return init_knife_sounds(game);
}

static float *init_buffer(void)
{
    float *buffer = malloc(sizeof(float) * 3000);

    for (int i = 0; i < 3000; ++i)
        buffer[i] = 0.f;
    return buffer;
}

static int init_fx(game_t *game, sfTexture *gun_shot_tex,
    sfTexture *ak_tex, sfTexture *weapon_tex)
{
    game->clock = sfClock_create();
    if (!game->clock)
        return abort_fx(game);
    game->lastchance = 0.0f;
    game->multiplicator = 1;
    game->buffer = init_buffer();
    game->key = init_key();
    game->fullscreen = false;
    init_weapons(game, ak_tex, weapon_tex);
    game->wall_height = NULL;
    if (create_shot(game, &game->gun_shot, gun_shot_tex) == 84)
        return abort_fx(game);
    if (create_shot(game, &game->ak_shot, gun_shot_tex) == 84)
        return abort_fx(game);
    return init_sound(game);
}

int init_main(game_t *game, sfTexture **texture)
{
    if (init_fx(game, texture[TX_SHOT], texture[TX_FOG],
        texture[TX_GUN]) == 84) {
            destroy_window(game);
            destroy_texture(texture);
            destroy_fx(game);
            return 84;
    }
    if (init_map(game) == 84) {
        destroy_window(game);
        destroy_fx(game);
        destroy_map(game);
        destroy_texture(texture);
        return 84;
    }
    return init_other(game, texture);
}
