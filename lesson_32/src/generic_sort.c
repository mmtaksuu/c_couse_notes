/**
 * @file    : LESSON_32 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 07 / Mayıs / 2020
 * @code    : generic_sort_01.c file
 * @details : 
 */

#include <stdio.h>
#include "helper.h"

#define     SIZE        50


int main(void)
{
    randomize();

    int a[SIZE] = {0};
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    gsort(a, SIZE, sizeof(*a), &icmp);
    display_array(a, SIZE);

    double da[SIZE] = {0};
    set_random_array_d(da, SIZE);
    display_array_d(da, SIZE);
    gsort(da, asize(da), sizeof(*da), &dcmp);
    display_array_d(da, asize(da));

    printf("Sizeof (int *) is %u Byte\n", sizeof(int *));
    printf("Sizeof (double *) is %u Byte\n", sizeof(double *));
    printf("Sizeof (void *) is %u Byte\n", sizeof(void *));
    printf("Sizeof (char *) is %u Byte\n", sizeof(char *));

    return 0;
}
