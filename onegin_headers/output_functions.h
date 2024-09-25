#ifndef OUTPUT_FUNCTIONS_H_
#define OUTPUT_FUNCTIONS_H_

#include <stdio.h>
#include <math.h>

#include "../onegin_headers/onegin_structs.h"

void_sex output_array(const Onegin_General_Data *onegin_array, const size_t str_nums);

void_sex memory_fault_error_checker(const void* data, const char* name, const char* func);

void_sex my_file_close(FILE* data);

void_sex compete_outp_array(Onegin_Variables *data_vars, Onegin_General_Data *onegin_array,
                            char* my_buffer, Onegin_Files_Attributes *data_files, const char* name_string);


#endif //OUTPUT_FUNCTIONS_H_
