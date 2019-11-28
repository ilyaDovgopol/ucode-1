#ifndef ULS_H
#define ULS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <dirent.h>
#include <errno.h>

#include "libmx.h"

typedef enum e_attr {
    blocks,
    chmod,
    links,
    user,
    group,
    file_size,
    a_time,
    m_time,
    c_time,
    file_name,
    MAX_ATTR
} t_attr;

typedef void *t_attr_array[MAX_ATTR];

typedef struct {
    t_list *list_attr;
    t_list *raw_lines;
    DIR *current_DIR;
} t_CD;

typedef struct {

} t_Command;

typedef struct {
    int *flags;
    t_Command *command;
    t_CD *cur_dir; // будет с каждой новой дерикторией меняться здесь будут лики
} t_App;

void read_dir(t_App *app);

#endif

