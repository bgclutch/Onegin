#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "../onegin_headers/onegin_structs.h"

size_t my_strlen(const char* arr);

void_sex my_sort(Onegin_Arrays *data_arrays, size_t left, size_t right);

void_sex my_sort_end(Onegin_Arrays *data_arrays, const Onegin_Variables data_vars);

int my_string_comparer_from_start(const char* str_1, const char* str_2, size_t len_1, size_t len_2);

int my_string_comparer_from_end(const char* str_1, const char* str_2, size_t len_1, size_t len_2);

void_sex sort_arrays(Onegin_Variables *data_vars, Onegin_Arrays *data_arrays);

void_sex my_qsort(Onegin_Arrays *data_arrays, size_t type_size, size_t left, size_t right);//main struct && comparer

//size_t partition(Onegin_Arrays *data_arrays, size_t type_size, size_t left, size_t right);

#endif //BUBBLE_SORT_H_