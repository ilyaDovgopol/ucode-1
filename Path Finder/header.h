//
// Created by Oleg Berdyshev on 2019-10-24.
//

#ifndef HEADER_H
#define HEADER_H

#include "libmx.h"

// --------------   PATH FINDER
typedef struct s_APP {
    int SIZE;
    char **city; 
    int **a;
    int **dist;
    //t_list *all_paths;
    int invalid_line_number;
    char *file_name;
} t_App;

typedef enum Err {
    Invalid_Number_Of_CommandLine,
    File_Doesnt_Exist,
    File_Is_Empty,
    Line1_isnt_valid,
    Line_isnt_Valid,
    Invalid_Number_of_Islands 

} e_Error;

bool mx_isdigit(int c);
bool mx_isalpha(int c);

void free_all( t_App *app);

#endif //LIBMX_H

