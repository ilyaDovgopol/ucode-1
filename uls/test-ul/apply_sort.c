#include "uls.h"

bool cmp(void *data1, void *data2, t_attr attr_file_size) {
    //printf("data1=%lu data2= %lu\n", (unsigned long)*(off_t *)(((void **)data1)[attr_file_size]), 
    //                               (unsigned long)*(off_t *)(((void **)data2)[attr_file_size]));
    ((void **)data1)[[attr_file_size]];
    return *((off_t *)(((void **)data1)[attr_file_size])) <  *((off_t *)(((void **)data2)[attr_file_size])) ? true : false;
}

bool cmp_size(void *data1, void *data2) {
    return cmp(data1, data2, attr_file_size);
}

void apply_sort(t_App *app) {
    int state = app->command[csort];
    switch (state) {
        case sort_nosort:
            break;
        case sort_size:
            mx_sort_list(app->cur_dir->list_attr, cmp_size);
            break;
        // case sort_ctime:
        //     break;
        // case sort_atime:
        //     break;
        // case sort_mtime:
        //     break;
    }
}
