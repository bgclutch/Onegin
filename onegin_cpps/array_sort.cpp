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


size_t my_strlen(const char* arr)
{
    assert(arr && "my_strlen err"); 
    size_t delta = 0;
    while(*(arr + delta) != '\0')
        delta++;

    return delta;
}


void_sex my_sort(Onegin_General_Data *onegin_array, size_t left, size_t right, void* comparers, size_t index)
{       
    int result = 0;
    for(size_t j = left; j < right - 1; j++) 
    {   
        for(size_t i = left; i < right - j - 1; i++)
        {
            result = comparers[index](onegin_array[i].string_ptr,  onegin_array[i + 1].string_ptr,
                              onegin_array[i].string_size, onegin_array[i + 1].string_size);
            if(result > 0)
            {
                struct_swap(&onegin_array[i], &onegin_array[i + 1]);
            }
        }
    }
}

// void_sex my_sort_end(Onegin_General_Data *onegin_array, const size_t left, const size_t right, void* comparer)
// {   
//     int result = 0;
//     for(size_t j = left; j < right - 1; j++) 
//     {   
//         for(size_t i = left; i < right - j - 1; i++)
//         {
//             result = comparer(onegin_array[i].string_ptr,  onegin_array[i + 1].string_ptr,
//                                                  onegin_array[i].string_size, onegin_array[i + 1].string_size);
//             if(result > 0)
//             {
//                 struct_swap(&onegin_array[i], &onegin_array[i + 1]); 
//             }
//         }
//     }
// }


int my_string_comparer_from_start(const char* str_1, const char* str_2, size_t len_1, size_t len_2)
{
    size_t ind_str_1 = 0;
    size_t ind_str_2 = 0;
    int result = 0;

    while((ind_str_1 < len_1) && !isalpha(str_1[ind_str_1]))
    {
        ind_str_1++;
    }
    while((ind_str_2 < len_2) && !isalpha(str_2[ind_str_2])) 
    {
        ind_str_2++;
    }

    while(ind_str_1 < len_1 && ind_str_2 < len_2 && result == 0)
    {
        result = toupper(str_1[ind_str_1]) - toupper(str_2[ind_str_2]);
        //printf("first letter " BLUE_TEXT("%c ") "second letter " BLUE_TEXT("%c\n\n"), str_1[ind_str_1], str_2[ind_str_2]);
        ind_str_1++;
        ind_str_2++;
    }
    return result;
}


int my_string_comparer_from_end(const char* str_1, const char* str_2, size_t len_1, size_t len_2)
{
    long ind_str_1 = (long)len_1 - 1; 
    long ind_str_2 = (long)len_2 - 1;

    int result = 0;

    while((ind_str_1 >= 0) && !isalpha(str_1[ind_str_1]))
    {
        ind_str_1--;
    }
    while((ind_str_2 >= 0) && !isalpha(str_2[ind_str_2])) 
    {
        ind_str_2--;
    }

    while(ind_str_1 >= 0 && ind_str_2 >= 0 && result == 0)
    {
        result = toupper(str_1[ind_str_1]) - toupper(str_2[ind_str_2]);
        //printf("first letter " BLUE_TEXT("%c ") "second letter " BLUE_TEXT("%c\n\n"), str_1[ind_str_1], str_2[ind_str_2]);
        ind_str_1--;
        ind_str_2--;
    }
    
    return result;
}


void_sex sort_arrays(Onegin_Variables *data_vars, Onegin_General_Data *onegin_array, void* comparers)
{
    printf("\n\n"
            "unsorted\n\n");

    output_array(onegin_array, data_vars->str_nums);

    printf("\n\n"
           "sorted from the start bubble\n\n");

    my_sort(onegin_array, 0, data_vars->str_nums, comparers, 0);//FIXME enum!!

    output_array(onegin_array, data_vars->str_nums);

    printf("\n\n"
            "sorted from the end\n\n");

    my_sort(onegin_array, 0, data_vars->str_nums, comparers, 1);//FIXME enum!!

    output_array(onegin_array, data_vars->str_nums);
}


// void_sex my_qsort(Onegin_Arrays *data_arrays, size_t type_size, size_t left, size_t right)//main struct && comparer
// {
//     size_t left_index = left;
//     size_t right_index = right - 1;

//     size_t pivot_index = (left + right) / 2;

//     if(right - left <= 1)
//     {
//         return;
//     }
//     // else if()
//     // {

//     // }
//     else
//     {
//         fprintf(stderr, YELLOW_TEXT("pivot string %s\n\n"), data_arrays->strings_ptrs[pivot_index]);
//         while(left_index < right && right_index > left)
//         {
//             while(my_string_comparer_from_start(data_arrays->strings_ptrs[left_index], data_arrays->strings_ptrs[pivot_index], 
//                         data_arrays->strings_sizes[left_index], data_arrays->strings_sizes[pivot_index]) <= 0 && left_index < pivot_index)//comp
//             {
//                 fprintf(stderr, RED_TEXT("skipped left string %s\n\n"), data_arrays->strings_ptrs[left_index]);
//                 left_index++;
//             }  

//             while(my_string_comparer_from_start(data_arrays->strings_ptrs[right_index], data_arrays->strings_ptrs[pivot_index], 
//                     data_arrays->strings_sizes[right_index], data_arrays->strings_sizes[pivot_index]) > 0 && right_index > pivot_index)
//             {
//                 fprintf(stderr, RED_TEXT("skipped right string %s\n\n"), data_arrays->strings_ptrs[right_index]);
//                 right_index--;
//             }

//             printf("text b4 swap\n");
//             my_swap(&data_arrays->strings_ptrs [left_index], &data_arrays->strings_ptrs [right_index], sizeof(*data_arrays->strings_ptrs)); 
//             my_swap(&data_arrays->strings_sizes[left_index], &data_arrays->strings_sizes[right_index], sizeof(*data_arrays->strings_sizes)); 
//             my_swap(&data_arrays->strings_nums [left_index], &data_arrays->strings_nums [right_index], sizeof(*data_arrays->strings_nums));
//             left_index++;
//             right_index--;

//             for(size_t i = left; i < right; i++)
//             {
//                 fprintf(stderr, "%s\n", data_arrays->strings_ptrs[i]);
//             }
//             fprintf(stderr, "right index %lu\n\n", right_index);
//         }
//         my_qsort(data_arrays, type_size, left, right_index - 1);
//         my_qsort(data_arrays, type_size, right_index - 1, right);
//     }
// }

