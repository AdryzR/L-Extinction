/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** check_npc_hit.c
*/

#include "proto.h"
#include <math.h>

static void init_ray(ray_casting_t *ray, player_t *pl, game_t *g, float x)
{
    ray->entity = false;
    ray->x = pl->x + 5;
    ray->y = pl->y + 5;
    ray->distance_to_wall = 0.0f;
    ray->angle = fmodf((fmodf(pl->camera_x, 2 * M_PI) - FOV / 2.0f)
        + (x / g->windows.width) * FOV, 2 * M_PI);
}

static void ray_step(ray_casting_t *ray)
{
    ray->distance_to_wall += 0.1f;
    ray->x += cosf(ray->angle) * 0.1f;
    ray->y += sinf(ray->angle) * 0.1f;
    ray->test_x = (int)(ray->x / TILE_SIZE);
    ray->test_y = (int)(ray->y / TILE_SIZE);
}

static void apply_shot_damage(ray_casting_t *r, game_t *g, npc_t *npc)
{
    unsigned int dmg = 0;

    for (int i = 0; i < 2; ++i)
        add_particle(&g->particle, sfRed,
            (sfVector2f){g->windows.width / 2.f,
            g->windows.height / 2.f + r->distance_to_wall},
            fabsf(r->distance_to_wall - 100.0f));
    npc->hit = true;
    dmg = (g->player->wp_status == W_AK) ? AK_DAMAGE : GUN_DAMAGE;
    npc->health = (npc->health > dmg) ? npc->health - dmg : 0;
}

static bool loop_on_npc(game_t *game, ray_casting_t *ray)
{
    bool hit;

    for (npc_t *npc = game->npc; npc; npc = npc->next) {
        hit = (ray->x > npc->position.x) &&
                (ray->x <= npc->position.x + 20) &&
                (ray->y > npc->position.y) &&
                (ray->y <= npc->position.y + 20);
        if (is_entity(game, ray->x, ray->y, "C") == 1)
            game->map.map2D[(int) ray->y / TILE_SIZE]
        [(int) ray->x / TILE_SIZE] = ' ';
        if (!npc->hit && hit) {
            apply_shot_damage(ray, game, npc);
            return true;
        }
    }
    return false;
}

static void check_shot_hits(game_t *game)
{
    ray_casting_t r = {0};

    if (is_mag_empty(game))
        return;
    init_ray(&r, game->player, game, game->windows.width / 2.f);
    while (r.distance_to_wall <= 200.0f) {
        ray_step(&r);
        if (loop_on_npc(game, &r))
            return;
    }
}

static void handle_knife_sound(game_t *g)
{
    sfSound_setBuffer(g->knife_sound, g->knife_buffers[g->knife_sound_idx]);
    sfSound_play(g->knife_sound);
    g->knife_sound_idx = (g->knife_sound_idx + 1) % KNIFE_SOUNDS_COUNT;
}

static void handle_knife(game_t *g)
{
    float px = g->player->x;
    float py = g->player->y;
    float dx;
    float dy;

    for (npc_t *z = g->npc; z; z = z->next) {
        dx = z->position.x - px;
        dy = z->position.y - py;
        if (dx * dx + dy * dy <= KNIFE_RANGE * KNIFE_RANGE) {
            z->hit = true;
            z->health = (z->health > KNIFE_DAMAGE)
                        ? z->health - KNIFE_DAMAGE : 0;
            add_particle(&g->particle, sfRed,
                (sfVector2f){g->windows.width / 2, g->windows.height / 2},
                KNIFE_RANGE);
            handle_knife_sound(g);
            return;
        }
    }
}

void check_npc_hit(game_t *game)
{
    if (game->player->wp_status == W_KNIFE)
        handle_knife(game);
    else
        check_shot_hits(game);
}
