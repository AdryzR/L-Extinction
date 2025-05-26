/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** update_drop
*/

#include <proto.h>

static ammo_drop_t *update_drop_list(game_t *game, ammo_drop_t *cur,
    ammo_drop_t *prev)
{
    ammo_drop_t *next = cur->next;

    game->player->gun_reserve += DROP_AMMO_AMOUNT;
    game->player->ak_reserve += DROP_AMMO_AMOUNT;
    if (prev)
        prev->next = cur->next;
    else
        game->drops = cur->next;
    free(cur);
    return next;
}

void pickup_drops(game_t *game)
{
    sfVector2f p = { game->player->x, game->player->y };
    ammo_drop_t *prev = NULL;
    ammo_drop_t *cur = game->drops;
    float dx;
    float dy;

    while (cur) {
        dx = cur->position.x - p.x;
        dy = cur->position.y - p.y;
        if (dx * dx + dy * dy <= DROP_PICKUP_RADIUS * DROP_PICKUP_RADIUS) {
            cur = update_drop_list(game, cur, prev);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}
