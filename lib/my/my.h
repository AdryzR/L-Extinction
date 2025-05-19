/*
** EPITECH PROJECT, 2024
** my
** File description:
** contain the prototype of all the function in libmy.a
*/

#include "mylist.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef MY_H_
    #define MY_H_

char *concat_params(int argc, char **argv);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_isneg(int n);

int my_is_prime(int nb);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

char *my_revstr(char *str);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

int my_show_word_array(char *const *tab);

void my_sort_int_array(int *array, int size);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char const *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char const *to_find);

char **my_str_to_word_array(char *str, char *delim);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

int my_strncmp2(char const *s1, char const *s2, int n, int i);

bool my_strstr2(int i, int e, char *str, char const *to_find);

int count_spaces(char const *str, int k);

int count_char(char const *str, int *i, int k);

int function_bizzare(char const *str, int *k, int count);

int count_function(char const *str, int count);

int my_list_size(linked_list_t const *begin);

int my_char_isnum(char c);

int my_printf(const char *format, ...);

void my_rev_list(linked_list_t **begin);

char *my_strndup(char const *src, int n);

int my_str_isalphanum(char const *str);

char *uint_to_str(unsigned int value);

void *my_realloc(void *ptr, size_t size);

void *my_memcpy(void *dest, const void *src, size_t n);

FILE *safe_fopen(char *filepath, char *mode);

char *safe_string_parsing(FILE *fd);

int delete_in_list(linked_list_t **begin, int id);

int push_to_end_list(linked_list_t **begin, list_object_t *object);

linked_list_t *free_linklist(linked_list_t *link);

void free_tab(char **tab);

void print_tab(char **tab);

list_object_t *free_object(list_object_t *object);

int push_to_begin_list(linked_list_t **begin, list_object_t *object);

void delete_function(linked_list_t *prev,
    linked_list_t **current, linked_list_t **begin);

void pop_back(linked_list_t **begin);

void pop_front(linked_list_t **begin);

#endif /* MY_H_ */
