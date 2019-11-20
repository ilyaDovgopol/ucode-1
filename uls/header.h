#ifndef HEADER_H
#define HEADER_H

#define NAME_MAX 500
#define MAX_PATH 1024

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
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef DIRSIZ
#define DIRSIZ 14
#endif
struct direct {
    ino_t d_ino;
    char *d_name[DIRSIZ];
};


#endif

