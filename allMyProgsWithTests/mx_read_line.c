#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, int delim, const int fd) {
    char *buf_str = mx_strnew(buf_size);
    int num_of_read_bytes = 0;
    while ((int res = read(fd, buf_str, buf_size)) >= buf_size) {
        int index = mx_get_char_index(buf_str, delim);
        

    }
    free(buf_str);
}

