
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#include "../onegin_headers/array_sort.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/array_to_file_translation.h"
#include "../onegin_headers/files_input.h"


struct Onegin_Arrays data_arrays =
{
    .strings_ptrs  = nullptr,
    .my_buffer     = nullptr,
    .strings_sizes = nullptr,
    .strings_nums  = nullptr,
    .prefix_sum    = nullptr
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
    if(input_is_correct(argc))
    {
        complete_array_of_ptrs(&data_vars, &data_arrays, &data_files, argv[1]);

        sort_arrays(&data_vars, &data_arrays);

        compete_outp_array(&data_vars, &data_arrays, &data_files, argv[2]);   
        
        printf("\nthanks for work!\n");
    }
    
    printf("good luck!\n");
    return 0;
}
