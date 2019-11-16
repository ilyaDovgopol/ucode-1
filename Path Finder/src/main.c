#include "libmx.h"
#include "header.h" 
// ----------------------------------------  test
#include <stdio.h>
void test_print_file_to_str(char *str) {
    printf("---   Print file   ---\n");
    if (str == NULL)
        printf("ERROR: str == NULL\n");
    else
        printf("\"%s\"\n", str);
    printf("Size of file: %d\n", mx_strlen(str));
}

void test_print_str(char **str_parsed) {
    printf("---   str_parsed   ---\n{");
    int i;
    for (i = 0; str_parsed[i] != NULL; i++)
        printf("\"%s\",",  str_parsed[i]);
    printf(" NULL }\n");
}

void test_paresd_args(char *arg1, char *arg2, char *number) {
    printf("---   in parse_line: arg1=\'%s\' arg2=\'%s\' int=\'%s\'\n", arg1, arg2, number);
}

void text_print_CITY(t_App *app) {
    printf("---- Print city: ----\n");
    for (int i = 0; i < app->SIZE; i++) {
        if (app->city[i] != NULL)
            printf("%d) %s\n", i, app->city[i]);
        else
            printf("%d) NULL\n", i);
    }
    printf("SIZE = %d\n", app->SIZE);  
    printf("--------\n");  
}

void test_print_AM(t_App *app){                                     // TEST    
    printf("----- Print Adjancency matix:   -----\n");     //DEBUG delete
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = 0 ; j < app->SIZE; j++)
            printf("%d\t", app->AM[i * app->SIZE + j]);
        
        printf("\n");
    }                                        //DEBUG delete
}

void test_print_cost_matrix(t_App *app) {
    printf("Print cost matix:\n");     //DEBUG delete
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = 0 ; j < app->SIZE; j++)
            printf("%d\t", app->dist_M[i * app->SIZE + j]);
        
        printf("\n");
    }    
}
// ----------------------------------------

int my_atoi(char *s) {   // TODO: do it
    //if (s[0] == '\0') return -1; // empty
    int res = 0;
    while (*s != '\0') {
        if (!mx_isdigit(*s)) return -1;
        res = 10 * res + (*s) - '0';
        s++;
    }
    if (res == 0) res = -1;
    return res;
}

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
    //test_paresd_args(*arg1, *arg2, number);                                    // TEST
    free(number);
    return true;
}

void init_city(t_App *app) {
    app->city = malloc(app->SIZE * sizeof (char *) + 1);
    if (app->city == NULL) {
        exit(1);
    }
    for (int i = 0; i < app->SIZE + 1; i++) {
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
    //add elem to city
    if (i < app->SIZE)
        city[i] = mx_strdup(elem);
    else { //  if too many elem
        cast_error_message(Invalid_Number_of_Islands, app);
    }
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
                app->AM[i * app->SIZE + j] = 1000000000;
        }
}

char *read_file(char *argv[], t_App *app) {
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
    //TODO: проверить строка заканчивается на \0 или на EOF      -----------------!!!!!!!!!!!!!!!!!!!!!!!!
    return str;
}

