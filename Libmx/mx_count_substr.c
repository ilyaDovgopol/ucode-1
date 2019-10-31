#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (sub == NULL || str == NULL) return 0;
    int count = 0;
    int l = mx_strlen(sub);
    if (l == 0) return 0;

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

