/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** draw_ui
*/

#include "proto.h"
#include <stdlib.h>

/*
 * Affiche la réserve (toujours en blanc).
 */
static void render_reserve_ui(game_t *game, unsigned int rem)
{
    char buf[16];
    player_t *pl = game->player;

    snprintf(buf, sizeof(buf), "%u", rem);
    sfText_setString(pl->reserve_txt, buf);
    sfText_setColor(pl->reserve_txt, sfWhite);
    sfRenderWindow_drawSprite(game->windows.windows, pl->reserve_sprite, NULL);
    sfRenderWindow_drawText(game->windows.windows, pl->reserve_txt, NULL);
}

/*
 * Affiche le magazine avec :
 *  - rouge si 0
 *  - orange si ≤20%
 *  - blanc sinon
 */
static void render_magazine_ui(game_t *game, unsigned int mag, float pct)
{
    char buf[16];
    sfColor col;
    player_t *pl = game->player;

    snprintf(buf, sizeof(buf), "%u", mag);
    if (mag == 0)
        col = sfRed;
    else if (pct <= 20.0f)
        col = sfColor_fromRGB(255, 165, 0);
    else
        col = sfWhite;
    sfText_setString(pl->ammo_txt, buf);
    sfText_setColor(pl->ammo_txt, col);
    sfRenderWindow_drawText(game->windows.windows, pl->ammo_txt, NULL);
}

/*
 * Affiche l’UI des munitions : réserve, magazine puis icône.
 */
static void render_ammo_ui(game_t *game)
{
    player_t *pl = game->player;
    unsigned int mag;
    unsigned int rem;
    float pct;

    if (pl->wp_status == W_AK) {
        mag = pl->ak_mag;
        rem = pl->ak_reserve;
        pct = mag * 100.0f / AK_MAG_SIZE;
    } else {
        mag = pl->gun_mag;
        rem = pl->gun_reserve;
        pct = mag * 100.0f / GUN_MAG_SIZE;
    }
    render_reserve_ui(game, rem);
    render_magazine_ui(game, mag, pct);
    sfRenderWindow_drawSprite(game->windows.windows, pl->ammo_sprite, NULL);
}

/*
 * Affiche l’UI de la vie : texte + icône.
 */
static void render_hp_ui(game_t *game)
{
    player_t *pl = game->player;
    char buf[16];

    snprintf(buf, sizeof(buf), "%u", pl->hp);
    sfText_setString(pl->hp_txt, buf);
    sfText_setColor(pl->hp_txt, sfWhite);
    sfRenderWindow_drawText(game->windows.windows, pl->hp_txt, NULL);
    sfRenderWindow_drawSprite(game->windows.windows, pl->hp_sprite, NULL);
}

void draw_ui(game_t *game)
{
    if (game->player->wp_status != W_KNIFE)
        render_ammo_ui(game);
    render_hp_ui(game);
}
