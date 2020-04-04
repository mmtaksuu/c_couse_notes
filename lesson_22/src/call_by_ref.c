/**
 * @file    : LESSON_22 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 25 / March / 2020
 * @code    : call_by_ref.c file
 * @details : 
 */


#include <stdio.h>

void foo(int *x)
{
    printf("x = %p\n", (void*)x);

    *x = 9999;
}


int main(void)
{
    int y = 12;
    printf("&y = %p\n", (void*)&y);

    foo(&y);

    printf("y = %d\n", y);

    return 0;
}