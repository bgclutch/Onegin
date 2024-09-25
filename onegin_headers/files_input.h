#ifndef FILE_INPUT_H_
#define FILE_INPUT_H_

#include "../onegin_headers/onegin_structs.h"

void_sex file_read_open(Onegin_Files_Attributes *data_files, const char *file_read_open);

void_sex file_write_open(Onegin_Files_Attributes *data_files, const char* file_write_open);

size_t string_nums_counter(Onegin_Variables *data_vars,
                              Onegin_Files_Attributes *data_files,
                              const char* name_string);

bool input_is_correct(const int argc);

#endif //FILE_INPUT_H_