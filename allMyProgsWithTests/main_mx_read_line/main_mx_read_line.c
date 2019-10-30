#include "../libmx.h"

int mx_read_line(char **lineptr, int buf_size, int delim, const int fd);

int main(void) {
    int fd;
    if ((fd = open("test.txt", O_RDONLY, 0))
        printf("Can't open\n");
    else {
        char *s;
        int res = mx_read_line(&s, 1024, ' ', fd);
        if (res < 1024) {
            printf("res < 1024\n");
        }
        
    }
    return 0;
}

