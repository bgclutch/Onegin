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

void_sex bubble_sort(char** array, size_t* string_size, size_t* string_num, size_t arr_size)
{   
    assert(&array[0][0]);
    assert(string_size);
    assert(string_num);

    for(size_t j = 0; j < arr_size; j++) //sort letters by alphabet
    {   
        for(size_t i = 0; i < arr_size - j; i++)
        {
            if(tolower(array[i][0]) > tolower(array[i + 1][0]))
            {
                my_swap(&array[i], &array[i + 1], sizeof(*array)); 
                my_swap(&string_size[i], &string_size[i + 1], sizeof(*string_size)); 
                my_swap(&string_num[i], &string_num[i + 1], sizeof(*string_num));
            }
        }
    }
}



void_sex my_sort(char** array, size_t* string_size, size_t* string_num, size_t arr_size)
{   
    assert(&array[0][0]);
    assert(string_size);
    assert(string_num);
    
    size_t result = 0;

    for(size_t j = 0; j < arr_size - 1; j++) //sort from second letter
    {   
        for(size_t i = 0; i < arr_size - j; i++)
        {
            result = my_string_comparer_from_start(array[i], array[i + 1]);
            if(result == SWAP_STRINGS)
            {
                my_swap(&array[i], &array[i + 1], sizeof(*array)); 
                my_swap(&string_size[i], &string_size[i + 1], sizeof(*string_size)); //CHECK IT!!
                my_swap(&string_num[i], &string_num[i + 1], sizeof(*string_num));
            }
        }
    }
}

void_sex my_sort_end(char** array, size_t* string_size, size_t* string_num, size_t arr_size)
{   
    assert(&array[0][0]);
    assert(string_size);
    assert(string_num);
    
    size_t result = 0;

    for(size_t j = 0; j < arr_size - 1; j++) //sort from second letter
    {   
        for(size_t i = 0; i < arr_size - j; i++)
        {
            result = my_string_comparer_from_end(array[i], array[i + 1]);
            if(result == SWAP_STRINGS)
            {
                my_swap(&array[i], &array[i + 1], sizeof(*array)); 
                my_swap(&string_size[i], &string_size[i + 1], sizeof(*string_size)); //CHECK IT!!
                my_swap(&string_num[i], &string_num[i + 1], sizeof(*string_num));
            }
        }
    }
}

//TODO - my_strcmp(different situations 'aaa' && 'aba'), ignore punctuation marks, spaces, tabs etc, write structcler