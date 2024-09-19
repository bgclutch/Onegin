#ifndef ONEGIN_STRUCTS_H_
#define ONEGIN_STRUCTS_H_ 

#include <stdio.h>
#include <math.h>

#include "../onegin_headers/onegin_structs.h"

typedef void void_sex;

enum CompareResults
{
    CONTINUE_COMPARE = 0,
    SWAP_STRINGS     = 1,
    NOT_SWAP_STRINGS = 2
};


struct Onegin_Arrays
{
    char**   strings_ptrs;
    char*       my_buffer;
    size_t* strings_sizes;
    size_t*  strings_nums;
    size_t*   prefix_sum;
};

struct Onegin_Variables
{
    size_t       str_nums;
    size_t    symbols_num;
};

struct Onegin_Files_Attributes
{
    FILE*           file_read;
    FILE*          file_write;
    size_t   first_file_index;
    size_t  second_file_index;
};


#endif //ONEGIN_STRUCTS_H_