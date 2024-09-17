#include <stdio.h>
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
