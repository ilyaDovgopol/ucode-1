#include <stdbool.h>

void mx_printchar(char c);
static void smart_print_newline(bool *flag);

void mx_str_separate(const char *str, char delim) {
    if (!str)
       return;
    int i = 0;
    bool flag = true;
    while (str[i]) {
        if (str[i] == delim) {
            smart_print_newline(&flag);
        }    
        else {
            mx_printchar(str[i]);
            flag = true;
        }
        i++;
    }
    smart_print_newline(&flag);
}

static void smart_print_newline(bool *flag) {
    if (*flag) {
        mx_printchar('\n');
        *flag = false;
    }
}
