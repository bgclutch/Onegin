#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE* sort_data = fopen("hui.txt", "r");
    assert(sort_data && "zalupa");

    fseek(sort_data, 0, SEEK_END);
    size_t symbols_num = (size_t)ftell(sort_data); //num of symbols
    fseek(sort_data, 0, SEEK_SET);

    char* file_arr = (char*) calloc(symbols_num, sizeof(char));
    assert(file_arr && "pidoras");

    fread(file_arr, sizeof(char), symbols_num, sort_data);


    size_t string_num = 0;

    for(size_t i = 0; i < symbols_num; i++)
    {
        if(file_arr[i] == '\n')
            string_num++;
    }                               //num of strings


    char** strings_ptrs = (char**) calloc(string_num, sizeof(char*)); 
    assert(strings_ptrs && "pizda");

    size_t* strings_sizes = (size_t*) calloc(string_num, sizeof(size_t));
    assert(strings_sizes && "pizdec");

    size_t* running_sum_string_sizes = (size_t*) calloc(string_num, sizeof(size_t));
    assert(running_sum_string_sizes && "nu ahuet'");

    size_t* string_nums = (size_t*) calloc(string_num, sizeof(size_t));
    assert(string_nums && "chlen");


    for(size_t ind_str = 0; ind_str < string_num; ind_str++)
    {
        for(size_t ind_symb = 0, string_len = 0; file_arr[ind_symb] != '\n'; ind_symb++)
            string_len++;

        strings_sizes[ind_str] = string_len;
        strings_sizes[ind_str] = ind_str;
    }


    for(size_t index = 0; index < string_num; index++)
    {
        strings_ptrs[index] = (char*) calloc(strings_sizes[index], sizeof(char));
        strings_ptrs[index] = file_arr[strings_sizes[index]]; 
    }







    //передавать массив указателей, массив размеров(???????), размер одного элемента из массива
    //в массиве указателей, функцию сравнения





    if(fclose(sort_data) != 0)
        printf("file cant be closed\n\n");

    return 0;
}


void my_qsort()//принимает в себя кучу аргументов(любых вообще) 
//и в конце концов выводит их упорядоченно в изначально переданный массив итп
{

}