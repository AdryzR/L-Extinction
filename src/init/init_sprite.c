/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myhunter-esteban.munier
** File description:
** init_sprite.c
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

sfSprite *init_sprite(sfTexture *texture)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setOrigin(sprite, (sfVector2f){10, 10});
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
