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
    #define WALL_N "assets/wall_dark.png"
    #define WALL_S "assets/wall_light.png"
    #define SHOT "assets/fx/explosion_no_background.png"
    #define SHOT_SOUND "assets/fx/Gunshot Sound Effect Single Shot.mp3"
    #define WEAPON "assets/weapon.png"
    #define MENU "assets/background/menu.png"
    #define FONT "assets/fx/04B_03__.TTF"
    #define CURSOR "assets/fx/cursor.png"
    #define FLOOR "assets/Ground_try_pattern.png"
    #define CELLING "assets/Ground_try_pattern.png"
    #define FOG "assets/fog3.png"
    #define RANDOM_MIN 0
    #define RANDOM_MAX 8
    #define PLAYER_ROTATION_SPEED 1 * (M_PI / 180)
    #define PLAYER_MOVE_SPEED 2
    #define PLAYER_RADIUS 5
    #define PLAYER_COS cosf(fmodf(game->player->camera_x, 2 * M_PI))
    #define PLAYER_SIN sinf(fmodf(game->player->camera_x, 2 * M_PI))
    #define PLAYER_COS_MOVE PLAYER_MOVE_SPEED * PLAYER_COS
    #define PLAYER_SIN_MOVE PLAYER_MOVE_SPEED * PLAYER_SIN
    #define PLAYER_HEIGHT TILE_SIZE / 6 - 4
    #define GREY sfColor_fromRGB(100, 100, 100)
    #define LIGHT_GREY sfColor_fromRGB(170, 170, 170)
    #define LIGHT_BLUE sfColor_fromRGB(173, 216, 230)
    #define WALL_DISTANCE 500

#endif /* MACRO_H_ */
