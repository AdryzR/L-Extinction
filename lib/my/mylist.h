/*
** EPITECH PROJECT, 2024
** mylist
** File description:
** liste linked header
*/

#ifndef MYLIST_H_
    #define MYLIST_H_

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

#endif /* MYLIST_H_ */
