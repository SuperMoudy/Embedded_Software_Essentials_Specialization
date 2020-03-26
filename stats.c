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
 * @file stats.c
 * @brief Statistical analysis of a number set
 *
 * A simple C program performing statistical analysis 
 * on an array of unsigned characters (as a number set).
 * This analysis consists of:
 * - Finding the median value
 * - Finding the mean value
 * - Finding the maximum value
 * - Finding the minimum value
 * - Sorting the number set
 * - Printing the number set
 *
 * @author Mahmoud Hamdy
 * @date Mar 26, 2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  /* Statistics and Printing Functions */
  printf("Array before sorting:\n");
  print_array(test, SIZE);

  printf("Array after sorting:\n");
  sort_array(test, SIZE);
  print_array(test, SIZE);

  printf("Performing Statistical Analysis...\n");
  print_statistics(test, SIZE);

}

void print_statistics(unsigned char arr[], unsigned int size)
{
  unsigned char median = find_median(arr, size);
  unsigned char mean = find_mean(arr, size);
  unsigned char maximum = find_maximum(arr, size);
  unsigned char minimum = find_minimum(arr, size);

  printf("Median  = %3u\n", median);
  printf("Mean    = %3u\n", mean);
  printf("Maximum = %3u\n", maximum);
  printf("Minimum = %3u\n\n", minimum); 
}

void print_array(unsigned char arr[], unsigned int size)
{
  for(int i = 0; i < size; i++)
  {
    printf("%3u ", arr[i]);
  }
  printf("\n\n");
}

unsigned char find_median(unsigned char arr[], unsigned int size)
{
  sort_array(arr, size);
  int mid_index = size / 2;

  if(size % 2 != 0)
    return arr[mid_index];

  return (arr[mid_index] + arr[mid_index - 1]) / 2;
}

unsigned char find_mean(unsigned char arr[], unsigned int size)
{
  int sum = 0;
  for(int i = 0; i < size; i++)
  {
    sum += arr[i];
  }

  return sum / size;
}

unsigned char find_maximum(unsigned char arr[], unsigned int size)
{
  unsigned char max = arr[0];
  for(int i = 0; i < size; i++)
  {
    if(arr[i] > max)
      max = arr[i];
  }

  return max;
}

unsigned char find_minimum(unsigned char arr[], unsigned int size)
{
  unsigned char min = arr[0];
  for(int i = 0; i < size; i++)
  {
    if(arr[i] < min)
      min = arr[i];
  }

  return min;
}

void sort_array(unsigned char arr[], unsigned int size)
{
  unsigned char min, temp;
  for(int i = 0; i < size - 1; i++)
  {
    for(int j = 0; j < size - 1 - i; j++)
    {
      if(arr[j] < arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
