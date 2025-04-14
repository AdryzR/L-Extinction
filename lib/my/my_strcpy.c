/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** Copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
