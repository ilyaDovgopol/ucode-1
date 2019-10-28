#include <stdio.h>
char *mx_replace_substr(const char *str, const char *sub, const char *replace);

int main(void) {
    printf("%s\n", mx_replace_substr("McDonalds", "alds", "uts"));
    printf("%s\n", mx_replace_substr("Ururu turu", "ru", "ta"));
    printf("%s\n", mx_replace_substr(" Ur ur u tu ru ", " ", "__"));
    return 0;
}

