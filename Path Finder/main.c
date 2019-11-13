#include "libmx.h"
#include "header.h" 
//#include <stdlib.h> // TODO: delete

void cast_error_message(e_Error err, t_App *app) {
    switch (err) {
        case Invalid_Number_Of_CommandLine:
            //mx_printerr("usage: ./pathfinder [filename]");
            printf("usage: ./pathfinder [filename]");
            break;
        case File_Doesnt_Exist:
            // mx_printerr("error: file ");
            // mx_printerr(app->file_name);
            // mx_printerr(" doesn't exist");
            printf("error: file doesn't exist");
            break;
        case File_Is_Empty:
            // mx_printerr("error: file ");
            // mx_printerr(app->file_name);
            // mx_printerr("  is empty");
            printf("error: file is empty");
            break;
        case Line1_isnt_valid:
            //mx_printerr("error: line 1 isn't valid"); // !!!!!!!!!!!!!!  TODO: delete comment
            printf("line 1 isn't valid");
            break;
        case Line_isnt_Valid:
            // mx_printerr("error:  line ");
            // mx_printerr(app->invalid_line_number);
            // mx_printerr(" isn't valid");
            printf("error:  line %d  isn't valid", app->invalid_line_number);
            break;
        case Invalid_Number_of_Islands:
            //mx_printerr("error: invalid number of islands");
            printf("error: invalid number of islands");
            break;
    }
    //mx_printerr("\n");  // !!!!!!!!!!!!!!  TODO: delete comment
    free_all(app);
    exit(1);
}

int my_atoi(char *s) {   // TODO: do it
    int res = 0;
    while (*s != '\0') {
        if (!mx_isdigit(*s)) return -1;
        res = 10 * res + (*s) - '0';
        s++;
    } 
    return res;
}

bool is_valid_name(char *s) {
    // we do not consider case when s==NULL that is malloc did not work
    if (mx_strlen(s) == 0)
        return false;
    for (int i = 0; s[i] != '\0'; i++)
        if(!mx_isalpha(s[i])) return false;
    return true;
}

bool parse_line(char *line, char **arg1, char **arg2, int *arg3) {
    int dash_idx = mx_get_char_index(line, '-');
    int coma_idx = mx_get_char_index(line, ',');
    int len = mx_strlen(line);
    if (dash_idx == -1 || coma_idx == -1 || len == 0 
        || dash_idx > coma_idx)
        return false;
    *arg1 = mx_strndup(line, dash_idx);
    *arg2 = mx_strndup(line + dash_idx + 1, coma_idx - dash_idx - 1);
    char *number = mx_strndup(line + coma_idx + 1, len - coma_idx - 1);
    if (!is_valid_name(*arg1) || !is_valid_name(*arg2))
        return false;
    *arg3 = my_atoi(number);
    if (*arg3 == -1)
        return false;
    //printf("in parse_line: arg1=\'%s\' arg2=\'%s\' int=\'%s\'\n", *arg1, *arg2, number); // DEBUG: delete
    free(number);
    return true;
}

void init_city(t_App *app) {
    app->city = malloc(app->SIZE * sizeof (char *));
    if (app->city == NULL) {
        exit(1);
    }
    for (int i = 0; i < app->SIZE; i++) {
        app->city[i] = NULL;
    }
}

void push_element_in_city(char *elem, t_App *app) {
    char **city = app->city;
    //go through city to find elem
    int i;
    for (i = 0; i < app->SIZE; i++) {
        if (city[i] == NULL)
            break;
        if (mx_strcmp(city[i], elem) == 0)
            return;
    }
    //if not add to city
    if (i < app->SIZE)
        city[i] = mx_strdup(elem);
}

int index_in_city(char *elem, t_App *app) {
    for (int i = 0; i < app->SIZE; i++)
        if ( mx_strcmp(app->city[i], elem) == 0)
            return i;
    return -1;
}

void init_adjacency_matrix(t_App *app) {
    app->AM = malloc(app->SIZE * app->SIZE * sizeof(int));
    for (int i = 0; i < app->SIZE; i++)
        for (int j = 0 ; j < app->SIZE; j++) {
            if (i == j)
                app->AM[i * app->SIZE + j] = 0;
            else
                app->AM[i * app->SIZE + j] = 2147483647;
        }
}

void initialize(int argc, char *argv[], t_App *app) {
    //TODO: validate arguments
    // if (argc != 2) {
    //     cast_error_message(Invalid_Number_Of_CommandLine, app);
    // }
    //TODO: read file and validate if file empty or do not exist
    // char *str = mx_file_to_str(argv[1]);
    // app->file_name = argv[1];
    // if (str == NULL) {
    //     cast_error_message(File_Doesnt_Exist, app);
    // }
    // if (mx_strlen(str) == 0) {
    //     cast_error_message(File_Is_Empty, app);
    // }
    //TODO: проверить строка заканчивается на \0 или на EOF      -----------------!!!!!!!!!!!!!!!!!!!!!!!!
    char str[] = "4\nGreenland-Bananal,8\nFraser-Greenland,10\nBananal-Fraser,3\nJava-Fraser,5\n"; // DEBUG: delete
    // validate str:
    // parse by \n
    char **str_parsed = mx_strsplit(str, '\n');
    // parse 1-st line
    app->SIZE = my_atoi(str_parsed[0]); 
    if (app->SIZE == -1)
        cast_error_message(Line1_isnt_valid, app);
    printf("line 0) %d\n", app->SIZE);

    // parse the rest of lines
    init_city(app);
    init_adjacency_matrix(app);
    for (int i = 1; i <= app->SIZE; i++) {
        char *arg1 = NULL;
        char *arg2 = NULL;
        int arg3 = -1;
        if (str_parsed[i] == NULL) {
            cast_error_message(Invalid_Number_of_Islands, app);
        }
        if (parse_line(str_parsed[i], &arg1, &arg2, &arg3)) {
            printf("line %d) arg1=\'%s\' arg2=\'%s\' int=%d\n", i, arg1, arg2, arg3); // DEBUG: delete
            // TODO: input  arg1 and arg2 into city
            push_element_in_city(arg1, app);
            push_element_in_city(arg2, app);
            // TODO: fill a-matrix
            int i = index_in_city(arg1, app);
            int j = index_in_city(arg2, app);
            app->AM[i * app->SIZE + j] = arg3;
            app->AM[j * app->SIZE + i] = arg3;
        }
        else {
            free(arg1);
            free(arg2);
            app->invalid_line_number = i;
            cast_error_message(Line_isnt_Valid, app);
        }
        free(arg1);
        free(arg2);
    }

    printf("Print city=");                 //DEBUG delete
    for (int i = 0; i < app->SIZE; i++) {
        if (app->city[i] != NULL)
            printf("(%s) ", app->city[i]);
    }                                        //DEBUG delete
    printf("Print Adjancency matix:\n");     //DEBUG delete
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = 0 ; j < app->SIZE; j++)
            printf("%d\t", app->AM[i * app->SIZE + j]);
        
        printf("\n");
    }                                        //DEBUG delete

    //if more lines then given number
    if (str_parsed[app->SIZE + 1] != NULL) {
        cast_error_message(Invalid_Number_of_Islands, app);
    }
    // make array of cities - city
    // and Adjacency matrix
}

void produce_allpaths(t_App *app) {

}

void print_allpaths(t_App *app) {

}

void free_all( t_App *app) {

}

int main(int argc, char *argv[]) {
    t_App *app = malloc(sizeof(t_App));
   
    initialize(argc, argv, app);
    produce_allpaths(app);
    print_allpaths(app);
    free_all(app);
    return 0;
}