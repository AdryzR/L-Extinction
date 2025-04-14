/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** destroy_function.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <stdbool.h>
#include "proto.h"

static void free_function_tower(tower_t *tower)
{
    tower_t *to_free;

    while (tower != NULL) {
        to_free = tower;
        sfCircleShape_destroy(tower->hitbox);
        tower = tower->next;
        free(to_free);
    }
}

static void free_function_plane(plane_t *plane)
{
    plane_t *to_free;

    while (plane != NULL) {
        to_free = plane;
        sfRectangleShape_destroy(plane->hitbox_dis);
        plane = plane->next;
        free(to_free);
    }
}

void destroy_window(game_t *game, sfTexture *texture_background)
{
    sfSprite_destroy(game->windows.background.sprite);
    sfTexture_destroy(texture_background);
    sfRenderWindow_destroy(game->windows.windows);
}

void destroy_entity(entity_t *entity, sfTexture **texture)
{
    sfTexture_destroy(texture[1]);
    sfTexture_destroy(texture[2]);
    sfSprite_destroy(entity->sprite_plane);
    sfSprite_destroy(entity->sprite_tower);
    if (entity != NULL) {
        free_function_plane(entity->plane_toplft);
        free_function_plane(entity->plane_toprht);
        free_function_plane(entity->plane_botlft);
        free_function_plane(entity->plane_botrht);
    }
    if (entity != NULL)
        free_function_tower(entity->tower);
    free(entity);
}

void destroy_fx(game_t *game)
{
    sfClock_destroy(game->clock);
    sfText_destroy(game->text.contain);
    sfFont_destroy(game->text.font);
}

void destroy_main(game_t *game, entity_t *entity, sfTexture **texture)
{
    destroy_window(game, texture[0]);
    destroy_entity(entity, texture);
    destroy_fx(game);
}
