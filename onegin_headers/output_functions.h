#ifndef OUTPUT_FUNCTIONS_H_
#define OUTPUT_FUNCTIONS_H_

#include <stdio.h>
#include <math.h>

#include "../onegin_headers/onegin_structs.h"

void_sex output_array(const Onegin_Variables data_variables, const Onegin_Arrays *data_arrays);

void_sex memory_fault_error_checker(const void* data, size_t line);

void_sex my_file_close(FILE* data);

#endif //OUTPUT_FUNCTIONS_H_