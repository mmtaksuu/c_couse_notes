/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : pointer_swap.c file
 * @details : 
 */


#include <stdio.h>

void pswap(int **p1, int **p2)
{
    int *ptemp = *p1;
    *p1 = *p2;
    *p2 = ptemp;
}


void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int main(void)
{
    int x = 10;
    int y = 20;

    int *ptr1 = &x;
    int *ptr2 = &y;

    printf("x = %d | y = %d \n", *ptr1, *ptr2);

    swap(ptr1, ptr2);
    printf("x = %d | y = %d \n", *ptr1, *ptr2);

    pswap(&ptr1, &ptr2);
    printf("x = %d | y = %d \n", *ptr1, *ptr2);

    return 0;
}


