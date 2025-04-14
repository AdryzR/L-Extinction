/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** Home made strncmp
*/

int my_strncmp2(char const *s1, char const *s2, int n, int i)
{
    int e = 0;
    int k = 0;

    for (k; s2[k]; k++);
    for (e; s1[e] != s1[i] || s2[e] != s2[k] && e < n; e++) {
        if (s1[e] < s2[e]) {
            return (-1);
        }
        if (s1[e] > s2[e]) {
            return (1);
        }
    }
    if (e < i)
        return (1);
    if (e < k)
        return (-1);
    return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int k = 0;
    int i = 0;

    for (i; s1[i] != '\0'; i++);
    for (k; s2[k] != '\0'; k++);
    for (int e = 0; s1[e] == s2[e] && e < n; e++) {
        if (s1[e] == s1[i] && s2[e] == s2[k]) {
            return (0);
        }
    }
    return (my_strncmp2(s1, s2, n, i));
}
