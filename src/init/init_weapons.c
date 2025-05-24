/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** init_weapons
*/

#include <proto.h>

void init_weapons(game_t *game, sfTexture *ak_tex, sfTexture *weapon_tex)
{
    game->ak_obj = init_object(ak_tex,
        (sfVector2f){WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f});
    sfSprite_setOrigin(game->ak_obj.sprite,
        (sfVector2f){1020 / 2.f, 0.f});
    game->weapon = init_object(weapon_tex,
        (sfVector2f){WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f});
    sfSprite_setOrigin(game->weapon.sprite,
        (sfVector2f){1020 / 2.f, 0.f});
}
