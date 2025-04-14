/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_background.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include "proto.h"

int init_background(game_t *game, sfTexture *texture)
{
    game->windows.background = init_object(texture, (sfVector2f){0, 0});
    if (!game->windows.background.sprite)
        return 84;
    sfSprite_setTexture(game->windows.background.sprite, texture, sfTrue);
    return 0;
}
