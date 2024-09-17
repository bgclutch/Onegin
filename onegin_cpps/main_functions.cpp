#include <stdio.h>
#include <math.h>

#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/text_actions.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/main_functions.h"

void_sex symbols_number(Onegin_Variables *data_vars, FILE* file_name)
{
    fseek(file_name, 0, SEEK_END);
    data_vars->symbols_num = (size_t)ftell(file_name);//number of symbols
    fseek(file_name, 0, SEEK_SET);
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

    fread(data_arrays->my_buffer, sizeof(char), data_vars->symbols_num, file_name);
}


void_sex dynamic_arrays_create(Onegin_Arrays *data_arrays, Onegin_Variables *data_vars)
{
    data_arrays->strings_ptrs = (char**) calloc(data_vars->str_nums, sizeof(char*)); //array of pointers to strings
    memory_fault_error_checker(data_arrays->strings_ptrs, __LINE__);

    data_arrays->strings_sizes = (size_t*) calloc(data_vars->str_nums, sizeof(size_t)); //array of sizes
    memory_fault_error_checker(data_arrays->strings_sizes, __LINE__);

    data_arrays->strings_nums = (size_t*) calloc(data_vars->str_nums ,sizeof(size_t)); //array of string positions
    memory_fault_error_checker(data_arrays->strings_nums, __LINE__);

    data_arrays->running_sum = (size_t*) calloc(data_vars->str_nums, sizeof(size_t));
    memory_fault_error_checker(data_arrays->running_sum, __LINE__);
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


void_sex fill_ptrs_array(const Onegin_Variables data_vars, Onegin_Arrays *data_arrays)
{
    for(size_t i = 0; i < data_vars.symbols_num; i++)
    {
        data_arrays->strings_ptrs[i] = &(data_arrays->my_buffer[data_arrays->running_sum[i]]);
    }
}


void_sex mem_free(Onegin_Arrays *data_arrays)
{
    free(data_arrays->my_buffer);
    free(data_arrays->strings_sizes);
    free(data_arrays->strings_nums);
    free(data_arrays->running_sum);
    free(data_arrays->strings_ptrs);
}

