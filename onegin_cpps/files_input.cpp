#include <stdio.h>
#include <assert.h>

#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/files_input.h"
#include "../onegin_headers/array_to_file_translation.h"


void_sex file_read_open(Onegin_Files_Attributes *data_files, const char *file_read_open)
{
    data_files->file_read = fopen(file_read_open,  "r");
    assert(data_files->file_read);
    memory_fault_error_checker(data_files->file_read, "file_read", "file_read_open");
}

void_sex file_write_open(Onegin_Files_Attributes *data_files, const char* file_write_open)
{
    data_files->file_write = fopen(file_write_open, "w");
    assert(data_files->file_write);
    memory_fault_error_checker(data_files->file_write, "file_write", "file_write_open");
}

size_t string_nums_counter(Onegin_Variables *data_vars,
                              Onegin_Files_Attributes *data_files,
                              const char* name_string)
{
    file_read_open(data_files, name_string); 
        
    data_vars->symbols_num = symbols_number(data_files);

    symbols_num_check(data_vars->symbols_num);

    my_buffer_create(data_vars, data_vars->symbols_num, data_files->file_read);

    my_file_close(data_files->file_read);

    return num_of_str(data_vars->my_buffer, data_vars->symbols_num);

}

bool input_is_correct(const int argc)
{
    return argc == 3 ?  1 : 0;
}
