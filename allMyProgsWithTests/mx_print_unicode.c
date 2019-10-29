#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char arr[4];
    if (c < 0x80) {
        arr[0] = (c>>0 & 0x7F) | 0x00;
        arr[1] = 0;
        arr[2] = 0;
        arr[3] = 0;
    }
    else if (c < 0x800) {
        arr[0] = (c>>6 & 0x1F) | 0xC0;
        arr[1] = (c>>0 & 0x3F) | 0x80;
        arr[2] = 0;
        arr[3] = 0;
    }
    else if (c < 0x010000) {
        arr[0] = (c>>12 & 0x7F) | 0xE0;
        arr[1] = (c>>6 & 0x3F) | 0x80;
        arr[2] = (c>>0 & 0x3F) | 0x80;
        arr[3] = 0;
    }
    else if (c < 0x110000) {
        arr[0] = (c>>18 & 0x7F) | 0xF0;
        arr[1] = (c>>12 & 0x3F) | 0x80;
        arr[2] = (c>>6 & 0x3F) | 0x80;
        arr[3] = (c>>0 & 0x3F) | 0x80;
    }
    write(1, arr, 4);
}

