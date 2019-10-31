#include <unistd.h>
int mx_strlen(const char *c);

void mx_printstr(const char *s) {
    if (!s) {
        return;
    }
    write(1, s, mx_strlen(s));
}

