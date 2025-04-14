/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** Copies n characters from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int k = 0;
    int count = 0;

    for (count = 0; dest[count] != '\0'; count++);
    if (count > 0) {
        for (i = 0; i < n; i++) {
            dest[i] = src[i];
        }
        return (dest);
    } else {
        for (k = 0; k < n || src[k] == '\0'; k++) {
            dest[k] = src[k];
        }
        dest[k] = '\0';
        return (dest);
    }
}
