/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** main.c
*/

#include "proto.h"

static int parsing(char *filepath, game_t *game)
{
    FILE *fd = safe_fopen(filepath, "r");
    char *buff = NULL;

    if (!fd)
        return 84;
    buff = safe_string_parsing(fd);
    if (!buff)
        return 84;
    game->map.map2D = my_str_to_word_array(buff, "\n");
    free(buff);
    return 0;
}

int main(int ac, char **av)
{
    game_t game = {0};

    if (ac != 2)
        return 84;
    if (parsing(av[1], &game) == 84)
        return 84;
    if (wolf(&game) == 84)
        return 84;
    return 0;
}
