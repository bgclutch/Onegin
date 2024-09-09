
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
    const char* fonegin_read  = "onegin_first_try.txt";
    //const char* fonegin_write = "sorted_onegin.txt";


    FILE* onegin_unsorted_text = fopen(fonegin_read,  "r");
    assert(onegin_unsorted_text && "file open err");

    //FILE* onegin_sorted_text   = fopen(fonegin_write, "w");
    //assert(onegin_sorted_text && "file open err");

    
    // for(int i = 0; i < rows; i++) //sort
    // {
    //     for(int j = 0; j < cols; j++) //cutted array
    //     {
    //         int g_char = 0;
    //         g_char = getc(onegin_unsorted_text);
    //         {
    //             onegin_array[i][j] = (char)g_char;
    //         }
    //     }
    // }

    size_t str_nums = 14;

    char** arr_of_ptrs = (char**) calloc(str_nums, sizeof(char*)); //array of pointers to strings
    assert(arr_of_ptrs && "pizda");

    size_t* arr_of_sizes = (size_t*) calloc(str_nums, sizeof(size_t)); //array of sizes
    assert(arr_of_sizes && "penis");

    size_t str_size = 0;
    //char* string_pointer;

    for(size_t i = 0; i < str_nums; i++)
    {
        if(getline(&(arr_of_ptrs[(int)i]), &str_size, onegin_unsorted_text) != EOF)
        {
            *(arr_of_sizes + i) = str_size;

            //*(arr_of_ptrs + i) = string_pointer;

            // printf("%p\n", arr_of_ptrs);

            // puts(arr_of_ptrs[i]); 
    }
    }

    printf("\n\n\n\n");

    for(size_t i = 0; i < str_nums; i++)
    {
        printf("%p\n", arr_of_ptrs + i);
        puts(arr_of_ptrs[i]);
    }

    for(size_t i = 0; i < str_nums; i++)
    {
        free(*(arr_of_ptrs + i));
    }

    free(arr_of_ptrs);
    free(arr_of_sizes);

    if(fclose(onegin_unsorted_text))
        printf("error in fclose read\n\n");
    
    // if(fclose(onegin_sorted_text))
    // printf("error in fclose write\n\n");

    return 0;
}

//TODO - //ебатория наебывает. пофиксить копирование последней строки в залупку, надо в разные. стркмп с конца спиздить свой свап организовать сортировку

