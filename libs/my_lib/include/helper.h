/**
 * @file    : MY_LIB project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / February / 2020
 * @code    : helper.c file
 * @details : 
 */

#ifndef HELPER_H
#define HELPER_H

#include <time.h>
#include <stdlib.h>
#include <basetsd.h>

#define     PRIVATE     static
#define     PUBLIC      extern


/**
 * @brief Randomize idiom
 * @details Used to generate different pseudo using system time for random number generator
 */
#define     randomize()       (srand((unsigned)time(NULL)))

/**
 * @brief Asize idiom
 * @details Used to find size of the given array
 */
#define     asize(x)          (sizeof(x) / sizeof ((x)[0]))

/**
 * Bitwise manipulatons
 */
#define     MASK(n)                     (1u << (n))
#define     SET_BIT(val, n)             ((val) |= MASK(n))
#define     RESET_BIT(val, n)           ((val) &= ~MASK(n))
#define     FLIP_BIT(val, n)            ((val) ^= MASK(n))
#define     GET_BIT(val, n)             (((val) & MASK(n)) > 0 ? 1 : 0)
#define     SET_RAND_BIT(val, type)     ((val) |=  (1u << ((unsigned int)rand() % (sizeof(type) * 8))))
#define     RESET_RAND_BIT(val, type)   ((val) &= ~(1u << ((unsigned int)rand() % (sizeof(type) * 8))))
#define     FLIP_RAND_BIT(val, type)    ((val) ^=  (1u << ((unsigned int)rand() % (sizeof(type) * 8))))
#define     GET_RAND_BIT(val, type)     (((val) &  (1u << ((unsigned int)rand() % (sizeof(type) * 8)))) > 0 ? 1 : 0)

/**
 * @brief Integer random number generator
 * @param num_of_digits is number of digit for generating number
 * @details Generates random numbers type of int for the given number of digits
 * @return Generated random number of type int
 */
int gen_rand_int_nums(void);

/**
 * @brief Floating random number generator
 * @param num_of_digits is number of digit for generating number
 * @details Generates random numbers type of floating-point for the given number of digits
 * @return Generated random number of type float
 */
double gen_rand_real_nums(void);

/**
 * @brief Fills the given array
 * @param p is the address of the given array
 * @param size is the size of the given array
 * @details This function uses the gen_rand_int_nums() function to fill the given array with desired random numbers.
 */
void set_random_array(int *p, size_t size);

/**
 *
 */
void display_array(const int *p, size_t size);


void set_random_array_d(double *p, size_t size);


void display_array_d(const double *p, size_t size);

int find_imax(const int *p, size_t size);

double find_dmax(const double *p, size_t size);


/**
 *
 * @param p
 * @return
 */
char *sgets(char *p);

/**
 *
 * @param p1
 * @param p2
 */
void swap_arr_items(int *p1, int *p2);

void gswap(void *vp1, void *vp2, size_t n);


void gsort(void *vpa, size_t size, size_t width, int(*fp)(const void *, const void *));
/**
 * @brief Bubble sort algorithm
 * @param p is the address of the given array
 * @param size is the size of the given array
 * @details Applies bubble sort algorithm for the given array
 */
void bsort(int *arr, int size);


int icmp(const void *vp1, const void *vp2);

int dcmp(const void *vp1, const void *vp2);

/**
 * @brief Generic Compairing Function that is used for all of the types
 * @param vp1
 * @param vp2
 * @param width total sizeof of the compairing blocks
 * @return
 */
int gcmp(const void *vp1, const void *vp2, size_t width);

void delay(double sec);

int is_hit_button(int ch);

/**
 *
 * @param val
 */
void bit_print(UINT16 val);

extern const char *pnames[300];

#endif //HELPER_H
