/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** scene.h
*/

#ifndef SCENE_H
    #define SCENE_H
    #include "types.h"
    #include "object/platform.h"
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>


/**
 * @brief Structure representing a scene.
 */
struct scene_s {
    scene_type_t type;
    game_fnc_t load;
    game_fnc_t event_manager;
    game_fnc_t update;
    game_fnc_t display;
    game_fnc_t free;
    void *data;
};

struct scene_ingame_s {
    // Player:
    player_t *player;
    sfTexture **player_textures;

    platform_t *platforms[20];
    platform_t *last_platform;
    sfTexture *platform_textures[2];

    // Background:
    sfSprite **background;
    sfTexture **background_texture;

    // Chrono:
    float time;
    sfText *timer_text;
    sfFont *timer_font;

    // color to render transparent
    unsigned int color;
};

struct scene_death_s {
    // Background:
    sfSprite **background;
    sfTexture **background_texture;
    sfFont *font;
    sfText *text_death;
    sfText *text_score;

    sfSprite *button;
    sfTexture *button_texture;
    sfText *text_button;
    sfRectangleShape *fade;

};
 
struct scene_menu_s {
    // Background:
    sfSprite *background;
    sfTexture *background_texture;
    // Button:
    sfSprite **button;
    sfTexture *button_texture;
    sfText **text;
    sfFont *font;
};

void load_ingame(game_t *game);
void update_ingame(game_t *game);
void event_ingame(game_t *game);
void display_ingame(game_t *game);
void free_ingame(game_t *game);

void load_death(game_t *game);
void update_death(game_t *game);
void event_death(game_t *game);
void display_death(game_t *game);
void free_death(game_t *game);

void load_menu(game_t *game);
void update_menu(game_t *game);
void event_menu(game_t *game);
void display_menu(game_t *game);
void free_menu(game_t *game);

/**
 * @brief Every scene enum and function pointer.
 */
static const scene_t scenes[] = {
    {ST_NONE, NULL, NULL, NULL, NULL, NULL, NULL},
    {ST_MAIN_MENU, load_menu, event_menu, update_menu, display_menu, free_menu, NULL},
    {ST_INGAME, load_ingame, event_ingame, update_ingame, display_ingame, free_ingame, NULL},
    {ST_DEATH, load_death, event_death, update_death, display_death, free_death, NULL}
};


void free_current_scene(game_t *game);
void change_scene(game_t *game, scene_type_t scene_type);



#endif
