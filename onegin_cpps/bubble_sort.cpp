#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../onegin_headers/bubble_sort.h"
#include "../onegin_headers/my_swap.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/my_string_functions.h"
#include "../onegin_headers/onegin_structs.h"

//typedef; 

void_sex my_sort(Onegin_Arrays *data_arrays, const Onegin_Variables data_vars)
{       
    size_t result = 0;

    for(size_t j = 0; j < data_vars.str_nums - 1; j++) //sort from second letter
    {   
        for(size_t i = 0; i < data_vars.str_nums - j - 1; i++)
        {
            result = my_string_comparer_from_start(data_arrays->strings_ptrs[i], data_arrays->strings_ptrs[i + 1]);
            if(result == SWAP_STRINGS)
            {
                my_swap(&data_arrays->strings_ptrs[i], &data_arrays->strings_ptrs[i + 1], sizeof(*data_arrays->strings_ptrs)); 
                my_swap(&data_arrays->strings_sizes[i], &data_arrays->strings_sizes[i + 1], sizeof(*data_arrays->strings_sizes)); 
                my_swap(&data_arrays->strings_nums[i], &data_arrays->strings_nums[i + 1], sizeof(*data_arrays->strings_nums));
            }
        }
    }
}

void_sex my_sort_end(Onegin_Arrays *data_arrays, const Onegin_Variables data_vars)
{   
    size_t result = 0;

    for(size_t j = 0; j < data_vars.str_nums - 1; j++) //sort from second letter
    {   
        for(size_t i = 0; i < data_vars.str_nums - j - 1; i++)
        {
            result = my_string_comparer_from_end(data_arrays->strings_ptrs[i], data_arrays->strings_ptrs[i + 1]);
            if(result == SWAP_STRINGS)
            {
                my_swap(&data_arrays->strings_ptrs[i], &data_arrays->strings_ptrs[i + 1], sizeof(*data_arrays->strings_ptrs)); 
                my_swap(&data_arrays->strings_sizes[i], &data_arrays->strings_sizes[i + 1], sizeof(*data_arrays->strings_sizes)); 
                my_swap(&data_arrays->strings_nums[i], &data_arrays->strings_nums[i + 1], sizeof(*data_arrays->strings_nums));
            }
        }
    }
}

//TODO - my_strcmp(different situations 'aaa' && 'aba'), ignore punctuation marks, spaces, tabs etc, write structcler