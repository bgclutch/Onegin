#ifndef ONEGIN_STRUCTS_H_
#define ONEGIN_STRUCTS_H_ 

#define RED     "\e[0;31m" ///< red
#define GREEN   "\e[0;32m" ///< green
#define YELLOW  "\e[0;33m" ///< yellow
#define BLUE    "\e[0;34m" ///< blue
#define DEL_COL    "\e[0m" ///< reset color

#define RED_TEXT(text)    RED text DEL_COL    ///< red text + reset color  
#define GREEN_TEXT(text)  GREEN text DEL_COL  ///< green text + reset color
#define YELLOW_TEXT(text) YELLOW text DEL_COL ///< yellow text + reset color
#define BLUE_TEXT(text)   BLUE text DEL_COL   ///< blue text + reset color

#include <stdio.h>
#include <math.h>

#include "../onegin_headers/onegin_structs.h"

typedef void void_sex;

// enum CompareResults
// {
//     CONTINUE_COMPARE = 0,
//     SWAP_STRINGS     = 1,
//     NOT_SWAP_STRINGS = 2
// };

struct Onegin_General_Data
{
    const char* string_ptr;
    size_t     string_size;
    size_t      string_num;
    size_t      prefix_sum;
};

struct Onegin_Variables
{
    char*    my_buffer;
    size_t    str_nums;
    size_t symbols_num;
};


// struct Onegin_Arrays
// {
//     char**   strings_ptrs;
//     char*       my_buffer;
//     size_t* strings_sizes;
//     size_t*  strings_nums;
//     size_t*   prefix_sum;
// };

struct Onegin_Files_Attributes
{
    FILE*           file_read;
    FILE*          file_write;
    size_t   first_file_index;
    size_t  second_file_index;
};


#endif //ONEGIN_STRUCTS_H_