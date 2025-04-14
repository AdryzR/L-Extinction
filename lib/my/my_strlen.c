/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** Count and returns the number of characters of a string
*/

int my_strlen(char const *str)
{
    int count;

    for (count = 0; str[count] != '\0'; count++);
    return (count);
}
