#include "libmx.h"

static size_t my_strnlen(const char *s, size_t n) {
    size_t len = mx_strlen(s);
    return len < n ? len : n;
}

char *mx_strndup(const char *s1, size_t n) {
    size_t len = my_strnlen(s1, n);
    char *s2 = mx_strnew(len + 1);

    if (s2 == NULL)
        return NULL;

    mx_strncpy(s2, s1, len);
    s2[len] = '\0';
    return s2;
}

