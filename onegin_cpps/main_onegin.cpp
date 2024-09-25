
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#include "../onegin_headers/array_sort.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/array_to_file_translation.h"
#include "../onegin_headers/files_input.h"


// struct Onegin_General_Data general_data =
// {
//     .string_ptr  = nullptr,
//     .string_size =       0,
//     .string_num  =       0,
//     .prefix_sum  =       0
// };

struct Onegin_Variables data_vars = 
{
    .my_buffer   = nullptr,
    .str_nums    =       0,
    .symbols_num =       0
};

struct Onegin_Files_Attributes data_files = 
{
    .file_read  =  nullptr,
    .file_write =  nullptr,
    .first_file_index  = 0,
    .second_file_index = 0
};

 
int main(int argc, char* argv[])
{
    if(input_is_correct(argc))
    {
        data_vars.str_nums = string_nums_counter(&data_vars, &data_files, argv[1]);

        struct Onegin_General_Data *onegin_array = (Onegin_General_Data*) calloc(sizeof(Onegin_General_Data), data_vars.str_nums);

        complete_array_of_ptrs(onegin_array, &data_vars);

        sort_arrays(&data_vars, onegin_array);

        compete_outp_array(&data_vars, onegin_array, data_vars.my_buffer, &data_files, argv[2]);   

        printf("\nthanks for work!\n");
    }
    
    printf("good luck!\n");
    return 0;
}
