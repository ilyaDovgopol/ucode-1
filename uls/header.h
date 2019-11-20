#ifndef HEADER_H
#define HEADER_H

#define NAME_MAX 500
#define MAX_PATH 1024

typedef struct {
    long ino;
    char name[NAME_MAX + 1];
} Dirent;

typedef struct {
    int fd;
    Dirent d;
} DIR;



DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef DIRSIZ
#define DIRSIZ 14
#endif
struct direct {
    ino_t d_ino;
    char d_name[DIRSIZ];
};


#endif

