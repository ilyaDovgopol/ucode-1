//
// Created by Oleg on 2019-10-24.
//

#ifndef LIBMX_H
#define LIBMX_H
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_push_back(t_list **list, void *data);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

#endif //LIBMX_H

