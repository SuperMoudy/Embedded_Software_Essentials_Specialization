/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves contents from source to destination. 
 * 
 * Given a pointer to an array of bytes, this will move a number 
 * of bytes given by the length provided to a destination array 
 * and it may be the same array but a different position. So, 
 * overlapping must be handled so that the overlapped data 
 * (to be copied later) must not be lost.
 * 
 * @param src Pointer to source array
 * @param dst Pointer to destination array
 * @param length Number of bytes to be moved
 * 
 * @return Pointer to destination array
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies contents from source to destination. 
 * 
 * Given a pointer to an array of bytes, this will copy a number 
 * of bytes given by the length provided to a destination array 
 * but one should take care if both arrays are the same as 
 * overlapping of positions is undefined and may lead to 
 * corruption of data. 
 * 
 * @param src Pointer to source array
 * @param dst Pointer to destination array
 * @param length Number of bytes to be copied
 * 
 * @return Pointer to destination array
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets array of bytes to a value.
 * 
 * Given a pointer to an array of bytes, this will set a number 
 * of bytes given by the length provided to a specific value.
 * 
 * @param src Pointer to source array
 * @param length Number of bytes to be set
 * @param value Value to be assigned to bytes locations
 * 
 * @return Pointer to source array
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Clears array of bytes.
 * 
 * Given a pointer to an array of bytes, this will clear a number  
 * of bytes given by the length provided.
 * 
 * @param src Pointer to source array
 * @param length Number of bytes to be cleared
 * 
 * @return Pointer to source array
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses array of bytes.
 * 
 * Given a pointer to an array of bytes, this will reverse the order 
 * of a number of bytes given by the 
 * length provided.
 * 
 * @param src Pointer to source array
 * @param length Number of bytes whose order to be reversed
 * 
 * @return Pointer to source array
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates words dynamically.
 * 
 * This will dynamically allocates a number of words given by 
 * the length provided.
 * 
 * @param length Number of words to be allocated (if available)
 * 
 * @return Pointer to memory if successful, or a Null pointer otherwise
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees dynamically allocated words
 * 
 * Given a pointer to a dynamically allocated memory of words, 
 * this will free this memory so that it can be reused.
 * 
 * @param src Pointer to dynamic source array
 * 
 * @return void
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
