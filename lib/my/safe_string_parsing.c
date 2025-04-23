/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** safe_string_parsing.c
*/

#include "my.h"

static size_t get_file_size(FILE *fd)
{
    long size = 0;

    fseek(fd, 0, SEEK_END);
    size = ftell(fd);
    rewind(fd);
    return (size_t)size;
}

char *safe_string_parsing(FILE *fd)
{
    size_t size = get_file_size(fd);
    char *buff = malloc(sizeof(char) * (size + 1));
    int br = 0;

    if (!buff || size == 0) {
        fclose(fd);
        return NULL;
    }
    br = fread(buff, 1, size, fd);
    if (br != size) {
        free(buff);
        fclose(fd);
        return NULL;
    }
    buff[br] = '\0';
    fclose(fd);
    return buff;
}
