/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** Find the first occurrence of a sub string in a string
*/

#include <stddef.h>
#include <stdbool.h>

bool my_strstr2(int i, int e, char *str, char const *to_find)
{
    int b = 0;

    for (i; str[i] == to_find[b]; i++) {
        b++;
        if ((str[i] == '\0' && e <= i) || (to_find[b] == '\0' && e >= i)) {
            return (true);
        }
    }
    return (false);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int e = 0;
    int r = 0;
    int count = 0;

    if (*to_find == '\0')
        return str;
    for (e; to_find[e]; e++);
    for (count; str[count]; count++);
    for (i; str[i]; i++) {
        r = i;
        if (my_strstr2(i, e, str, to_find)) {
            str[count] = '\0';
            return str + r;
        }
    }
    return (NULL);
}
