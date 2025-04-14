/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_generate_position
*/

#include "object/platform.h"
#include "macro.h"
#include <stdlib.h>
#include <math.h>


static float generate_offset(void)
{
    return (float)(rand() % 20) + 80.f;
}

static void normalize_vector(sfVector2f *vector)
{
    float magnitude = sqrtf(vector->x * vector->x + vector->y * vector->y);

    vector->x /= magnitude;
    vector->y /= magnitude;
}

sfVector2f platform_generate_position(const platform_t *previous)
{
    if (previous == NULL)
        return (sfVector2f){ 0.0f, (float)WINDOW_HEIGHT / 2 + 34.f };

    sfVector2f position = sfSprite_getPosition(previous->sprite);
    sfVector2f random_direction = {
        (float)(rand() % 990) + 10,
        (float)(rand() % 1000) - 500,  // allow less variation in y axis
    };

    normalize_vector(&random_direction);

    float offset = generate_offset();
    random_direction.x *= offset;
    random_direction.y *= offset / 1.25f;

    float previous_width = sfSprite_getGlobalBounds(previous->sprite).width;
    position.x += random_direction.x + previous_width;
    position.y += random_direction.y;

    // Clamp y so it doesn't go out of screen
    if (position.y - 40.f <= 0.f)
        position.y += 80.f;
    if (position.y + 13.f >= WINDOW_HEIGHT)
        position.y -= 80.f;

    return position;
}
