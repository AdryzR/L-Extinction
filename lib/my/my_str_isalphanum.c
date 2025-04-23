/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-esteban.munier
** File description:
** my_str_isalphanum.c
*/

int my_str_isalphanum(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' &&
        str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) || str[i] == '_' ||
        str[i] == '.') {
        } else
            return 0;
    }
    return 1;
}
