/**
 * @file    : LESSON_23 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 25 / March / 2020
 * @code    : const_semantics.c file
 * @details : 
 */


#include <stdio.h>


int main(void)
{
    const int x = 1111;

    int *ptr = (int *)&x;
    *ptr = 7777;        //ub

    printf("x = %d\n", x);

    return 0;
}

