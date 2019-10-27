//
// Created by Oleg Berdyshev on 2019-10-24.
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
// Utils
void mx_print_strarr(char **arr, const char *delim);
void mx_printstr(const char *s);
void mx_printchar(char c);
char *mx_itoa(int number);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quick_sort(char **arr, int left, int right);

// String part
char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);


#endif //LIBMX_H

