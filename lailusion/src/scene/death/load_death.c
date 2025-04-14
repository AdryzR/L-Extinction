/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** load_menu.c
*/

#include "game.h"
#include "macro.h"
#include "object/player.h"
#include <string.h>


static void scale_image_to_window(sfSprite* sprite, sfRenderWindow* window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2u texture_size = sfTexture_getSize(sfSprite_getTexture(sprite));

    // Compute the scale needed to cover the window with the background:
    float scale_x = (float)window_size.x / (float)texture_size.x;
    float scale_y = (float)window_size.y / (float)texture_size.y;

    // Scale the sprite to cover the whole bg
    float scale = (scale_x > scale_y) ? scale_x : scale_y;
    sfSprite_setScale(sprite, (sfVector2f){scale, scale});
}

/**
 * @brief create a texture from a file, and
 * return it if no error was encountered.
 * Exit with an error message otherwise.
 */
static sfTexture *load_texture(const char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    if (texture == NULL) {
        fprintf(stderr, "Error: Failed loading texture at %s\n", path);
        exit(ERROR);
    }

    return texture;
}

static sfTexture *load_background_texture(int index)
{
    // Dynamically retrieve path to background texture:
    char file_path[] = "assets/background/layer_%.png";
    file_path[24] = '0' + (char)index;  // replace '%' with the index; the cast is safe since index € [0; 4]

    sfTexture *texture = load_texture(file_path);
    sfTexture_setRepeated(texture, sfTrue);

    return texture;
}

static void load_fade(scene_death_t *data)
{
    data->fade = sfRectangleShape_create();
    sfRectangleShape_setFillColor(data->fade, (sfColor){0, 0, 0, 130});
    sfRectangleShape_setSize(data->fade, (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT});
    sfRectangleShape_setPosition(data->fade, (sfVector2f){0, 0});
}

static void load_text(scene_death_t *data, float score)
{
    data->font = sfFont_createFromFile("assets/fonts/FutureMillennium.ttf");
    if (!data->font) {
        fprintf(stderr, "Error: Failed to load font\n");
        exit(ERROR);
    }
    data->text_death = sfText_create();
    sfText_setString(data->text_death, "You died");
    sfText_setFont(data->text_death, data->font);
    sfText_setCharacterSize(data->text_death, 80);
    sfText_setPosition(data->text_death, (sfVector2f){WINDOW_WIDTH / 2 - 190, WINDOW_HEIGHT / 2 - 150});
    data->text_score = sfText_create();

    char score_str[16];
    snprintf(score_str, sizeof(score_str), "Score : %d", (int)(score * 100));
    sfText_setString(data->text_score, score_str);
    sfText_setFont(data->text_score, data->font);
    sfText_setCharacterSize(data->text_score, 20);
    sfText_setPosition(data->text_score, (sfVector2f){WINDOW_WIDTH / 2 - 65, WINDOW_HEIGHT / 2});

    data->text_button = sfText_create();
    sfText_setString(data->text_button, "Restart");
    sfText_setFont(data->text_button, data->font);
    sfText_setCharacterSize(data->text_button, 40);
    sfText_setPosition(data->text_button, (sfVector2f){WINDOW_WIDTH / 2 - 90, WINDOW_HEIGHT / 2 + 50});
}

void load_button(scene_death_t *data)
{
    data->button_texture = load_texture("assets/button/button.png");
    data->button = sfSprite_create();
    sfSprite_setTexture(data->button, data->button_texture, sfTrue);
    sfSprite_setScale(data->button, (sfVector2f){1.5f, 1});
    sfSprite_setPosition(data->button, (sfVector2f){WINDOW_WIDTH / 2 - 110, WINDOW_HEIGHT / 2 + 40});
}


void load_death(game_t *game)
{
    if (!game)
        return;

    if (!game->scene)
        game->scene = malloc(sizeof(scene_t));

    game->scene->data = malloc(sizeof(scene_death_t));

    scene_death_t *data = game->scene->data;
    data->background = malloc(6 * sizeof(sfSprite *));
    data->background_texture = malloc(6 * sizeof(sfTexture *));

    // Background Setup:
    for (int i = 0; i < 5; i++) {
        data->background_texture[i] = load_background_texture(i);
        data->background[i] = sfSprite_create();
        sfSprite_setTexture(data->background[i], data->background_texture[i], sfTrue);
        scale_image_to_window(data->background[i], game->screen.window);
    }
    data->background[5] = NULL;
    data->background_texture[5] = NULL;

    load_fade(data);
    load_text(data, game->score);
    load_button(data);
}
