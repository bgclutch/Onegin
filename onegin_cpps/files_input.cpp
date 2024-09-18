#include <stdio.h>

#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/files_input.h"

void_sex file_read_open(Onegin_Files_Attributes *data_files, const char *file_read_open)
{
    data_files->file_read = fopen(file_read_open,  "r");
    memory_fault_error_checker(data_files->file_read, "file_read", "file_read_open"); //strrchr
}

void_sex file_write_open(Onegin_Files_Attributes *data_files, const char* file_write_open)
{
    data_files->file_write = fopen(file_write_open, "w");
    memory_fault_error_checker(data_files->file_write, "file_write", "file_write_open");
}

// void_sex file_index_finder(Onegin_Files_Attributes *data_files, const char* const* const argv)
// {
    
// }
