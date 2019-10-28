// #include <stdlib.h>
// #include <stddef.h>

// char *mx_strnew(const int size);
// int mx_strlen(const char *);
// char *mx_strcpy(char *dst, const char *src);
// char *mx_strcat(char *s1, const char *s2);
// char *mx_strdup(const char *str);

#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL || s2 == NULL) {
        if (s1 == NULL)
            return mx_strdup(s2);
        else
            return mx_strdup(s1);
    }
    char *p = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    if (p == NULL)
        return NULL;
    mx_strcpy(p, s1);
    mx_strcat(p, s2);
    return p;
}

