/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : pointer_to_pointer.c file
 * @details : 
 */


#include <stdio.h>

int main(void)
{
    int x = 10;
    int y = 20;

    int *ptr = &x;
    int **p = &ptr;

    printf("*ptr = %d\n", *ptr);
    *p = &y; //ptr = &y;

    printf("*ptr = %d\n", *ptr);

    return 0;
}

