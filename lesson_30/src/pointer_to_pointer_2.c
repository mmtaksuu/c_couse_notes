/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : pointer_to_pointer_2.c file
 * @details : 
 */

#include "helper.h"

int main(void)
{
    int a[] = { 1, 3, 5, 7, 9, 11};

    int *ptr = a;
    int **p = &ptr;

    display_array(a, asize(a));

    ++*p;
    ++**p;

    display_array(a, asize(a));

    return 0;
}
