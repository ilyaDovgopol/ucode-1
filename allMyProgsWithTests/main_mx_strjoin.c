#include <stddef.h>
#include <stdio.h>

char *mx_strjoin(char const *s1, char const *s2);
void mx_printstr(char *);

int main(void) {
    char str1[] = "this";
    char str2[] = "dodge ";
    char *str3 = NULL;
    char *s;
    printf("%s\n", s = mx_strjoin(str2, str1)); //returns "dodge this"
    
    printf("%s\n", s = mx_strjoin(str3, str1)); //returns "this"
    printf("%d\n", s[6]);
    return 0;
}

