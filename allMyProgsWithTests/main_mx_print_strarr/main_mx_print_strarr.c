#include "libmx.h"

int main(void) {
    char *arr[] = {"Hello", "World", ",", "Oleg", "!", NULL};
    char *delim = "__";
    mx_print_strarr(arr, delim);
    return 0;
}

