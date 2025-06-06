/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** macro.h
*/

#ifndef MACRO_H_
    #define MACRO_H_
    #define WINDOW_HEIGHT 1080
    #define WINDOW_WIDTH 1920
    #define M_PI 3.14
    #define FOV 60 * (M_PI / 180)
    #define GAME_WINDOW game->windows.windows
    #define WALL_N "assets/wall_dark.png"
    #define WALL_S "assets/wall_light.png"
    #define SHOT "assets/fx/explosion_no_background.png"
    #define SHOT_SOUND "assets/fx/gunshot.mp3"
    #define WP_AK_TEXTURE "assets/rifle.png"
    #define WP_GUN_TEXTURE "assets/weapon.png"
    #define RESERVE_ASSET "assets/ui/reserve_box.png"
    #define DROP_ASSET "assets/mun.png"

    #define GAME_MUSIC "assets/fx/game_music.mp3"

    #define GUN_DAMAGE 10
    #define AK_DAMAGE 25

    #define DROP_CHANCE_PCT 50
    #define DROP_AMMO_AMOUNT 10
    #define DROP_PICKUP_RADIUS 20

    #define KNIFE_RANGE 50.0f
    #define KNIFE_DAMAGE 50
    #define KNIFE_SOUND_1 "assets/fx/knife1.mp3"
    #define KNIFE_SOUND_2 "assets/fx/knife2.mp3"
    #define KNIFE_SOUNDS_COUNT 2

    #define RELOAD_COOLDOWN 1.5f
    #define RELOAD_SOUND_1 "assets/fx/reload_goofy.mp3"
    #define RELOAD_SOUND_2 "assets/fx/reloading_english_man.mp3"
    #define RELOAD_SOUND_3 "assets/fx/reload.mp3"
    #define RELOAD_SOUNDS_COUNT 3

    #define BUTTON_SOUND "assets/fx/menu-button.mp3"
    #define WP_KNIFE_TEXTURE "assets/knife.png"
    #define MENU "assets/background/menu.png"
    #define FONT "assets/fx/04B_03__.TTF"
    #define CURSOR "assets/fx/cursor.png"
    #define FLOOR "assets/Ground_try_pattern.png"
    #define CELLING "assets/Ground_try_pattern.png"
    #define FOG "assets/fog3.png"
    #define ZOMBIE "assets/entity/Zombie_first.png"
    #define RANDOM_MIN 0
    #define RANDOM_MAX 8
    #define PLAYER_ROTATION_SPEED 1.5 * (M_PI / 180)
    #define PLAYER_MOVE_SPEED 2
    #define PLAYER_RADIUS 5
    #define PLAYER_COS cosf(fmodf(game->player->camera_x, 2 * M_PI))
    #define PLAYER_SIN sinf(fmodf(game->player->camera_x, 2 * M_PI))
    #define PLAYER_COS_MOVE PLAYER_MOVE_SPEED * PLAYER_COS
    #define PLAYER_SIN_MOVE PLAYER_MOVE_SPEED * PLAYER_SIN
    #define SKY_BLUE sfColor_fromRGB(135, 206, 235)
    #define GREEN_GRASS sfColor_fromRGB(34, 139, 34)
    #define HP_ASSET "assets/ui/heart_100.png"
    #define AMMO_ASSET "assets/ui/ammo_100.png"
    #define AMMO_75 "assets/ui/ammo_75.png"
    #define AMMO_50 "assets/ui/ammo_50.png"
    #define AMMO_25 "assets/ui/ammo_25.png"
    #define AMMO_0 "assets/ui/ammo_0.png"
    #define HP_75 "assets/ui/heart_75.png"
    #define HP_50 "assets/ui/heart_50.png"
    #define HP_25 "assets/ui/heart_25.png"
    #define HP_0 "assets/ui/heart_0.png"
    #define UI_FONT "assets/arial.ttf"

    #define DEFAULT_GUN_AMMO 50
    #define DEFAULT_AK_AMMO 100
    #define AK_MAG_SIZE 20
    #define GUN_MAG_SIZE 10
    #define DEFAULT_HP 100
    #define PLAYER_HEIGHT TILE_SIZE / 6 - 4

    #define GREY sfColor_fromRGB(100, 100, 100)
    #define LIGHT_GREY sfColor_fromRGB(170, 170, 170)
    #define LIGHT_BLUE sfColor_fromRGB(173, 216, 230)
    #define WALL_DISTANCE 500

#endif
