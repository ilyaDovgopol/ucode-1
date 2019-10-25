#include <stdio.h>

char *mx_strcat(char *s1, const char *s2);

int main(void) {
    char s[20];
    s[0] = 'H';
    s[1] = 'e';
    s[2] = '\0';
    char ss[] = "llo";
    mx_strcat(s, ss);
    printf("%s\n", s);
    return 0;
}
