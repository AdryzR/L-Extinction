/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** Concatenates n characters of the src string to end of
** the dest string
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int k = 0;

    if (*src == '\0')
        return (dest);
    for (i; dest[i]; i++);
    for (k = 0; k < nb || src[k] == '\0'; k++) {
        dest[i + k] = src[k];
    }
    dest[i + k] = '\0';
    return (dest);
}
