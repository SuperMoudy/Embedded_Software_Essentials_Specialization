/******************************************************************************
 * Copyright (C) 2020 by Mahmoud Hamdy
 * 
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Mahmoud Hamdy is not liable for any misuse of this material.
 * 
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Mahmoud Hamdy
 * @date October 3 2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Convert data from Integer to ASCII string
 * 
 * Given a 32-bit signed integer, this function will convert it 
 * to an Ascii string according to the required base given.
 * The base is assumed to be from 2 to 16.
 * 
 * @param data integer to be converted
 * @param ptr pointer to converted array
 * @param base base of the number system used in conversion
 * 
 * @return length of the converted array
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Convert data from ASCII string to Integer
 * 
 * Given a pointer to array of numbers represented as a single 
 * value, this function will convert it to a single 32-bit 
 * signed integer according to the required base.
 * The base is assumed to be from 2 to 16.
 * 
 * @param ptr pointer to array to be converted
 * @param digits number of digits in the array
 * @param base base of the number system used in conversion
 * 
 * @return converted 32-bit number
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */