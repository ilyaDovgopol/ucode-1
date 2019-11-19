#include "header.h"

static int my_atoi(char *s);
static bool is_valid_name(char *s);
static bool parse_line(char *line, char **arg1, char **arg2, int *arg3);
static void init_city(t_App *app);
static void push_element_in_city(char *elem, t_App *app);
static int index_in_city(char *elem, t_App *app);
static void init_adjacency_matrix(t_App *app);
static char *read_file(char *argv[], t_App *app);
static void parse_rest_of_lines(t_App *app, char **str_parsed);

void initialize(int argc, char *argv[], t_App *app) {

    // initialize
    app->city = NULL;    // in heap
    app->AM = NULL;         // in heap
    app->dist_M = NULL;     // in heap
    app->parsed_lines_array = NULL;   // in heap
    app->file_to_str = NULL;           // in heap

    if (argc != 2) {
        cast_error_message(Invalid_Number_Of_CommandLine, app);
    }
    char *str = read_file(argv, app);
    
    // validate str:
    // parse by \n
    app->parsed_lines_array = mx_strsplit(str, '\n');
    char **str_parsed = app->parsed_lines_array;

    // parse 1-st line
    app->SIZE = my_atoi(str_parsed[0]); 
    if (app->SIZE == -1)
        cast_error_message(Line1_isnt_valid, app);
    parse_rest_of_lines(app, str_parsed);
    if (app->city[app->SIZE - 1] == NULL) {
        cast_error_message(Invalid_Number_of_Islands, app);
    }
}

static void parse_rest_of_lines(t_App *app, char **str_parsed) {
    init_city(app);
    init_adjacency_matrix(app);
    for (int i = 1; str_parsed[i] != NULL; i++) {
        char *arg1 = NULL;
        char *arg2 = NULL;
        int arg3 = -1;
        if (parse_line(str_parsed[i], &arg1, &arg2, &arg3)) {
            push_element_in_city(arg1, app);
            push_element_in_city(arg2, app);
            int i = index_in_city(arg1, app);
            int j = index_in_city(arg2, app);
            app->AM[i * app->SIZE + j] = arg3;
            app->AM[j * app->SIZE + i] = arg3;
        }
        else {
            free(arg1);
            free(arg2);
            app->invalid_line_number = i + 1;
            cast_error_message(Line_isnt_Valid, app);
        }
        free(arg1);
        free(arg2);
    }
}

static int my_atoi(char *s) {
    int res = 0;
    while (*s != '\0') {
        if (!mx_isdigit(*s)) return -1;
        res = 10 * res + (*s) - '0';
        s++;
    }
    if (res == 0) res = -1;
    return res;
}

static bool is_valid_name(char *s) {
    if (mx_strlen(s) == 0)
        return false;
    for (int i = 0; s[i] != '\0'; i++)
        if(!mx_isalpha(s[i])) return false;
    return true;
}

static bool parse_line(char *line, char **arg1, char **arg2, int *arg3) {
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
    free(number);
    return true;
}

// initit
static void init_city(t_App *app) {
    app->city = malloc(app->SIZE * sizeof (char *) + 1);
    if (app->city == NULL) {
        exit(1);
    }
    for (int i = 0; i < app->SIZE + 1; i++) {
        app->city[i] = NULL;
    }
}

static void push_element_in_city(char *elem, t_App *app) {
    char **city = app->city;
    //go through city to find elem
    int i;
    for (i = 0; i < app->SIZE; i++) {
        if (city[i] == NULL)
            break;
        if (mx_strcmp(city[i], elem) == 0)
            return;
    }
    //add elem to city
    if (i < app->SIZE)
        city[i] = mx_strdup(elem);
    else { //  if too many elem
        cast_error_message(Invalid_Number_of_Islands, app);
    }
}

static int index_in_city(char *elem, t_App *app) {
    for (int i = 0; i < app->SIZE; i++)
        if ( mx_strcmp(app->city[i], elem) == 0)
            return i;
    return -1;
}

static void init_adjacency_matrix(t_App *app) {
    app->AM = malloc(app->SIZE * app->SIZE * sizeof(int));
    for (int i = 0; i < app->SIZE; i++)
        for (int j = 0 ; j < app->SIZE; j++) {
            if (i == j)
                app->AM[i * app->SIZE + j] = 0;
            else
                app->AM[i * app->SIZE + j] = 1000000000;
        }
}

static char *read_file(char *argv[], t_App *app) {
    app->file_name = argv[1];
    // Check if file exists
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        close(fd);
        cast_error_message(File_Doesnt_Exist, app);
    }
    close(fd);

    //read file and validate if file empty
    app->file_to_str = mx_file_to_str(argv[1]);
    char *str = app->file_to_str;
    if (mx_strlen(str) == 0) {
        cast_error_message(File_Is_Empty, app);
    }
    return str;
}

