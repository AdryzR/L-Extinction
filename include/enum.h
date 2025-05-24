/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** enum.h
*/

#ifndef ENUM_H_
    #define ENUM_H_

typedef enum status_e {
    WAIT,
    FLY,
    DEAD,
    LAND,
    TODELETE,
}status_t;

typedef enum screenpart_e {
    LEFT,
    RIGHT,
}screenpart_t;

typedef enum texture_idx {
    TX_WALL_N,
    TX_WALL_S,
    TX_SHOT,
    TX_GUN,
    TX_FOG,
    TX_ZOMBIE,
    TX_AK,
    TX_KNIFE,
    TX_AMMO,
    TX_SIZE
}texture_idx_t;

#endif /* ENUM_H_ */
