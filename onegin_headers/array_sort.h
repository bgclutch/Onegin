#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "../onegin_headers/onegin_structs.h"

void_sex my_sort(Onegin_Arrays *data_arrays, const Onegin_Variables data_vars);

void_sex my_sort_end(Onegin_Arrays *data_arrays, const Onegin_Variables data_vars);

int my_string_comparer_from_start(const char* str_1, const char* str_2, size_t len_1, size_t len_2);

int my_string_comparer_from_end(const char* str_1, const char* str_2, size_t len_1, size_t len_2);

void_sex sort_arrays(Onegin_Variables data_vars, Onegin_Arrays *data_arrays);

#endif //BUBBLE_SORT_H_