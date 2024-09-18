#ifndef MAIN_FUNCTIONS_H_
#define MAIN_FUNCTIONS_H_

#include "../onegin_headers/onegin_structs.h"

size_t symbols_number(Onegin_Files_Attributes *data_files);

void_sex symbols_num_check(const Onegin_Variables data_vars);

void_sex my_buffer_create(Onegin_Arrays *data_arrays, Onegin_Variables data_vars, FILE* file_name);

void_sex dynamic_arrays_create(Onegin_Arrays *data_arrays, Onegin_Variables data_vars);

void_sex ptrs_array_fill(const Onegin_Variables data_vars, Onegin_Arrays *data_arrays);

void_sex string_nums_and_sizes(const Onegin_Variables data_variables, Onegin_Arrays *data_arrays);

void_sex fill_sorted_file(Onegin_Arrays *data_ararys, const Onegin_Variables data_vars, FILE* file_outp);

void_sex mem_free(Onegin_Arrays *data_arrays);


#endif //MAIN_FUNCTIONS_H_