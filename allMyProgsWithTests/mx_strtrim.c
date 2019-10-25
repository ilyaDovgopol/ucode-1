#include <stdbool.h>
#include <stddef.h>

bool mx_isspace(char c);
void mx_strdel(char **str);
char *mx_strnew(const int size);
int mx_strlen(const char *);
char *mx_strncpy(char *dst, const char *src, int len);

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;
    // remember where to start and finnish
    int start = 0;
    while (mx_isspace(str[start]))
        start++;
    int end = mx_strlen(str) - 1;
    if (end == -1)
       return mx_strnew(0);
    while (mx_isspace(str[end]))
        end--;
    // count how much space we need
    char *newstr = mx_strnew(end - start + 1);
    // copy what we need
    if (newstr != NULL)
        mx_strncpy(newstr, &str[start], end - start + 1);
    return newstr;
}

