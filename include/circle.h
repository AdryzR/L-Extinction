/*
** EPITECH PROJECT, 2024
** bs_myradar
** File description:
** circle.h
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#ifndef CIRCLE_H_H
    #define CIRCLE_H_H

typedef struct circlelist_s {
    int id;
    int random;
    float lastchance;
    sfVector2f position;
    sfCircleShape *circle;
    int found;
    struct circlelist_s *next;
}circlelist_t;

#endif /* CIRCLE_H_H */
