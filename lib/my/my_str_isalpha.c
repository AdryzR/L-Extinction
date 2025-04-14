/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** Returns 1 if the string only contains alphabetical
** character and 0 if the string contains another type
** of character
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] < 'a' && str[i] > 'z') || (str[i] < 'A' && str[i] > 'Z'))
            return 0;
    }
    return 1;
}
