/*
** EPITECH PROJECT, 2024
** mylist
** File description:
** liste linked header
*/

#ifndef MYLIST_H_
    #define MYLIST_H_

typedef struct list_object_s {
    int id;
    float data;
    float offset_x;
    float offset_y;
} list_object_t;

typedef struct linked_list_s {
    list_object_t *object;
    struct linked_list_s *next;
} linked_list_t;

#endif /* MYLIST_H_ */
