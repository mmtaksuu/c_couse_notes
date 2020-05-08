/**
 * @file    : LESSON_32 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 02 / Mart / 2020
 * @code    : qsort_impl_01.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include "helper.h"


#define     SIZE        100


int main(void)
{
    randomize();

    int a[SIZE];
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    qsort(a, SIZE, sizeof(*a), &icmp);
    display_array(a, SIZE);

    double da[SIZE];
    set_random_array_d(da, SIZE);
    display_array_d(da, SIZE);
    qsort(da, SIZE, sizeof(*da), &dcmp);
    display_array_d(da, SIZE);

    return 0;
}
