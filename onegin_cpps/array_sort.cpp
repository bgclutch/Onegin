#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
            printf("first letter " BLUE_TEXT("%c ") "second letter " BLUE_TEXT("%c\n\n"), str_1[ind_str_1], str_2[ind_str_2]);
            ind_str_1++;
            ind_str_2++;
        }
    }
    return result;
}


int my_string_comparer_from_end(const char* str_1, const char* str_2, size_t len_1, size_t len_2)
{
    int ind_str_1 = (int)len_1 - 1; //int here is good?
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
            printf("first letter " BLUE_TEXT("%c ") "second letter " BLUE_TEXT("%c\n\n"), str_1[ind_str_1], str_2[ind_str_2]);
            ind_str_1--;
            ind_str_2--;
        }
    }
    return result;
}


void_sex sort_arrays(Onegin_Variables *data_vars, Onegin_Arrays *data_arrays)
{
    printf("\n\n"
            "unsorted\n\n");

    output_array(*data_vars, data_arrays);

    printf("\n\n"
           "sorted from the start bubble\n\n");

    my_sort(data_arrays, *data_vars);

    output_array(*data_vars, data_arrays);

    printf("\n\n"
            "sorted from the end\n\n");

    my_sort_end(data_arrays, *data_vars);

    output_array(*data_vars, data_arrays);
}


void_sex my_qsort(Onegin_Arrays *data_arrays, size_t type_size, size_t left, size_t right)//main struct && comparer
{
    if(right - left >= 1)
    {
        size_t pivot = right - 1; //FIXME ASSERTS
        int result = 0;

        size_t index_finder  = left;
        size_t index_swapper = left;
        
        for(size_t index_left = left; index_left <= pivot; index_left++)
        {
            fprintf(stderr, "iteration %lu\n"
                    "pivot %lu\n"
                    "left index " BLUE_TEXT("%lu\t") "right index " BLUE_TEXT("%lu\n")
                    "index_finder " GREEN_TEXT("%lu\t") "index_swapper " GREEN_TEXT("%lu\n\n"), index_left,
                     pivot, index_left, right, index_finder, index_swapper);

            for(size_t i = 0; i < right; i++)
            {
                if(i < index_left)
                {
                    fprintf(stderr, GREEN_TEXT("\tstring ") RED_TEXT("%lu\n") GREEN_TEXT("%s\n"), i, data_arrays->strings_ptrs[i]);
                }
                else if(i == index_left)
                {
                    fprintf(stderr, RED_TEXT("\tstring ") YELLOW_TEXT("%lu\n") RED_TEXT("%s\n"), i, data_arrays->strings_ptrs[i]);
                }
                else if(i > index_left)
                {
                    fprintf(stderr, BLUE_TEXT("\tstring ") RED_TEXT("%lu\n") BLUE_TEXT("%s\n"), i, data_arrays->strings_ptrs[i]);
                }
            }

            if(index_left != pivot)
            {
                result = my_string_comparer_from_start(data_arrays->strings_ptrs[index_left], data_arrays->strings_ptrs[pivot], 
                                                       data_arrays->strings_sizes[index_left], data_arrays->strings_sizes[pivot]);
                printf("compare result " GREEN_TEXT("%d ") "in " BLUE_TEXT("%lu iteration\n\n"), result, index_left);
            }
            if(result > 0) //>=?
            {
                fprintf(stderr, YELLOW_TEXT("index finder b4 increment %lu\n"), index_finder);
                index_finder++;
                fprintf(stderr, YELLOW_TEXT("index finder after increment %lu\n\n"), index_finder);
            }
            if(result <= 0) //<?
            {
                if(index_finder > index_swapper)
                {
                    printf(BLUE_TEXT("TEXT B4 SWAPS\n\n\n"));
                    //fprintf(stderr, YELLOW_TEXT("left string "   ) RED_TEXT("index %lu\n") YELLOW_TEXT("%s\n"),     index_left, data_arrays->strings_ptrs[index_left]);
                    fprintf(stderr, YELLOW_TEXT("string finder " ) RED_TEXT("index %lu\n") YELLOW_TEXT("%s\n"),     index_finder, data_arrays->strings_ptrs[index_finder]);
                    fprintf(stderr, YELLOW_TEXT("string swapper ") RED_TEXT("index %lu\n") YELLOW_TEXT("%s\n\n\n"), index_swapper, data_arrays->strings_ptrs[index_swapper]);

                    my_swap(&data_arrays->strings_ptrs [index_finder], &data_arrays->strings_ptrs [index_swapper], sizeof(*data_arrays->strings_ptrs)); 
                    my_swap(&data_arrays->strings_sizes[index_finder], &data_arrays->strings_sizes[index_swapper], sizeof(*data_arrays->strings_sizes)); 
                    my_swap(&data_arrays->strings_nums [index_finder], &data_arrays->strings_nums [index_swapper], sizeof(*data_arrays->strings_nums));
                    index_swapper++;
                    index_finder++;
                    fprintf(stderr, "index swapper %lu  index finder %lu\n\n", index_swapper, index_finder);
                }
            }
        }      
        fprintf(stderr, YELLOW_TEXT("TEXT BEFORE LEFT SIDE SORT\n") RED_TEXT("left %lu   index swapper %lu  right %lu\n\n"), left, index_swapper, right);
        my_qsort(data_arrays, type_size, left, index_swapper);//left side
        fprintf(stderr, YELLOW_TEXT("TEXT BEFORE RIGHT SIDE SORT\n"));
        my_qsort(data_arrays, type_size, index_swapper + 1, right);//right side
    }
    else
    {
        fprintf(stderr, "huynya peredelyvay     left %lu right %lu\n\n", left, right);
    }   
        
}