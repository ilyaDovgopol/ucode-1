#include <stdio.h>

int mx_count_substr(const char *str, const char *sub);

int main(void) {
    char s[] = "yo yoyoyo yo Ne o";
    //char subs[] = "yo";
    char subs[] = " ";
    printf("%d", mx_count_substr(s, subs));

    return 0;
}
