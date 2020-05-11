/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 10 / May / 2020
 * @code    : memchr_exp.c file
 * @details : 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define     SIZE    100

typedef unsigned char Byte;

int main(void)
{
    Byte a[SIZE] = {0};

    for (size_t i = 0; i < SIZE*3; ++i)
        a[rand() % SIZE] = 1;

    for (size_t i = 0; i < SIZE; ++i)
        printf("%u%c", a[i], i % 20 == 19 ? '\n' : ' ');
    printf("\n");

    Byte * p = memchr(a, 0, sizeof(a));

    if (!p)
    {
        fprintf(stderr, "Not Found!\n");
        exit(EXIT_FAILURE);
    } else
    {
        printf("Found at %d index.\n", p-a);
    }

    return 0;
}
