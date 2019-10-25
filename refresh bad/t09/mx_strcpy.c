#include <stddef.h>

char *mx_strcpy(char *dst, const char *src) { 
    if (!src) 
        return NULL;
    
    char *d = dst;
    while ((*d++ = *src++) != '\0')
        ;
    return dst;
}

