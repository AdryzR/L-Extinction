/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** main.c
*/

#include "proto.h"

static void free_tab(script_t *script)
{
    for (int i = 0; script->tab[i] != NULL; i++)
        free(script->tab[i]);
    free(script->tab);
}

static int parsing(script_t *script, int ac, char **av)
{
    if (ac < 2 || ac > 2) {
        write(2, "Please execute ./wolf3d with a file.\nFor more"
        " information please execute ./my_radar -h\n", 88);
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        my_printf("\nAir traffic simulation panel\nUSAGE\n"
        "  ./my_radar [OPTION] path_to_script\n"
        "  path_to_script\tThe path to the script file.\nOPTIONS\n"
        "  -h\t\tprint the usage and quit.\nUSER INTERACTIONS\n"
        "  \'L\' key\t\tenable/disable hitboxes and areas.\n"
        "  \'S\' key\t\tenable/disable sprites.\n  \'J\'"
        " key\t\tenable/disable speed x3\n");
        return 1;
    }
    if (open_script(script, av[1]) == 84) {
        free(script->tab);
        return 84;
    }
    return 0;
}

static int my_radar(sfTexture **texture, script_t *script)
{
    entity_t *entity;
    game_t game;

    if (init_main(&game, &entity, texture, script) == 84) {
        free_tab(script);
        return 84;
    }
    free_tab(script);
    display_loop(&game, entity);
    // destroy_main(&game, entity, texture);
    return 0;
}

int main(int ac, char **av)
{
    script_t script;
    int rep;
    sfTexture *texture_background = sfTexture_createFromFile(BACKGROUND, NULL);
    sfTexture *texture_plane = sfTexture_createFromFile(PLANE, NULL);
    sfTexture *texture_tower = sfTexture_createFromFile(TOWER, NULL);
    sfTexture *texture[3] = {texture_background, texture_plane, texture_tower};

    if (!texture[0] || !texture[1] || !texture[2])
        return 84;
    rep = parsing(&script, ac, av);
    if (rep == 84)
        return 84;
    if (rep == 1)
        return 0;
    if (my_radar(texture, &script) == 84)
        return 84;
    return 0;
}
