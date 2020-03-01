/**
 * @file    : c_programing_course project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 01 / March / 2020
 * @code    : memset_fill_array.c file
 * @details : void *memset(void *vp, int val, size_t n);
 */

#include <stdio.h>
#include <string.h>
#include "../../helper.h"

#define     SIZE              100


int main(void)
{
    int a[SIZE];

    randomize();
    set_random_array(a, SIZE, 3);
    display_array(a, SIZE);

    size_t idx, n;
    printf("Enter index and number: ");
    scanf("%u%u", &idx, &n);


    memset(a+idx, 0, n*sizeof(int));
    display_array(a, SIZE);

    return 0;
}


