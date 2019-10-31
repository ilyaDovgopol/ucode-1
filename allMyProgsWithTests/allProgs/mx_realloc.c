#include "libmx.h"

static int my_min(int a, int b);

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL && size)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        ptr = NULL;
        return malloc(malloc_size(0));
    }
    
    int sz = my_min(size, malloc_size(ptr));
    void *p = malloc(size);
    if (p == NULL) return NULL;
 
    mx_memcpy(p, ptr, sz);
    free(ptr);
    ptr = NULL;
    return p;
}

static int my_min(int a, int b) {
    return a < b ? a : b;
}

