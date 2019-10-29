#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    byte *src = (byte *)s;
    byte chr = (byte)c;
    for (int i = 0; i < n; i++) {
        if(src[i] == chr)
            return src + i;
    }
    return NULL;
}

