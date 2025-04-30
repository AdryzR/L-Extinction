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
    #define WALL_N "assets/wall64.jpg"
    #define WALL_S "assets/wall.bmp"
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

#endif /* MACRO_H_ */
