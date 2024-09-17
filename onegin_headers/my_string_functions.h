#ifndef MY_STRING_FUNCTIONS_H_
#define MY_STRING_FUNCTIONS_H_

#include "../onegin_headers/onegin_structs.h"

size_t my_strlen(const char* arr);

size_t my_string_comparer_from_start(const char* str_1, const char* str_2);

size_t my_string_comparer_from_end(const char* str_1, const char* str_2);

enum CompareResults compare_result(char symb_1, char symb_2);

#endif //MY_STRING_FUNCTIONS_H_