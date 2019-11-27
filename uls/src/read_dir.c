#include "uls.h"

t_App *new_CD(t_App *app) {
    t_CD *cd = malloc(sizeof(t_CD ));
    app->cur_dir->current_DIR = cd;
    // TODO: fill all NULL

    return cd;
}

void read_dir(t_App *app) {
    t_CD *cd = new_CD(app);
    cd->current_DIR = opendir(".");     // TODO: убрать позже и сделать для любой директории
    produce_list_attr(app);
    // apply_filters(app);
    // apply_sort(app);
    // apply_format(app);
    // apply_printmode(app);
    closedir(cd->current_DIR);
}
