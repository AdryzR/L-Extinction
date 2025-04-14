/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** code.h
*/

#ifndef CORE_H
    #define CORE_H
    #include <game.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>


int game_mainloop(void);
void update(game_t *game);
void display(game_t *game);
void free_game(game_t *game);
game_t *init_game(game_t *game);
void event_manager(game_t *game);
float get_time(game_t *game);


#endif
