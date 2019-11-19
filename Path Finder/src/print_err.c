#include "header.h"

void cast_error_message(e_Error err, t_App *app) {
    switch (err) {
        case Invalid_Number_Of_CommandLine:
            mx_printerr("usage: ./pathfinder [filename]");
            break;

        case File_Doesnt_Exist:
            mx_printerr("error: file ");
            mx_printerr(app->file_name);
            mx_printerr(" doesn't exist");
            break;

        case File_Is_Empty:
            mx_printerr("error: file ");
            mx_printerr(app->file_name);
            mx_printerr(" is empty");
            break;

        case Line1_isnt_valid:
            mx_printerr("error: line 1 isn't valid"); 
            break;

        case Line_isnt_Valid:
            mx_printerr("error: line ");
            char *snum = mx_itoa(app->invalid_line_number);
            mx_printerr(snum);
            free(snum);
            snum = NULL;
            mx_printerr(" isn't valid");
            break;

        case Invalid_Number_of_Islands:
            mx_printerr("error: invalid number of islands");
            break;
    }
    mx_printerr("\n");
    free_all(app);
    exit(1);
}

