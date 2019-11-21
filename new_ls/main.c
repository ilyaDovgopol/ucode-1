#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    char buf[512];
    mydir = opendir(argv[1]);
    while((myfile = readdir(mydir)) != NULL) {
         sprintf(buf, "%s/%s", argv[1], myfile->d_name);
         stat(buf, &mystat);
         printf("%zu", mystat.st_size);
         printf(" %s", myfile->d_name);
	 printf(" st_dev=%d\tst_ino=%d\tst_mode=%d\t", mystat.st_dev, mystat.st_ino, mystat.st_mode);
	 printf("st_nlink=%d\tst_uid=%d\n", mystat.st_nlink, mystat.st_uid);
    }
    closedir(mydir);
}

