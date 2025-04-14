/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** player
*/

#ifndef OBJECT_PLAYER_H
    #define OBJECT_PLAYER_H
    #include "game.h"
    #include <stdbool.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>


/**
 * @brief Player states
 */
typedef enum {
    PS_NORMAL,
    PS_JUMP,
    PS_SLIDE,
} player_state_t;


struct player_s {
    player_state_t state;
    sfSprite *sprite;
    float accel_y;  // since the player only moves up and down, only keep track of y
};


bool player_update(player_t *player, game_t *game);
void player_run(player_t *player, sfTexture **textures);
void player_jump(player_t *player, sfTexture **textures);
void player_slide(player_t *player, sfTexture **textures);
void player_display(game_t *game, player_t *player);

// Utils:
player_t *player_create(void);
void player_update_texture(player_t *player, sfTexture **textures);
void player_snap_to_platform(scene_ingame_t *data);


#endif
