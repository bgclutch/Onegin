#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../onegin_headers/array_sort.h"
#include "../onegin_headers/my_swap.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/onegin_structs.h"

//typedef; 

void_sex my_sort(Onegin_Arrays *data_arrays, const Onegin_Variables data_vars)
{       
    int result = 0;
    for(size_t j = 0; j < data_vars.str_nums - 1; j++) 
    {   
        for(size_t i = 0; i < data_vars.str_nums - j - 1; i++)
        {
            result = my_string_comparer_from_start(data_arrays->strings_ptrs[i], data_arrays->strings_ptrs[i + 1],
                                                   data_arrays->strings_sizes[i], data_arrays->strings_sizes[i + 1]);
            if(result > 0)
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
    int result = 0;
    for(size_t j = 0; j < data_vars.str_nums - 1; j++) 
    {   
        for(size_t i = 0; i < data_vars.str_nums - j - 1; i++)
        {
            result = my_string_comparer_from_end(data_arrays->strings_ptrs[i], data_arrays->strings_ptrs[i + 1],
                                                 data_arrays->strings_sizes[i], data_arrays->strings_sizes[i + 1]);
            if(result > 0)
            {
                my_swap(&data_arrays->strings_ptrs[i], &data_arrays->strings_ptrs[i + 1], sizeof(*data_arrays->strings_ptrs)); 
                my_swap(&data_arrays->strings_sizes[i], &data_arrays->strings_sizes[i + 1], sizeof(*data_arrays->strings_sizes)); 
                my_swap(&data_arrays->strings_nums[i], &data_arrays->strings_nums[i + 1], sizeof(*data_arrays->strings_nums));
            }
        }
    }
}


int my_string_comparer_from_start(const char* str_1, const char* str_2, size_t len_1, size_t len_2)
{
    size_t ind_str_1 = 0;
    size_t ind_str_2 = 0;
    int result = 0;

    while((ind_str_1 < len_1) && (ind_str_2 < len_2) && (result == 0))
    {
        while((ind_str_1 < len_1) && !isalpha(str_1[ind_str_1]))
        {
            ind_str_1++;
        }
        while((ind_str_2 < len_2) && !isalpha(str_2[ind_str_2])) 
        {
            ind_str_2++;
        }
        if(ind_str_1 < len_1 && ind_str_2 < len_2)
        {
            result = toupper(str_1[ind_str_1]) - toupper(str_2[ind_str_2]);
            ind_str_1++;
            ind_str_2++;
        }
    }
    return result;
}


int my_string_comparer_from_end(const char* str_1, const char* str_2, size_t len_1, size_t len_2)
{
    int ind_str_1 = (int)len_1 - 1;
    int ind_str_2 = (int)len_2 - 1;
    int result = 0;

    while((ind_str_1 >= 0) && (ind_str_2 >= 0) && (result == 0))
    {
        while((ind_str_1 >= 0) && !isalpha(str_1[ind_str_1]))
        {
            ind_str_1--;
        }
        while((ind_str_2 >= 0) && !isalpha(str_2[ind_str_2])) 
        {
            ind_str_2--;
        }
        if(ind_str_1 >= 0 && ind_str_2 >= 0)
        {
            result = toupper(str_1[ind_str_1]) - toupper(str_2[ind_str_2]);
            ind_str_1--;
            ind_str_2--;
        }
    }
    return result;
}


void_sex sort_arrays(Onegin_Variables data_vars, Onegin_Arrays *data_arrays)
{
    printf("\n\n"
            "unsorted\n\n");

    output_array(data_vars, data_arrays);

    printf("\n\n"
           "sorted from the start\n\n");

    my_sort(data_arrays, data_vars);

    output_array(data_vars, data_arrays);

     printf("\n\n"
            "sorted from the end\n\n");

    my_sort_end(data_arrays, data_vars);

    output_array(data_vars, data_arrays);
}