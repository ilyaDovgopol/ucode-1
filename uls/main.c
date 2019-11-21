#include "header.h"

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);

void closedir(DIR *dfd);
void fsize(char *);
void dirwalk(char *dir, void (*fcn)(char *));
DIR *opendir(char *dirname);
void closedir(DIR *dp);

//struct stat stbuf;

int main(int argc, char *argv[]) {
    printf("Hello Viktor!\n");
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
    printf("in fsize with '%s'\n", name);
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
    Dirent *dp;
    DIR *dfd;
  
    printf("we are in dirwalk with '%s'\n", dir);
    if ((dfd = opendir(dir)) == NULL) {
	    printf("ew cant open dir");
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    printf("afrer open dir\n");
    while ((dp = readdir(dfd)) != NULL) {
	printf("we read dp\n");
        if (strcmp(dp->name, ".") == 0
         || strcmp(dp->name, "..") == 0) {
                printf("we found . or ..\n");
		continue;
	}
        
        if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name)) {
            printf("too long\n");
		fprintf(stderr, "dirwalk: name %s%s too long\n", dir, dp->name);
	}
	else {
            //sprintf(name, "%s%s", dir, dp->name);
            printf("name='%s'\n", name);
	    
	    printf("dir='%s' dir->name='%s'\n", dir, dp->name);
	    (*fcn)(name);
        }
    }
    closedir(dfd);
}

DIR *opendir(char *dirname) {
    int fd;
    struct stat stbuf;
    DIR *dp;
    printf("ew opendir '%s'\n", dirname);
    if ((fd = open(dirname, O_RDONLY, 0)) == -1
        || fstat(fd, &stbuf) == -1
        || (stbuf.st_mode & S_IFMT) != S_IFDIR
        || (dp = (DIR *)malloc(sizeof(DIR))) == NULL)
            return NULL;
    dp->fd = fd;
    return dp;
}

void closedir(DIR *dp) {
    if (dp) {
        close(dp->fd);
    }
}

Dirent *readdir(DIR *dp) {
    struct direct dirbuf;
    static Dirent d;
    printf("we readdir with fd=%d and name=\n", dp->fd);
    while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) 
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

