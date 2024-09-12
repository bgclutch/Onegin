#include <stdio.h>
#include <inttypes.h>

#include "../onegin_headers/my_swap.h"


void my_swap(void* var_1, void* var_2, unsigned long size)
{
    unsigned long add_bytes = 0;

    uint64_t *ptr_var_long_1 = (uint64_t*)var_1;
    uint64_t *ptr_var_long_2 = (uint64_t*)var_2;

    for(; size >= sizeof(uint64_t); ptr_var_long_1++, ptr_var_long_2++, size -= sizeof(uint64_t), add_bytes += sizeof(uint64_t))
    {
        uint64_t imba = *ptr_var_long_1;
        *ptr_var_long_1 = *ptr_var_long_2;
        *ptr_var_long_2 = imba;
    }

    uint32_t *ptr_var_int_1 = (uint32_t*)(var_1) + add_bytes;
    uint32_t *ptr_var_int_2 = (uint32_t*)(var_2) + add_bytes;

    if(size / sizeof(uint32_t) == 1)
    {
        uint32_t imba = *ptr_var_int_1;
        *ptr_var_int_1 = *ptr_var_int_2;
        *ptr_var_int_2 = imba;
        size %= sizeof(uint32_t);
        add_bytes += sizeof(uint32_t);
    }

    uint16_t *ptr_var_short_1 = (uint16_t*)(var_1) + add_bytes;
    uint16_t *ptr_var_short_2 = (uint16_t*)(var_2) + add_bytes;

    if(size / sizeof(uint16_t) == 1)
    {
        uint16_t imba = *ptr_var_short_1;
        *ptr_var_short_1 = *ptr_var_short_2;
        *ptr_var_short_2 = imba;
        size %= sizeof(uint16_t);
        add_bytes += sizeof(uint16_t);
    }

    uint8_t *ptr_var_char_1 = (uint8_t*)var_1 + add_bytes;
    uint8_t *ptr_var_char_2 = (uint8_t*)var_2 + add_bytes;

    if(size / sizeof(uint8_t) == 1)
    {
        uint8_t imba = *ptr_var_char_1;
        *ptr_var_char_1 = *ptr_var_char_2;
        *ptr_var_char_2 = imba;
        size %= sizeof(uint8_t);
        add_bytes += sizeof(uint8_t);
    }
}