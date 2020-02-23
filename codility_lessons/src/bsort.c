/**
 * @file    : LESSON_20 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / February / 2020
 * @code    : bsort.c file
 * @details : 
 */

#include <stdio.h>
#include "../../helper.h"

#define     SIZE              40


int main(void)
{
    int a[SIZE];

    randomize();
    set_random_array(a, SIZE, 2);
    display_array(a, SIZE);

    bsort(a, SIZE);

    display_array(a, SIZE);

    return 0;
}

