/*
** EPITECH PROJECT, 2024
** Delivery (Espace de travail)
** File description:
** my_printf_h.h
*/

#include <stdarg.h>
#ifndef MY_PRINTF_H_H
    #define MY_PRINTF_H_H

char flag_integer(va_list list_arg, int v);
char flag_s(va_list list_arg, int v);
char flag_c(va_list list_arg, int v);
char flag_pourcent(va_list list_arg, int v);
char flag_u(va_list list_arg, int v);
char flag_o(va_list list_arg, int v);
char flag_x(va_list list_arg, int v);
char flag_upper_x(va_list list_arg, int v);
char flag_p(va_list list_arg, int v);
char flag_f(va_list list_arg, int v);
char flag_upper_f(va_list list_arg, int v);
int my_put_float_nbr_lil_f(double nb, int v);
int my_put_float_nbr_up_f(double nb, int v);
int error_case_lil_f(double nb);
int error_case_up_f(double nb);
char flag_e(va_list list_arg, int v);
char my_put_expo_lil_e(double nb, int v);
int my_put_expo_lil_e_deux(double nb, int v, int i);
char flag_upper_e(va_list list_arg, int v);
char my_put_expo_up_e(double nb, int v);
int my_put_expo_up_e_deux(double nb, int v, int i);
char flag_g(va_list list_arg, int v);
char flag_upper_g(va_list list_arg, int v);
char flag_upper_s(va_list list_arg, int v);
int sf_space(const char *format, int i, va_list list_arg);
char sf_plus(const char *format, int i, va_list list_arg);
char sf_hashtag(const char *format, int i, va_list list_arg);

#endif
