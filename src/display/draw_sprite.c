/*
** EPITECH PROJECT, 2024
** G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
** File description:
** draw_npc.c
*/

#include "proto.h"

sprite_t init_sprite_npc(game_t *game, float tx, float ty)
{
    sprite_t sprite = {0};
    float angle_offset = (game->player->camera_y - 90.0f);
    int vertical_offset = (int)(tanf(angle_offset * (M_PI / 180.0f)) * 10);

    sprite.ty = ty;
    sprite.sprite_screen_x = (int)((game->windows.width / 2) * (1 + tx / ty));
    sprite.sprite_height = abs((int)(TILE_SIZE *
    game->windows.height / ty) / 2);
    sprite.draw_start_y = -sprite.sprite_height + game->windows.height / ty
    + vertical_offset + 200;
    sprite.draw_end_y = sprite.sprite_height + game->windows.height / ty
    + vertical_offset + 200;
    sprite.draw_start_x = -sprite.sprite_height / 2 + sprite.sprite_screen_x;
    sprite.draw_end_x = sprite.sprite_height / 2 + sprite.sprite_screen_x;
    return sprite;
}

static sprite_t calcul_sprite(game_t *game, npc_t *npc)
{
    sprite_t sprite = {0};
    float dir_x = cosf(game->player->camera_x);
    float dir_y = sinf(game->player->camera_x);
    float plane_x = -dir_y * tanf(FOV / 2.0f);
    float plane_y = dir_x * tanf(FOV / 2.0f);
    float sprite_x = npc->position.x - game->player->x;
    float sprite_y = npc->position.y - game->player->y;
    float invDet = 1.0f / (plane_x * dir_y - dir_x * plane_y);
    float tx = invDet * (dir_y * sprite_x - dir_x * sprite_y);
    float ty = invDet * (-plane_y * sprite_x + plane_x * sprite_y);

    if (game->i == true && game->player->hp > 0 && ty > 0 && ty < 10)
        --game->player->hp;
    sprite = init_sprite_npc(game, tx, ty);
    if (ty <= 0.1f || sprite_x > WALL_DISTANCE) {
        sprite.sprite_height = -1;
        return sprite;
    }
    return sprite;
}

void render_sprite(game_t *game, npc_t *npc, sprite_t *spr)
{
    float tex_height = sfTexture_getSize(npc->texture).y;

    spr->quad[0].texCoords = (sfVector2f){spr->tex_x, 0};
    spr->quad[1].texCoords = (sfVector2f){spr->tex_x + 1, 0};
    spr->quad[2].texCoords = (sfVector2f){spr->tex_x + 1, tex_height};
    spr->quad[3].texCoords = (sfVector2f){spr->tex_x, tex_height};
    if (npc->hit == false) {
        for (int i = 0; i < 4; i++)
            spr->quad[i].color = sfWhite;
    } else {
        for (int i = 0; i < 4; i++)
            spr->quad[i].color = sfRed;
    }
    spr->states = (sfRenderStates) {.texture = npc->texture,
        .blendMode = sfBlendAlpha, .transform = sfTransform_Identity};
    sfRenderWindow_drawPrimitives(game->windows.windows, spr->quad, 4,
    sfQuads, &spr->states);
}

void draw_sprite(game_t *game, npc_t *npc)
{
    sprite_t spr = calcul_sprite(game, npc);

    if (spr.sprite_height < 0)
        return;
    for (int stripe = spr.draw_start_x; stripe < spr.draw_end_x; stripe++) {
        if (stripe < 0 || stripe >= game->windows.width ||
            spr.ty > game->buffer[stripe])
            continue;
        game->buffer[stripe] = spr.ty;
        spr.tex_x = ((stripe - (-spr.sprite_height / 2 + spr.sprite_screen_x))
        * sfTexture_getSize(npc->texture).x) / spr.sprite_height;
        spr.quad[0].position = (sfVector2f){stripe, spr.draw_start_y};
        spr.quad[1].position = (sfVector2f){stripe + 1, spr.draw_start_y};
        spr.quad[2].position = (sfVector2f){stripe + 1, spr.draw_end_y};
        spr.quad[3].position = (sfVector2f){stripe, spr.draw_end_y};
        render_sprite(game, npc, &spr);
    }
}
