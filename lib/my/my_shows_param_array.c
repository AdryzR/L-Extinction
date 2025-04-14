/*
** EPITECH PROJECT, 2024
** my_show_param_array
** File description:
** Display the ocntent of an array
*/

#include "my.h"
#include "struct.h"
#include <stddef.h>

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[i].str != NULL; i++) {
        my_putstr(par[i].str);
    }
}
