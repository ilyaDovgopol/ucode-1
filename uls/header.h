#define NAME_MAX 500

typedef struct {
    long ino;
    char name[NAME_MAX + 1];
} t_Dirent;

typedef struct {
    int fd;
    t_Dirent d;
} t_DIR;

t_DIR *opendir(char *dirname);
t_Dirent *readdir(t_DIR *dfd);
void closedir(t_DIR *dfd);

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



