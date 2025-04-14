/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** Returns the square root (if it is a whole number)
** of the number given as argument
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    for (i; nb != i * i; i++) {
        if (i * i > nb) {
            return 0;
        }
    }
    return i;
}
