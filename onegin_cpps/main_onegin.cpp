
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../onegin_headers/my_swap.h"
#include "../onegin_headers/bubble_sort.h"
#include "../onegin_headers/my_string_functions.h"
#include "../onegin_headers/text_actions.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/main_functions.h"
#include "../onegin_headers/files_input.h"


struct Onegin_Arrays data_arrays =
    {
        .strings_ptrs  = nullptr,
        .my_buffer     = nullptr,
        .strings_sizes = nullptr,
        .strings_nums  = nullptr,
        .running_sum   = nullptr
    };

    struct Onegin_Variables data_vars =
    {
        .str_nums    = 0,
        .symbols_num = 0
    };

    struct Onegin_Files_Attributes data_files = 
    {
        .file_read  =  nullptr,
        .file_write =  nullptr,
        .first_file_index =  0,
        .second_file_index = 0
    };


int main(int argc, char* argv[])
{
    //more functions!
    // for(size_t index; index < argc; index++)
    // {
    //     strtchr();
    // }

    file_read_open(&data_files, argv[1]); //cant open file to read, fix
        
    data_vars.symbols_num = symbols_number(&data_files);

    symbols_num_check(data_vars);

    my_buffer_create(&data_arrays, data_vars, data_files.file_read);
    //fprintf(stderr, "my_buffer %p\n", data_arrays.my_buffer);

    // for(size_t i = 0; i < data_vars.symbols_num; i++)
    // {
    //     printf("%c", data_arrays.my_buffer[i]);
    //     if(data_arrays.my_buffer[i] == '\n')
    //         printf("\npenis was found\n");
    // }

    my_file_close(data_files.file_read);
    
    data_vars.str_nums = num_of_str(&data_arrays, data_vars.symbols_num);

    dynamic_arrays_create(&data_arrays, data_vars);

    string_nums_and_sizes(data_vars, &data_arrays);

    ptrs_array_fill(data_vars, &data_arrays);

    printf("\n\n"
            "unsorted\n\n");

    output_array(data_vars, &data_arrays);

    printf("\n\n"
            "sorted by first letters\n\n");

    bubble_sort(data_arrays.strings_ptrs, data_arrays.strings_sizes, data_arrays.strings_nums, data_vars.str_nums - 1); //my_sort should be here

    output_array(data_vars, &data_arrays);

    printf("\n\n"
           "sorted from the start\n\n");

    my_sort(data_arrays.strings_ptrs, data_arrays.strings_sizes, data_arrays.strings_nums, data_vars.str_nums - 1);

    output_array(data_vars, &data_arrays);

     printf("\n\n"
            "sorted from the end\n\n");

    my_sort_end(data_arrays.strings_ptrs, data_arrays.strings_sizes, data_arrays.strings_nums, data_vars.str_nums - 1);

    output_array(data_vars, &data_arrays);

    printf("\n\n");

    file_write_open(&data_files, argv[2]);

    fill_sorted_file(&data_arrays, data_vars, data_files.file_write);
    
    mem_free(&data_arrays);

    my_file_close(data_files.file_write);
    
    return 0;
}

//TODO - 

