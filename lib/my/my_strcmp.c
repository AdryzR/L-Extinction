/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Compare two string
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int k = my_strlen(s2);
    int i = my_strlen(s1);
    int e = 0;

    for (e; s1[e] == s2[e]; e++) {
        if (e == i && e == k)
            return (0);
    }
    for (e = 0; s1[e] != s1[i] && s2[e] != s2[k]; e++) {
        if (s1[e] < s2[e])
            return (-1);
        if (s1[e] > s2[e])
            return (1);
    }
    if (e < i)
        return (1);
    if (e < k)
        return (-1);
    return 0;
}
