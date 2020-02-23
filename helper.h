/**
 * @file    : LESSON_20 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / February / 2020
 * @code    : helper.c file
 * @details : 
 */

#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>
#include <time.h>

/**
 * @brief Randomize idiom
 * @details Used to generate different pseudo using system time for random number generator
 */
#define     randomize()       (srand((unsigned)time(NULL)))

/**
 * @brief Integer random number generator
 * @param num_of_digits is number of digit for generating number
 * @details Generates random numbers type of int for the given number of digits
 * @return Generated random number of type int
 */
int gen_rand_int_nums(int num_of_digits);

/**
 * @brief Floating random number generator
 * @param num_of_digits is number of digit for generating number
 * @details Generates random numbers type of floating-point for the given number of digits
 * @return Generated random number of type float
 */
float gen_rand_float_nums(int num_of_digits);

/**
 * @brief Fills the given array
 * @param p is the address of the given array
 * @param size is the size of the given array
 * @param num_of_digits is used for filling the array with n number of digits random numbers
 * @details This function uses the gen_rand_int_nums() function to fill the given array with desired random numbers.
 */
void set_random_array(int *p, size_t size, int num_of_digits);

/**
 *
 */
void display_array(const int *, size_t);

/**
 *
 * @param p
 * @return
 */
char *sgets(char *p);

/**
 * @brief Bubble sort algorithm
 * @param p is the address of the given array
 * @param size is the size of the given array
 * @details Applies bubble sort algorithm for the given array
 */
void bsort(int *arr, int size);

/**
 *
 * @param p1
 * @param p2
 */
void swap_arr_items(int *p1, int *p2);

#endif //HELPER_H
