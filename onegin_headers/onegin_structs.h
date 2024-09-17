#ifndef ONEGIN_STRUCTS_H_
#define ONEGIN_STRUCTS_H_ 

#include <stdio.h>
#include <math.h>

#include "../onegin_headers/onegin_structs.h"

typedef void void_sex;

struct Onegin_Arrays
{
    char**   strings_ptrs;
    char*       my_buffer;
    size_t* strings_sizes;
    size_t*  strings_nums;
    size_t*   running_sum;
};

struct Onegin_Variables
{
    size_t       str_nums;
    size_t    symbols_num;
};



#endif //ONEGIN_STRUCTS_H_