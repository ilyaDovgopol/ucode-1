// #include <stdbool.h>
// #include <stddef.h>

// bool mx_isspace(char c);
// void mx_strdel(char **str);
// char *mx_strnew(const int size);
// int mx_strlen(const char *);
// char *mx_strncpy(char *dst, const char *src, int len);

#include "libmx.h"
static bool my_isspace(char c);

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;
    // remember where to start and finish
    int start = 0;
    while (my_isspace(str[start]))
        start++;
    int end = mx_strlen(str) - 1;
    // empty string case
    if (end == -1)
       return mx_strnew(0);
    while (my_isspace(str[end]))
        end--;
    // count how much space we need
    // char *newstr = mx_strnew(end - start + 1);
    // if (newstr == NULL) return NULL;

    // // copy what we need
    // mx_strncpy(newstr, &str[start], end - start + 1);
    // return newstr;
    return mx_strndup(&str[start], end - start + 1);
}

static bool my_isspace(char c) {
    return c == '\t'
        || c == '\n'
        || c == '\v'
        || c == '\f'
        || c == '\r'
        || c == ' ';
}

