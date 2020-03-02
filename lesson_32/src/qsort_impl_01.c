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
#include "../../helper.h"


#define     SIZE        100


int icmp(const void *vp1, const void *vp2)
{
    const int *p1 = (const int *)vp1;
    const int *p2 = (const int *)vp2;

    if (*p1 > *p2)
        return 1;

    if (*p1 < *p2)
        return -1;

    return 0;
}


int main(void)
{

    int a[SIZE];

    randomize();
    set_random_array(a, SIZE, 2, "int");
    display_array(a, SIZE);

    qsort(a, SIZE, sizeof(*a), &icmp);
    display_array(a, SIZE);

    int da[SIZE];
    set_random_array(da, SIZE, 3, "double");

    return 0;
}
