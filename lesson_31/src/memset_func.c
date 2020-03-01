/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 01 / March / 2020
 * @code    : memset_func.c file
 * @details : 
 */

#include <stdio.h>
#include "../../helper.h"


#define     SIZE              100


void *memset_(void *vp, int val, size_t n)
{
    char *p = (char *)vp;

    while (n--)
        *p++ = (char)val;

    return vp;
}



int main(void)
{

    int a[SIZE];

    randomize();
    set_random_array(a, SIZE, 2);
    display_array(a, SIZE);

    int val = 0;
    size_t idx, pieces = 0;
    printf("Enter index, pieces, and set value : ");
    scanf("%u%u%d", &idx, &pieces, &val);

    memset_(a + idx, val, pieces * sizeof(*a));

    display_array(a, SIZE);

    return 0;
}



