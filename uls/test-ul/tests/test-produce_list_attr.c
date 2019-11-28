#include "uls.h"
#include <stdio.h>
#include "test.h"

void test_print_attr(t_App *app) {
    
    t_list *cur = app->cur_dir->list_attr;
    if (cur == NULL) printf("List is empty\n");
    else printf("HEAD\nV\n");
    for (int i = 0; cur != NULL; cur = cur->next, i++) {
        printf("%d)-> ", i);
        print_attr_list(cur->data);
    }
    printf("End of Test produce _list_ attr\n");
}

int main(void) {
    
    t_App *app = malloc(sizeof(t_App));
    read_dir(app);
    test_print_attr(app);
    // if (app) printf("app != NULL\n");
    // else printf("app == NULL\n");
    // if (app->cur_dir) printf("app->cur_dir != NULL\n");
    // else printf("app->cur_dir == NULL\n");
    // if (app->cur_dir->current_DIR) printf("app->cur_dir->current_DIR != NULL\n");
    // else printf("app->cur_dir->current_DIR == NULL\n");
    // printf("Test produce _list_ attr\n");
    print_list_anonim_data(app->cur_dir->list_attr);
    return 0;
}

