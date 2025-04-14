/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-esteban.munier
** File description:
** update_timer.c
*/

#include "proto.h"

static void inttostr(int N, char *str)
{
    int i = 0;
    int k = 0;
    char temp;

    while (N > 0) {
        str[i] = N % 10 + '0';
        N = N / 10;
        i++;
    }
    str[i] = '\0';
    k = i - 1;
    for (int j = 0; j < k; j++) {
        temp = str[j];
        str[j] = str[k];
        str[k] = temp;
        k--;
    }
}

static int get_intsize(int i)
{
    int count = 0;

    for (; i > 0; i = i / 10)
        count++;
    return count;
}

int update_timer(game_t *game)
{
    sfTime elapsed = sfClock_getElapsedTime(game->clock);
    int elapsed_seconde = elapsed.microseconds * 0.000001;
    char *time = malloc(sizeof(char) * get_intsize(elapsed_seconde) + 1);

    if (!time)
        return 84;
    inttostr(elapsed_seconde, time);
    sfText_setString(game->text.contain, time);
    game->time = elapsed_seconde;
    free(time);
    return 0;
}
