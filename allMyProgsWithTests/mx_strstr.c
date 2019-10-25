#include <stdio.h>

char *mx_strchr(const char *str, int c);
int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);

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
