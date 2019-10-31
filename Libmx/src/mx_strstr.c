#include "libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    char *s = (char *) s1;
    int l = mx_strlen(s2);
    while (*s) {
        if (!mx_strncmp(s, s2, l)) {
            return s;
        }
        s++;
    }
    return NULL;
}

