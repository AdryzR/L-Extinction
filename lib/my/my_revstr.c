/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** Reverses a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int e = 0;
    int c = 0;
    char temp;

    for (e; str[e] != '\0'; e++);
    e--;
    while (i <= e) {
        temp = str[e];
        str[e] = str[i];
        str[i] = temp;
        i++;
        e--;
    }
    return str;
}
