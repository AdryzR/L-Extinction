/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** Returns 1 if the number is prime and 0 if not
*/

int my_is_prime(int nb)
{
    long n = nb;

    if (n <= 1 || n > 2147483647) {
        return (0);
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return (0);
        }
    }
    return (1);
}
