/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** load_menu.c
*/

#include "game.h"
#include "macro.h"
#include "object/player.h"
#include "sound.h"
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

void load_ingame(game_t *game)
{
    if (!game)
        return;

    change_music(game, MAIN_MUSIC);

    if (!game->scene)
        game->scene = malloc(sizeof(scene_t));

    game->scene->data = malloc(sizeof(scene_ingame_t));

    scene_ingame_t *data = game->scene->data;
    data->player_textures = malloc(3 * sizeof(sfTexture *));
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

    // Player Setup:
    data->player_textures[PS_NORMAL] = load_texture("assets/player/player.png");
    data->player_textures[PS_JUMP] = load_texture("assets/player/jump.png");
    data->player_textures[PS_SLIDE] = load_texture("assets/player/slide.png");

    data->player = player_create();
    player_update_texture(data->player, data->player_textures);

    // Platform Setup:
    data->platform_textures[0] = load_texture("assets/platforms/platform_red.png");
    sfTexture_setRepeated(data->platform_textures[0], sfTrue);

    data->platform_textures[1] = load_texture("assets/platforms/platform_green.jpg");
    sfTexture_setRepeated(data->platform_textures[1], sfTrue);

    platforms_init(data->platforms, data->platform_textures);
    data->last_platform = data->platforms[19];

    // Timer setup:
    data->time = 0;
    data->timer_font = sfFont_createFromFile("assets/fonts/FutureMillennium.ttf");
    data->timer_text = sfText_create();
    sfText_setFont(data->timer_text, data->timer_font);
    sfText_setCharacterSize(data->timer_text, 30);
    sfText_setFillColor(data->timer_text, sfBlack);
    sfText_setPosition(data->timer_text, (sfVector2f){5, 5});

    data->color = 0;
}
