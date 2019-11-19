#define NAME_MAX 500;

typedef struct {
    long ino;
    char name[NAME_MAX + 1];
} t_Dirent;

typedef sruct {
    int fd;
    Dirent d;
} t_DIR;

t_DIR *opendir(char *dirname);
t_Dirent *readdir(t_DIR *dfd);


