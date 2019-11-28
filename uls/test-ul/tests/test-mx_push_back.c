#include "test.h"

int main(void) {
    t_list * l = NULL;
    
    t_list *r0 = NULL;
    make_int_list_of(&r0, 4);
    print_list_int_data(r0);
    mx_push_back(&l, r0);

    t_list *r1 = NULL;
    make_int_list_of(&r1, 3);
    print_list_int_data(r1);
    mx_push_back(&l, r1);

    t_list *r2 = NULL;
    make_int_list_of(&r2, 2);
    print_list_int_data(r2);
    //mx_push_back(&l, r2);

    print_list_anonim_data(l);

    return 0;
}

