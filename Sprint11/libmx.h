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

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_pop_front(t_list **head);

#endif //LIBMX_H

