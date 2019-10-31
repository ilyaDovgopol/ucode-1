#include <stdlib.h>
int mx_strlen(const char *str);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *src) {
    return mx_strcpy(mx_strnew(mx_strlen(src)), src);
}

