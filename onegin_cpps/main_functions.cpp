#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/text_actions.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/main_functions.h"

size_t symbols_number(Onegin_Files_Attributes data_files)
{
    assert(data_files.file_read && "pososal huyaku");
    fseek(data_files.file_read, 0, SEEK_END);
    size_t result = (size_t)ftell(data_files.file_read);//number of symbols
    fseek(data_files.file_read, 0, SEEK_SET);

    return result;
}


void_sex symbols_num_check(const Onegin_Variables *data_vars)
{
    if(data_vars->symbols_num == 0)      
    {
        printf("fill your file better, lol\n\n"); //free mem and finish
    }
}


void_sex my_buffer_create(Onegin_Arrays *data_arrays, Onegin_Variables *data_vars, FILE* file_name)
{
    data_arrays->my_buffer = (char*) calloc(data_vars->symbols_num, sizeof(char));
    memory_fault_error_checker(data_arrays->my_buffer, "my_buffer", "my_buffer_create");

    fread(data_arrays->my_buffer, sizeof(char), data_vars->symbols_num, file_name);
}


void_sex dynamic_arrays_create(Onegin_Arrays *data_arrays, Onegin_Variables *data_vars)
{
    data_arrays->strings_ptrs  = (char**) calloc(data_vars->str_nums, sizeof(char*)); //array of pointers to strings
    memory_fault_error_checker(data_arrays->strings_ptrs, "strings_ptrs", "dynamic_arrays_create");

    data_arrays->strings_sizes = (size_t*) calloc(data_vars->str_nums, sizeof(size_t)); //array of sizes
    memory_fault_error_checker(data_arrays->strings_sizes, "strings_sizes", "dynamic_arrays_create");

    data_arrays->strings_nums  = (size_t*) calloc(data_vars->str_nums ,sizeof(size_t)); //array of string positions
    memory_fault_error_checker(data_arrays->strings_nums, "strings_nums", "dynamic_arrays_create");

    data_arrays->running_sum   = (size_t*) calloc(data_vars->str_nums, sizeof(size_t)); //running sum array
    memory_fault_error_checker(data_arrays->running_sum, "running_sum", "dynamic_arrays_create");
}


void_sex string_nums_and_sizes(const Onegin_Variables data_vars, Onegin_Arrays *data_arrays)
{    
    size_t index = 0;
    data_arrays->running_sum[0] = 0;
    for(size_t str_n = 0; str_n < data_vars.str_nums - 1; str_n++)//strings lens
    {
        size_t counter = 0;

        while(data_arrays->my_buffer[index] != '\0' && index < data_vars.symbols_num)
        {
            counter++;
            index++;
        }
        counter++;
        index++;
        data_arrays->strings_nums[str_n] = str_n;
        data_arrays->strings_sizes[str_n] = counter;

        data_arrays->running_sum[str_n + 1] = data_arrays->running_sum[str_n] + counter; 

        counter = 0;
    }
}


void_sex ptrs_array_fill(const Onegin_Variables data_vars, Onegin_Arrays *data_arrays)
{
    for(size_t i = 0; i < data_vars.str_nums; i++)
    {
        data_arrays->strings_ptrs[i] = &(data_arrays->my_buffer[data_arrays->running_sum[i]]);
    }
}


void_sex fill_sorted_file(Onegin_Arrays *data_ararys, const Onegin_Variables data_vars, FILE* file_outp)
{
    for(size_t index = 0; index < data_vars.str_nums; index++)
        fputs(data_ararys->strings_ptrs[index], file_outp);
}


void_sex mem_free(Onegin_Arrays *data_arrays)
{
    free(data_arrays->my_buffer);
    free(data_arrays->strings_sizes);
    free(data_arrays->strings_nums);
    free(data_arrays->running_sum);
    free(data_arrays->strings_ptrs);
}

