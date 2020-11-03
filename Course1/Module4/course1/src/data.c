/******************************************************************************
 * Copyright (C) 2020 by Mahmoud Hamdy
 * 
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Mahmoud Hamdy is not liable for any misuse of this material.
 * 
 *****************************************************************************/

#include "data.h"
#include "memory.h"
#include <ctype.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    if((base < 2) || (base > 16))
    {
        return 0;
    }

    if(data == 0)
    {
        *ptr = '0';
        *(ptr + 1) = '\0';
        return 2;
    }
    
    // Numbers array
    uint8_t *numbers = (uint8_t *)"0123456789ABCDEF";
    
    // Length of the digits array
    uint8_t length = 0;

    // Testing whether to add a negative sign
    if(data < 0)
    {
        *ptr = '-';
        length++;
        data = 0 - data;
    }

    while(data)
    {
        *(ptr + length) = numbers[data % base];
        length++;
        data /= base;
    }

    // Reversing results (null character not included)
    //ptr -= length;
    if(*ptr == '-')
    {
        my_reverse(ptr + 1, length - 1);
    }
    else
    {
        my_reverse(ptr, length);
    }
    
    *(ptr + length) = '\0'; // null-terminated array now

    // include null in array length as specified
    return length + 1;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    if(!ptr)
    {
        return 0;
    }

    int32_t data = 0, place = 1;
    uint8_t neg_flag = 0;

    while(isspace(*ptr))
    {
        ptr++;
        digits--;
    }

    if(*ptr == '-')
    {
        neg_flag = 1;
        ptr++;
        digits -= 2; // Excluding Minus and Null characters
    }
    else
    {
        digits -= 1; // Excluding Null character
    }
    

    // starting from position zero
    ptr += (digits - 1);

    // Validate data before conversion
    if((*ptr < '0') || ((*ptr > '9') && (*ptr < 'A')) || (*ptr > 'F'))
    {
        return 0;
    }

    while(digits > 0)
    {
        if((*ptr >= '0') && (*ptr <= '9'))
        {
            data += ((*ptr) - '0') * place;
        }
        else if((*ptr >= 'A') && (*ptr <= 'F'))
        {
            data += ((*ptr) - 'A' + 10) * place;
        }
        else
        {
            return data;
        }
        
        place *= base;
        ptr--;
        digits--;
    }

    return (neg_flag > 0 ? -data : data);
}

