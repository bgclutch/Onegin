#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/onegin_structs.h"

void_sex output_array(const Onegin_Variables data_variables, const Onegin_Arrays *data_arrays)
{
    for(size_t i = 0; i < data_variables.str_nums; i++)
    {
        puts(data_arrays->strings_ptrs[i]);
    }
}


void_sex memory_fault_error_checker(const void* data, const char* name, const char* func)
{
    if(data == nullptr)
    {
        printf("not enough memory to do actions with %s in %s, lol\n\n", name, func);
    }
}

void_sex my_file_close(FILE* data)
{
    if(fclose(data))
        fprintf(stderr, "error in fclose\n\n");
}