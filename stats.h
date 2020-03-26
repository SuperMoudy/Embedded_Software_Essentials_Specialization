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
 * @file stats.h 
 * @brief Function Prototypes used in the statistical analysis
 *
 * This file contains the function prototypes that we used
 * in our statistical analysis software so that we can 
 * include them all at once using the include directive to.
 *
 * @author Mahmoud Hamdy
 * @date Mar 26, 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Print the statistical values of the array
 *
 * This function takes as an input an array of 
 * unsigned characters and an unsigned integer 
 * representing its length. It process this array, 
 * finds its maximum, minimum, median, and mean 
 * value, and print them all.
 *
 * @param arr Array of unsigned characters
 * @param size The length of the array
 *
 * @return This function doesn't return data
 */
void print_statistics(unsigned char arr[], unsigned int size);

/**
 * @brief Print the elements of the array
 *
 * This function takes as an input an array of 
 * unsigned characters and an unsigned integer 
 * representing its length. Then it prints its 
 * elements one by one.
 *
 * @param arr Array of unsigned characters
 * @param size The length of the array
 *
 * @return This function doesn't return data
 */
void print_array(unsigned char arr[], unsigned int size);

/**
 * @brief Find the median in a number set
 *
 * <Add Extended Description Here>
 *
 * @param arr Array of unsigned characters
 * @param size The length of the array
 *
 * @return The median value of the array
 */
unsigned char find_median(unsigned char arr[], unsigned int size);

/**
 * @brief Find the mean in a number set
 *
 * This function takes as an input an array of 
 * unsigned characters and an unsigned integer 
 * representing its length. Then it finds its 
 * median value which breaks the array into
 * two halves.
 *
 * @param arr Array of unsigned characters
 * @param size The length of the array
 *
 * @return The mean value of the array
 */
unsigned char find_mean(unsigned char arr[], unsigned int size);

/**
 * @brief Find the maximum in a number set
 *
 * This function takes as an input an array of 
 * unsigned characters and an unsigned integer 
 * representing its length. Then it finds its 
 * mean value (the average).
 *
 * @param arr Array of unsigned characters
 * @param size The length of the array
 *
 * @return The maximum value of the array
 */
unsigned char find_maximum(unsigned char arr[], unsigned int size);

/**
 * @brief Find the minimum in a number set
 *
 * This function takes as an input an array of 
 * unsigned characters and an unsigned integer 
 * representing its length. Then it finds its 
 * minimum value.
 *
 * @param arr Array of unsigned characters
 * @param size The length of the array
 *
 * @return The minimum value of the array
 */
unsigned char find_minimum(unsigned char arr[], unsigned int size);

/**
 * @brief Sort the array elements descendingly
 *
 * This function takes as an input an array of 
 * unsigned characters and an unsigned integer 
 * representing its length. Then it finds its 
 * maximum value.
 *
 * @param arr Array of unsigned characters
 * @param size The length of the array
 *
 * @return This function doesn't return data
 */
void sort_array(unsigned char arr[], unsigned int size);


#endif /* __STATS_H__ */
