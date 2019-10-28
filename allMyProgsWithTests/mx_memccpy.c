#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    size_t i = 0;
    unsigned char *s = (unsigned char *)src;
    unsigned char *d = (unsigned char *)dst;
    unsigned char chr = (unsigned char)c;
    while (i < n &&  s[i] != chr) {
        d[i] = s[i];
        i++;
    }
    return dst;
}

