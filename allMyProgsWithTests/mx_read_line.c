#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    if (fd < 0) return -1;
    char *buf_str = mx_strnew(buf_size);
    char *cur_str = mx_strnew(0);
    char *tmp_str;
    int num_of_read_bytes = 0;
    int res;
    if ((res = read(fd, buf_str, buf_size)) > 0) {
        // for (int i = 0; i < buf_size; i++) {
        //     if (buf_str[i] == delim) {
        //         free(buf_str);
        //         return num_of_read_bytes;
        //     }
        //     *cur = buf_str[i];
        //     cur++;
        //     num_of_read_bytes++;
        // }
        int index;
        if ((index = mx_get_char_index(buf_str, delim)) != -1)
            buf_str[index] = '\0';
        else
            buf_str[res] = '\0';
        tmp_str = cur_str;
        cur_str = mx_strjoin(cur_str, buf_str);
        free(tmp_str);
        num_of_read_bytes += res;
        // at the end
        if (num_of_read_bytes < buf_size) break;
    }
    *lineptr = cur_str;
    free(buf_str);
    if (res < 0) return -1;
    return num_of_read_bytes;
}

