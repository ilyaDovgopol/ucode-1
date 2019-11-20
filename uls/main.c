#include "header.h"

t_DIR *opendir(char *dirname);
t_Dirent *readdir(t_DIR *dfd);

void closedir(t_DIR *dfd);
void fsize(char *);
void dirwalk(char *dir, void (*fcn)(char *));
t_DIR *opendir(char *dirname);
void closedir(t_DIR *dp);

//struct stat stbuf;

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
        dirwalk(name, fsize);
    printf("%8lld %s\n", stbuf.st_size, name);        
}

void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    t_Dirent *dp;
    t_DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0
            || strcmp(dp->name, "..") == 0)
                continue;
        
        if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s%s too long\n", dir, dp->name);
        else {
            sprintf(name, "%s%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}

t_DIR *opendir(char *dirname) {
    int fd;
    struct stat stbuf;
    t_DIR *dp;
    if ((fd = open(dirname, O_RDONLY, 0)) == -1)
        || fstat(fd, &stbuf) == -1
        || (stbuf.st_mode & S_IFMT) != S_IFDIR
        || (dp = (t_DIR *)malloc(sizeof(t_DIR))) == NULL)
            return;
    dp->fd = fd;
    return dp;
}

void closedir(t_DIR *dp) {
    if (dp) {
        close(dp->fd);
    }
}

t_Dirent *readdir(t_DIR *dp) {
    struct direct dirbuf;
    static t_Dirent d;
    while (read(df->fd, (char *) &dirbuf, sizeof(dirbuf)) 
        == sizeof(dirbuf)) {
            if (dirbuf.d_ino == 0)
                continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0';
        return &d;
    }
    return NULL;
}

