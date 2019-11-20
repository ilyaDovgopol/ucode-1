#include "header.h"

t_DIR *opendir(char *dirname);
t_Dirent *readdir(t_DIR *dfd);

void closedir(t_DIR *dfd);
void fsize(char *);

int main(int argc, char *argv[]) {
    if (argc == 1)
        fsize(".");
    else {
        argc--;
        while(argc > 0) {
            argv++;
            fsize(*argv);
        }
    }
    return 0;
}

void fsize(char *name) {
    struct stat stbuf;
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: cant't access%s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        
}

