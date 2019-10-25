#include <stdio.h>

char *mx_strchr(const char *str, int c);
int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int l = mx_strlen(sub);

    while (*str) {
        char *p = mx_strstr(str, sub);
        if(p) {
            count++;
            str = p + l - 1;
        }
        str++;
    }
    return count;
}

