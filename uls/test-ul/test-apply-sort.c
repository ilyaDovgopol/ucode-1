#include "uls.h"

t_App *new_App(void){
    t_App *app = malloc(sizeof(t_App));
    app->al = NULL; // attributs for aligning
    app->flags = NULL;
    app->cur_dir = NULL;
    return app;
}
#include "test.h"

int main() {
    t_App *app = new_App();
    printf("Test csort sort_size\n");
    app->command[csort] = sort_size;
    read_dir(app);
    print_attr_list(app->cur_dir->list_attr);

    // printf("Test csort sort_nosort\n");
    // app->command[csort] = sort_nosort;
    // read_dir(app);
    // print_attr_list(app->cur_dir->list_attr);
    return 0;
}

