/**
 * @file    : LESSON_23 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 25 / March / 2020
 * @code    : ptr_aritmetics.c file
 * @details : 
 */

#include <stdio.h>


int main(void)
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 10; ++i) {
        printf("%p %p\n", a + i, &a[i]);
    }

    printf("\n\n");

    for (int i = 0; i < 10; ++i) {
        printf("%d %d %d %d\n", a[i], i[a], *(a + i), *(i + a));
    }

    printf("\n\n");

    int *p1 = a + 7;
    int *p2 = a + 2;

    printf("%d\n", p1 - p2);
    printf("%d\n", p2 - p1);

    return 0;
}


