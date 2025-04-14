/*
** EPITECH PROJECT, 2024
** B-CPE-101-STG-1-1-myprintf-kevser.akcan
** File description:
** my_char_isnum.c
*/

int my_char_isnum(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    return 0;
}
