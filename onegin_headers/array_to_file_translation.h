#ifndef MAIN_FUNCTIONS_H_
#define MAIN_FUNCTIONS_H_

#include "../onegin_headers/onegin_structs.h"

size_t symbols_number(Onegin_Files_Attributes *data_files);

void_sex symbols_num_check(const size_t symbols_num);

void_sex my_buffer_create(Onegin_Variables *data_vars, size_t symbols_num, FILE* file_name);

size_t num_of_str(char* my_buffer, const size_t symbols_num);

void_sex ptrs_array_fill(const Onegin_Variables data_vars, Onegin_General_Data *onegin_array, const char* my_buffer);

void_sex string_nums_and_sizes(Onegin_Variables *data_vars, Onegin_General_Data *onegin_array);

void_sex count_prefix_sum(const Onegin_Variables data_vars, Onegin_General_Data *onegin_array);

void_sex fill_sorted_file(Onegin_General_Data *onegin_array, const Onegin_Variables data_vars, Onegin_Files_Attributes *data_files);

void_sex complete_array_of_ptrs(Onegin_General_Data *onegin_array, Onegin_Variables *data_vars);

void_sex mem_free(Onegin_General_Data *onegin_array, char* my_buffer);

#endif //MAIN_FUNCTIONS_H_