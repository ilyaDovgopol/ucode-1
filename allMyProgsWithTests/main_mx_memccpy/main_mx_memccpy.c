#include "../libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);

int main(void) {
    char *s = "Hello";
    void *d = NULL;
    mx_memccpy(d, s, '0', 4);
    printf("%s", d);
    free(d);
    system("leaks -q a.out");
    return 0;
}

