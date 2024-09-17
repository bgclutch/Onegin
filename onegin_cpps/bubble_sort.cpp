#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../onegin_headers/bubble_sort.h"
#include "../onegin_headers/my_swap.h"
#include "../onegin_headers/output_functions.h"

void bubble_sort(char** array, size_t* string_size, size_t* string_num, size_t arr_size)
{   
    assert(&array[0][0]);
    assert(string_size);
    assert(string_num);
    for(size_t j = 0; j < arr_size; j++)
    {   
        for(size_t i = 0; i < arr_size - j; i++)
        {
            if(toupper(array[i][0]) > toupper(array[i + 1][0])) //strcmp here
            {
                my_swap(&array[i], &array[i + 1], sizeof(*array)); 
                my_swap(&string_size[i], &string_size[i + 1], sizeof(*string_size)); //CHECK IT!!
                my_swap(&string_num[i], &string_num[i + 1], sizeof(*string_num));
            }
        }
    }
}

//TODO - my_strcmp(different situations 'aaa' && 'aba'), ignore punctuation marks, spaces, tabs etc, write struct