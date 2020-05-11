/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 01 / March / 2020
 * @code    : my_memset_func.c file
 * @details : 
 */

#include <stdio.h>
#include "helper.h"


#define     SIZE              100


void * my_memset(void *vp, int ival, size_t n_btyes)
{
    unsigned char * p = (unsigned char *)vp;

    while (n_btyes--)
        *p++ = (unsigned char)ival;

    return vp;
}



int main(void)
{

    int a[SIZE];

    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);

    int set_val = 0;
    size_t start_idx, n_of_items = 0;

    printf("Enter start_idx, n_of_items, and set_value : ");
    scanf("%u%u%d", &start_idx, &n_of_items, &set_val);

    my_memset(a + start_idx, set_val, n_of_items * sizeof(*a));

    putchar('\n');
    display_array(a, SIZE);

    return 0;
}



