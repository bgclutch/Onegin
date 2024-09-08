#include <stdio.h>
#include <assert.h>
#include <ctype.h>


int main(void)
{
    const char* fonegin_read  = "onegin_first_try.txt";
    //const char* fonegin_write = "sorted_onegin.txt";

    const int rows = 14;
    const int cols = 80;

    char onegin_array[rows][cols] = {0, 0};

    FILE* onegin_unsorted_text = fopen(fonegin_read,  "r");
    //FILE* onegin_sorted_text   = fopen(fonegin_write, "w");

    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++) //cutted array
        {
            int g_char = 0;
            g_char = getc(onegin_unsorted_text);
            {
                onegin_array[i][j] = (char)g_char;
            }
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(isprint(onegin_array[i][j]) || iscntrl(onegin_array[i][j]))
                printf("%c", onegin_array[i][j]);
        }
    }

    printf("\n\n\n");

    char prac[] = {'f', 'a', 'Z', 'd', 'B', 'n'};

     for(int i = 0; i < (int)(sizeof(prac) / sizeof(char)); i++)
    {
        if(isprint(prac[i]) || iscntrl(prac[i]))
            printf("%c", prac[i]);
    }

    printf("\n\n\n");

    int counter = 0;
    int size = (int)(sizeof(prac) / sizeof(char));

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(tolower(prac[j]) > tolower(prac[j + 1]))
            {
                char swapper = prac[j];
                prac[j] = prac[j + 1];
                prac[j + 1] = swapper;
            }
            counter++;
        }
    }

    for(int i = 0; i < (int)(sizeof(prac) / sizeof(char)); i++)
    {
        if(isprint(prac[i]) || iscntrl(prac[i]))
            printf("%c", prac[i]);
    }

    printf("\n\n %d \n\n", counter);

    if(fclose(onegin_unsorted_text))
        printf("error in fclose read\n\n");
    
    // if(fclose(onegin_sorted_text))
    //     printf("error in fclose write\n\n");

    return 0;
}