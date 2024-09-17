#include <stdio.h>
#include <math.h>

#include "../onegin_headers/text_actions.h"
#include "../onegin_headers/output_functions.h"

size_t num_of_str(Onegin_Arrays *data_arrays, size_t file_size)
{
    memory_fault_error_checker(data_arrays->strings_nums, __LINE__);
    size_t counter_str = 0;
    for(size_t index = 0; index < file_size; index++)
    {
        if(data_arrays->my_buffer[index] == '\n')
        {
            data_arrays->my_buffer[index] = '\0';
            counter_str++;
        }
    }
    return counter_str;
}