void initialize(int argc, char *argv[], t_App *app) {

    // initialize
    app->city = NULL;    // in heap
    app->AM = NULL;         // in heap
    app->dist_M = NULL;     // in heap
    app->parsed_lines_array = NULL;   // in heap
    app->file_to_str = NULL;           // in heap

    //TODO: validate arguments
    if (argc != 2) {
        cast_error_message(Invalid_Number_Of_CommandLine, app);
    }
    char *str = read_file(argv, app);
    //test_print_file_to_str(str);                               // TEST
    
    // validate str:
    // parse by \n
    app->parsed_lines_array = mx_strsplit(str, '\n');
    char **str_parsed = app->parsed_lines_array;
    //test_print_str(str_parsed);                                // TEST

    // parse 1-st line
    app->SIZE = my_atoi(str_parsed[0]); 
    if (app->SIZE == -1)
        cast_error_message(Line1_isnt_valid, app);

    // parse the rest of lines
    init_city(app);
    init_adjacency_matrix(app);
    for (int i = 1; str_parsed[i] != NULL; i++) {
        char *arg1 = NULL;
        char *arg2 = NULL;
        int arg3 = -1;
        // if (str_parsed[i] == NULL) {
        //     cast_error_message(Invalid_Number_of_Islands, app);
        // }
        if (parse_line(str_parsed[i], &arg1, &arg2, &arg3)) {
            push_element_in_city(arg1, app);
            push_element_in_city(arg2, app);
            // TODO: fill adjacency matrix
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
    //text_print_CITY(app);                                   // TEST
    //test_print_AM(app);                                     // TEST    

    //if more lines then given number
    if (app->city[app->SIZE - 1] == NULL) {
        cast_error_message(Invalid_Number_of_Islands, app);
    }
}

// ---------------------------------------------------------------------
void init_dist_matrix(t_App *app) {
    app->dist_M = malloc(app->SIZE * app->SIZE * sizeof(int));
    for (int i = 0; i < app->SIZE; i++)
        for (int j = 0 ; j < app->SIZE; j++) {
                app->dist_M[i * app->SIZE + j] = app->AM[i * app->SIZE + j];
        }
}

void use_Floyd_Warshall(t_App *app) {
    int size = app->SIZE;
    int *dist = app->dist_M;
    for (int k = 0; k < size; k++) { 
        // Pick all vertices as source one by one 
        for (int i = 0; i < size; i++) { 
            // Pick all vertices as destination for the 
            // above picked source 
            for (int j = 0; j < size; j++) { 
                // If vertex k is on the shortest path from 
                // i to j, then update the value of dist[i][j]
                int ik = i * size + k;
                int kj = k * size + j;
                int ij = i * size + j;
                if (dist[ik] + dist[kj] < dist[ij]) 
                    dist[ij] = dist[ik] + dist[kj]; 
            } 
        } 
    }
}

void make_cost_matrix(t_App *app) {
    init_dist_matrix(app);
    use_Floyd_Warshall(app);
}

void init_stack(t_stack **st, t_App *app, int i, int j) {
    *st = malloc(sizeof(t_stack)); // i, j, v2, v3, ..., vn, i
    if ((*st) == NULL) exit(1);

    (*st)->max_size = app->SIZE;
    (*st)->path = malloc((*st)->max_size * sizeof(int) + 1);
    (*st)->path[0] = i;
    (*st)->path[1] = j;
    (*st)->size = 1;
}

void push_in_stack(t_stack *st, int elem) {
    if (st->size < st->max_size) {
        st->size++;
        st->path[st->size] = elem;
    }
}

int pop_from_stack(t_stack *st) {
    if (st->size > 1) {
        st->size--;
        return st->path[st->size + 1];
    }
    return st->path[1]; // всегда первый элемент не можно убрать.
}

int get_from_stack(t_stack *st) {
    return st->path[st->size];
}

bool is_next(t_App *app, t_stack *st, int *cur) {
    // is there next possible way from vertex(j) bigger then cur
    // do linear search
    int j = get_from_stack(st);
    int i = st->path[0];
    int *AM = app->AM;
    int *DM = app->dist_M;
    int size = app->SIZE;
    //int starting_vertex = *cur == 0 ? 0 : *cur + 1;  !!!!!!!!!!!!!!!!!!!!!!!!!
    int starting_vertex = *cur + 1;                   //!!!!!!!!!!!!!!!!!!
    for (int k = starting_vertex; k < app->SIZE; k++) {
        if (j != k) {
            if (DM[i * size + j] - AM[j * size + k] == DM[i * size + k]) {
                *cur = k;
                return true;
            }
        }
    }
    return false;
}
// ------------------------------------------------
char *get_name_by_id(int i, t_App *app) {
    return app->city[i];
}
void print_line(void) {
    char s[]= "========================================";
    mx_printstr(s);
}

void print_path(t_App *app, t_stack *st) {
    mx_printstr("Path: ");
    mx_printstr(get_name_by_id (st->path[0], app));
    mx_printstr(" -> ");
    mx_printstr(get_name_by_id(st->path[1], app));
    mx_printstr("\n");
}

void print_route(t_App *app, t_stack *st) {
    mx_printstr("Route: ");
    for(int i = st->size; i >= 2; i--) {
        mx_printstr(get_name_by_id(st->path[i], app));
        mx_printstr(" -> ");

    }
    mx_printstr(get_name_by_id(st->path[1], app));
    mx_printstr("\n");
}

void print_distance(t_App *app, t_stack *st) {
    mx_printstr("Distance: ");
    int total_dist = 0;
    for(int i = st->size - 1; i >= 2; i--) {
        int dist = app->AM[st->path[i] * app->SIZE + st->path[i + 1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" + ");
    }
    if (total_dist != 0) {
        int dist = app->AM[st->path[2] * app->SIZE + st->path[1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" = ");
    }
    else
       total_dist = app->AM[st->path[2] * app->SIZE + st->path[1]];
    mx_printint(total_dist);
    mx_printstr("\n");
}

void print_path_info(t_App *app, t_stack *st) {
    static bool first_line = true;
    if (first_line) {
        first_line = false;
    }
    else {
        mx_printstr("\n");
    }
    print_line();
    mx_printstr("\n");
    print_path(app, st);
    print_route(app, st);
    print_distance(app, st);
    print_line();
}
// -------------------------------------------------------

void restore_path_Helper(t_App *app, t_stack *st) {
    // base case
    if (get_from_stack(st) == st->path[0]) { //TODO: HERE IS WRONG CHECK should be some thing like:
        print_path_info(app, st);             // if (DM[i * size + j] - AM[j * size + k] == DM[i * size + k])
        return;
    }
    else { // recursive case
        // for all adjecency virtecies to j
        //int cur = 0;                         // !!!!!!!!!!!!!!
        int cur = -1;                         // !!!!!!!!!!!!!!
        while (is_next(app, st, &cur)) {
            // choose
            push_in_stack(st, cur);
            // explore
            restore_path_Helper(app, st);
            // un-choose
            pop_from_stack(st);
        }
    }
}

void restore_allpaths_from_to(t_App *app, int i, int j) {
    t_stack *st = NULL;
    init_stack(&st, app, i, j);

    restore_path_Helper(app, st);

    free(st->path);
    free(st);
}

void restore_all_paths(t_App *app) {
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = i + 1; j < app->SIZE; j++)
            restore_allpaths_from_to(app, i, j);
    }
}

void make_allpaths_and_print(t_App *app) {
    make_cost_matrix(app);
    restore_all_paths(app);
}
// ------------------------------------------------------------------
void delete_matrix(int *m) {
    if (m != NULL)
        free(m);
}

void free_all( t_App *app) {
    mx_del_strarr(&(app->city));
    delete_matrix(app->AM);
    delete_matrix(app->dist_M);
    mx_del_strarr(&(app->parsed_lines_array));
    mx_strdel(&(app->file_to_str));
}
// ------------------------------------------------------------------
int main(int argc, char *argv[]) {
    t_App *app = malloc(sizeof(t_App));

    initialize(argc, argv, app);
    make_allpaths_and_print(app);
    free_all(app);
    //system("leaks -q pathfinder hard");                          // TEST
    return 0;
}

