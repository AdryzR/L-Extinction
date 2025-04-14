/*
** EPITECH PROJECT, 2024
** concat_params
** File description:
** concat argument in a string
*/

#include <stddef.h>
#include <stdlib.h>

static int count_function2(char **argv, int count)
{
    for (int i = 0; argv[i]; i++) {
        for (int l = 0; argv[i][l]; l++) {
            count++;
        }
    }
    return count;
}

char *concat_params(int argc, char **argv)
{
    char *str;
    int count = 0;
    int n = 0;

    count += count_function2(argv, count);
    str = malloc(sizeof(char) * (count + 1));
    if (str == NULL)
        return (str);
    for (int k = 0; k < argc; k++) {
        for (int j = 0; argv[k][j]; j++) {
            str[n] = argv[k][j];
            n++;
        }
        if (k + 1 < argc) {
            str[n] = '\n';
            n++;
        }
    }
    str[n] = '\0';
    return (str);
}
