
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../onegin_headers/my_swap.h"
#include "../onegin_headers/bubble_sort.h"
#include "../onegin_headers/my_string_functions.h"
#include "../onegin_headers/text_actions.h"
#include "../onegin_headers/output_functions.h"
#include "../onegin_headers/onegin_structs.h"
#include "../onegin_headers/main_functions.h"


int main(void)
{
    //func with argv
    const char* fonegin_read  = "onegin_first_try.txt";
    const char* fonegin_write = "sorted_onegin.txt";

    FILE* onegin_unsorted_text = fopen(fonegin_read,  "r");
    memory_fault_error_checker(onegin_unsorted_text, __LINE__);

    FILE* onegin_sorted_text = fopen(fonegin_write, "w");
    memory_fault_error_checker(onegin_sorted_text, __LINE__);


    struct Onegin_Arrays data_arrays =
    {
        .strings_ptrs  = nullptr,
        .my_buffer     = nullptr,
        .strings_sizes = nullptr,
        .strings_nums  = nullptr,
        .running_sum   = nullptr
    };

    struct Onegin_Variables data_vars =
    {
        .str_nums    = 0,
        .symbols_num = 0
    };
    
    symbols_number(&data_vars, onegin_unsorted_text);

    symbols_num_check(&data_vars);

    my_buffer_create(&data_arrays, &data_vars, onegin_unsorted_text);

    data_vars.str_nums = num_of_str(&data_arrays, data_vars.symbols_num);

    dynamic_arrays_create(&data_arrays, &data_vars);

    string_nums_and_sizes(data_vars, &data_arrays);

    ptrs_array_fill(data_vars, &data_arrays);

    output_array(data_vars, &data_arrays);

    printf("\n\n");

    bubble_sort(data_arrays.strings_ptrs, data_arrays.strings_sizes, data_arrays.strings_nums, data_vars.str_nums - 1); //my_sort should be here

    output_array(data_vars, &data_arrays);

    printf("\n\n");

    // my_sort(data_arrays.strings_ptrs, data_arrays.strings_sizes, data_arrays.strings_nums, data_vars.str_nums - 1);

    // output_array(data_vars, &data_arrays);

    // printf("\n\n");

    my_sort_end(data_arrays.strings_ptrs, data_arrays.strings_sizes, data_arrays.strings_nums, data_vars.str_nums - 1);

    output_array(data_vars, &data_arrays);

    printf("\n\n");

    fill_sorted_file(&data_arrays, data_vars, onegin_sorted_text);
    
    mem_free(&data_arrays);

    my_file_close(onegin_unsorted_text);
    
    my_file_close(onegin_sorted_text);
    
    return 0;
}


//TODO - // strcmp с конца организовать сортировку (сначала по началу, потом по концу строки) my_sort

