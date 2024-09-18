#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#include "../onegin_headers/my_string_functions.h"
#include "../onegin_headers/onegin_structs.h"

size_t my_strlen(const char* arr)
{
    if(arr == nullptr)
       {
           printf("not enough memory to array, lol\n\n");
           return 0;
       }
    size_t delta = 0;
    while(*(arr + delta) != '\0')
        delta++;

    return delta;
}


size_t my_string_comparer_from_start(const char* str_1, const char* str_2)
{
    size_t len_1 = my_strlen(str_1);
    size_t len_2 = my_strlen(str_2);

    size_t ind_str_1 = 0;
    size_t ind_str_2 = 0;
    size_t result = 0;

    while((ind_str_1 < len_1) && (ind_str_2 < len_2) && (result == CONTINUE_COMPARE))
    {
        while((ind_str_1 < len_1) && !isalpha(str_1[ind_str_1]))
        {
            ind_str_1++;
        }
        while((ind_str_2 < len_2) && !isalpha(str_2[ind_str_2])) 
        {
            ind_str_2++;
        }
        result = compare_result(str_1[ind_str_1], str_2[ind_str_2]);
        ind_str_1++;
        ind_str_2++;
    }
    return result;
}


size_t my_string_comparer_from_end(const char* str_1, const char* str_2)
{
    size_t len_1 = my_strlen(str_1);
    size_t len_2 = my_strlen(str_2);

    size_t ind_str_1 = len_1;
    size_t ind_str_2 = len_2;
    size_t result = 0;

    while((ind_str_1 > 0) && (ind_str_2 > 0) && (result == CONTINUE_COMPARE))
    {
        while((ind_str_1 > 0) && !isalpha(str_1[ind_str_1]))
        {
            ind_str_1--;
        }
        while((ind_str_2 > 0) && !isalpha(str_2[ind_str_2])) 
        {
            ind_str_2--;
        }
        result = compare_result(str_1[ind_str_1], str_2[ind_str_2]);
        ind_str_1--;
        ind_str_2--;
    }
    return result;
}


enum CompareResults compare_result(char symb_1, char symb_2)
{
    enum CompareResults comp_res = CONTINUE_COMPARE;
    if(toupper(symb_1) > toupper(symb_2))
        {
            comp_res = SWAP_STRINGS;
        }
    else if(toupper(symb_1) < toupper(symb_2))
        {
            comp_res = NOT_SWAP_STRINGS;
        }
    else if(toupper(symb_1) == toupper(symb_2))
        {
            comp_res = CONTINUE_COMPARE;
        } 
    return comp_res;
}

