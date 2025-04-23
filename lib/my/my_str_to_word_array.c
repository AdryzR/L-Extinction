/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Split a string into word
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void free_my_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        if (array[i])
            free(array[i]);
    free(array);
}

bool is_delim(char c, char *delim)
{
    for (int i = 0; delim[i]; i++)
        if (delim[i] == c)
            return true;
    return false;
}

int size_of_word(char *word, char *delim)
{
    int length = 0;

    while (word[length] && !is_delim(word[length], delim))
        ++length;
    return length;
}

int number_of_words(char *str, char *delim)
{
    int nb_words = 0;

    for (bool is_word = false; *str; str++) {
        if (is_delim(*str, delim)) {
            is_word = false;
            continue;
        }
        if (!is_word) {
            is_word = true;
            nb_words++;
        }
    }
    return nb_words;
}

int set_words(char **words, char *str, char *delim)
{
    int word_len = 0;
    int pos_char = 0;

    for (int pos_words = 0; *str; ++pos_words) {
        for (; is_delim(*str, delim) && *str; ++str);
        if (!*str) {
            words[pos_words] = NULL;
            break;
        }
        word_len = size_of_word(str, delim);
        words[pos_words] = malloc(sizeof(char) * (word_len + 1));
        if (!words[pos_words])
            return 84;
        for (pos_char = 0; !is_delim(*str, delim) && *str; str++) {
            words[pos_words][pos_char] = *str;
            pos_char++;
        }
        words[pos_words][pos_char] = '\0';
    }
    return 0;
}

char **my_str_to_word_array(char *str, char *delim)
{
    char **words = NULL;
    int words_count = 0;
    int is_error = 0;

    if (!str || !delim)
        return NULL;
    words_count = number_of_words(str, delim);
    words = malloc(sizeof(char *) * (words_count + 1));
    if (!words)
        return NULL;
    for (size_t i = 0; i < words_count + 1; i++)
        words[i] = NULL;
    is_error = set_words(words, str, delim);
    if (is_error == 84) {
        free_my_array(words);
        return NULL;
    }
    return words;
}
