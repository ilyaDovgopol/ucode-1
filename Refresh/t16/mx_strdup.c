#include <stdlib.h>
int mx_strlen(char *str);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(char *src) {
    char *s = mx_strnew(mx_strlen(src));
    if (s != NULL)
        mx_strcpy(s, src);
    return s;
}

