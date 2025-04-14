/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** open_script.c
*/

#include "proto.h"

int open_script(script_t *script, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    char *buffer;

    if (!fd)
        return 84;
    stat(filepath, &sb);
    buffer = malloc(sizeof(char) * sb.st_size + 1);
    if (!buffer)
        return 84;
    read(fd, buffer, sb.st_size);
    buffer[sb.st_size] = '\0';
    script->tab = my_str_to_word_array(buffer, "\n");
    free(buffer);
    close(fd);
    return 0;
}
