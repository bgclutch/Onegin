#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/array_to_file_translation.h"

size_t symbols_number(Onegin_Files_Attributes *data_files)
{
    assert(data_files->file_read);
    fseek(data_files->file_read, 0, SEEK_END); 
    size_t result = (size_t)ftell(data_files->file_read);
    fseek(data_files->file_read, 0, SEEK_SET);

    return result;
}


void_sex symbols_num_check(const size_t symbols_num)
{
    if(symbols_num == 0)      
    {
        printf("fill your file better, lol\n\n"); 
    }
}


void_sex my_buffer_create(Onegin_Variables *data_vars, size_t symbols_num, FILE* file_name)
{
    data_vars->my_buffer = (char*) calloc(symbols_num + 1, sizeof(char));
    memory_fault_error_checker(data_vars->my_buffer, "my_buffer", "my_buffer_create");

    fread(data_vars->my_buffer, sizeof(char), symbols_num, file_name);
    data_vars->my_buffer[symbols_num] = '\0';
}


size_t num_of_str(char* my_buffer, const size_t symbols_num)
{
    assert(my_buffer && "norm");

    size_t counter_str = 0;
    for(size_t index = 0; index < symbols_num; index++)
    {
        if(my_buffer[index] == '\n')
        {
            my_buffer[index] = '\0';
            counter_str++;
        }
    }
    return counter_str;
}


void_sex string_nums_and_sizes(Onegin_Variables *data_vars, Onegin_General_Data *onegin_array)
{    
    size_t index = 0;
    for(size_t str_n = 0; str_n < data_vars->str_nums; str_n++)
    {
        size_t counter = 0;

        while(data_vars->my_buffer[index] != '\0' && index < data_vars->symbols_num)//1 strings counter 2 buffer checker
        {
            counter++;
            index++;
        }
        counter++;
        index++;
        onegin_array[str_n].string_num  = str_n;
        onegin_array[str_n].string_size = counter;

        counter = 0;
    }
}

void_sex count_prefix_sum(const Onegin_Variables data_vars, Onegin_General_Data *onegin_array)
{
    onegin_array[0].prefix_sum = 0;
    for(size_t str_n = 1; str_n < data_vars.str_nums; str_n++)
    {
        onegin_array[str_n].prefix_sum = onegin_array[str_n - 1].prefix_sum + onegin_array[str_n - 1].string_size; 
    }
}


void_sex ptrs_array_fill(const Onegin_Variables data_vars, Onegin_General_Data *onegin_array, const char* my_buffer)
{
    for(size_t i = 0; i < data_vars.str_nums; i++)
    {
        onegin_array[i].string_ptr = &(my_buffer[onegin_array[i].prefix_sum]);
    }
}


void_sex fill_sorted_file(Onegin_General_Data *onegin_array, const Onegin_Variables data_vars, Onegin_Files_Attributes *data_files)
{
    for(size_t index = 0; index < data_vars.str_nums; index++)
    {
        fputs(onegin_array[index].string_ptr, data_files->file_write);
        putc('\n', data_files->file_write);
    }

}

void_sex complete_array_of_ptrs(Onegin_General_Data *onegin_array, Onegin_Variables *data_vars)
{
    string_nums_and_sizes(data_vars, onegin_array);

    count_prefix_sum(*data_vars, onegin_array);

    ptrs_array_fill(*data_vars, onegin_array, data_vars->my_buffer);
}


void_sex mem_free(Onegin_General_Data *onegin_array, char* my_buffer)
{
    free(onegin_array);
    free(my_buffer);
} 

