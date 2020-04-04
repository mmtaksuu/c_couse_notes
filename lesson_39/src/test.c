/**
 * @file    : LESSON_39 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 04 / April / 2020
 * @code    : test.c file
 * @details : 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void sleep(double sec)
{
    clock_t start = clock();

    while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}

void bprint(int val)
{
    char str[40];

    _itoa(val, str, 2);
    printf("%32s\n", str);
}

int main(void)
{


    return 0;
}
