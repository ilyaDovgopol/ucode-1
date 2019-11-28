#include "uls.h"

// static char **dup_string_array(int argc, char **argv) {
//     if (argv == NULL) return NULL;

//     char **arr = malloc(argc * sizeof(char *));
//     for (int i = 0; i < argc; i++) {
//         arr[i] = mx_strdup(argv[i]);
//     }

// }

// static t_App *new_app(int argc, char *argv[]) {
//     t_App *this = NULL;
//     this = malloc(sizeof(t_App));
//     if (this == NULL) {
//         exit(1);
//     }

//     this->argc = argc;
//     this->argv = dup_string_array(argc, argv);
//     return this;
// }

int main(int argc, char *argv[]) {
    printf("%d %s", argc, argv[0]);

    // app = new_app(argc, argv);
    // readargs_parse_fill(app);
    // make_aligned_lines(app);
    // print_aligned_lines(app);
    // free_app(&app);
    t_App *app = malloc(sizeof(t_App));
    read_dir(app);
    return 0;
}

