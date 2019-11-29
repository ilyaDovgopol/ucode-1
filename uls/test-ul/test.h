#ifndef TEST_H
#define TEST_H

#include "uls.h"

void print_list_anonim_data(t_list *head);
void make_anonim_list_of(t_list **head, int size);
void print_list_int_data(t_list *head);
void make_int_list_of(t_list **head, int size);
void print_attr_arr(void **attr_array);
void print_attr_list(t_list *head);

#endif

