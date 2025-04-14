/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** Return a number sent to the function as a string
*/

int my_getnbr(char const *str)
{
    int i;
    long r = 0;
    int l = 1;
    int k = 1;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-') {
            l *= -1;
        }
    }
    for (i; str[i] >= '0' && str[i] <= '9'; i++) {
        r = r * 10 + (str[i] - '0');
    }
    if (r * l > 2147483647 || r * l < -2147483648 ||
        (str[i - 1] < '0' && str[i - 1] > '9')) {
        return 0;
    }
    return r * l;
}
