#include <stdio.h>

#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/files_input.h"
#include "../onegin_headers/array_to_file_translation.h"


void_sex file_read_open(Onegin_Files_Attributes *data_files, const char *file_read_open)
{
    data_files->file_read = fopen(file_read_open,  "r");
    memory_fault_error_checker(data_files->file_read, "file_read", "file_read_open");
}

void_sex file_write_open(Onegin_Files_Attributes *data_files, const char* file_write_open)
{
    data_files->file_write = fopen(file_write_open, "w");
    memory_fault_error_checker(data_files->file_write, "file_write", "file_write_open");
}

void_sex complete_array_of_ptrs(Onegin_Variables data_vars, Onegin_Arrays *data_arrays,
                                Onegin_Files_Attributes *data_files, const char* name_string)
{
    file_read_open(data_files, name_string); 
        
    data_vars.symbols_num = symbols_number(data_files);

    symbols_num_check(data_vars);

    my_buffer_create(data_arrays, data_vars, data_files->file_read);

    my_file_close(data_files->file_read);
    
    data_vars.str_nums = num_of_str(data_arrays, data_vars.symbols_num);

    dynamic_arrays_create(data_arrays, data_vars);

    string_nums_and_sizes(data_vars, data_arrays);

    count_prefix_sum(data_vars, data_arrays);

    ptrs_array_fill(data_vars, data_arrays);
}

bool input_is_correct(const int argc, const char* const* const argv)
{
    if(argc == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


