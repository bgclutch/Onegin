
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../onegin_headers/my_swap.h"
#include "../onegin_headers/bubble_sort.h"
#include "../onegin_headers/my_string_functions.h"

size_t num_of_str(char* array);

int main(void)
{
    const char* fonegin_read  = "onegin_first_try.txt";
    const char* fonegin_write = "sorted_onegin.txt";


    FILE* onegin_unsorted_text = fopen(fonegin_read,  "r");
        if(onegin_unsorted_text == nullptr)
        {
            printf("try again open read file, lol\n\n");
            return 0;
        }

    FILE* onegin_sorted_text   = fopen(fonegin_write, "w");
    if(onegin_sorted_text == nullptr)
        {
            printf("try again write file, lol\n\n");
            return 0;
        }


    fseek(onegin_unsorted_text, 0, SEEK_END);
    size_t symbols_num = (size_t)ftell(onegin_unsorted_text);
    fseek(onegin_unsorted_text, 0, SEEK_SET);

    if(symbols_num == 0)
        {
            printf("fill your file better, lol\n\n");
            return 0;
        }

    char* my_buffer = (char*) calloc(symbols_num, sizeof(char));

    fread(my_buffer, sizeof(char), symbols_num, file);





    size_t str_nums = num_of_str(my_buffer);

    //fwrite(my_buffer, sizeof(char), symbols_num, onegin_sorted_text);

    //FUNC!
    char** strings_ptrs = (char**) calloc(str_nums, sizeof(char*)); //array of pointers to strings
    if(strings_ptrs == nullptr)
        {
            printf("not enough memory to calloc strings_ptrs, lol\n\n");
            return 0;
        }

    size_t* strings_sizes = (size_t*) calloc(str_nums, sizeof(size_t)); //array of sizes
     if(strings_sizes == nullptr)
        {
            printf("not enough memory to calloc strings_sizes, lol\n\n");
            return 0;
        }

    size_t* strings_nums = (size_t*) calloc(str_nums ,sizeof(size_t)); //array of string positions
    if(strings_ptrs == nullptr)
        {
            printf("not enough memory to calloc string_nums, lol\n\n");
            return 0;
        }




    int counter = 0;
    for(size_t i = 0; i < str_nums; i++)
    {
        for(size_t j = 0; my_buffer[i][j] != '\n'; j++)
        {
            counter++;
        }
        strings_sizes[i] = counter;
        strings_nums[i] = i;
        counter = 0;
    }


    for(size_t i = 0; i < str_nums; i++)
    {
        char* &strings_ptrs[i] = (char*) calloc(strings_sizes[i], sizeof(char));
        strings_ptrs[i] = gets_s(my_buffer, strings_sizes[i]);
    }



    printf("\n\n");

    for(size_t i = 0; i < str_nums; i++)
    {
        puts(strings_ptrs[i]);
    }

    printf("\n\n\n");

    bubble_sort(strings_ptrs, strings_sizes, strings_nums, str_nums - 1);


    for(size_t i = 0; i < str_nums; i++)
    {
        puts(strings_ptrs[i]);
    }


    for(size_t i = 0; i < str_nums; i++)
    {
        free(*(strings_ptrs + i));
    }

    free(strings_ptrs);
    free(strings_sizes);
    free(strings_nums);

    free(my_buffer);

    printf("\n\n");

    if(fclose(onegin_unsorted_text))
        printf("error in fclose read\n\n");
    
    if(fclose(onegin_sorted_text))
        printf("error in fclose write\n\n");

    return 0;
}




size_t num_of_str(char* array)
{
    size_t index = 0;
    size_t counter = 0;
    while(array[index] != EOF)
    {
        if(array[index] == '\n')
        {
            counter++;
        }
        index++;
    }
    return counter;
}

//TODO - // стркмп edit с конца организовать сортировку (сначала по началу, потом по концу строки)

