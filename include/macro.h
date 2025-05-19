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
    #define WALL_N "assets/Wall_try_dark.png"
    #define WALL_S "assets/Wall_try_light.png"
    #define SHOT "assets/fx/explosion_no_background.png"
    #define SHOT_SOUND "assets/fx/Gunshot Sound Effect Single Shot.mp3"
    #define WEAPON "assets/weapon.png"
    #define MENU "assets/background/menu.png"
    #define TOWER "assets/entity/tower.png"
    #define PLANE "assets/entity/plane.png"
    #define FONT "assets/fx/04B_03__.TTF"
    #define CURSOR "assets/fx/cursor.png"
    #define RANDOM_MIN 0
    #define RANDOM_MAX 8
    #define PLAYER_ROTATION_SPEED 1 * (M_PI / 180)
    #define PLAYER_MOVE_SPEED 1
    #define PLAYER_RADIUS 5
    #define PLAYER_COS cosf(fmodf(game->player->angle, 2 * M_PI))
    #define PLAYER_SIN sinf(fmodf(game->player->angle, 2 * M_PI))
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
    #define UI_FONT "assets/arial.ttf"
    #define DEFAULT_AMMO 100
    #define DEFAULT_HP 100

#endif
