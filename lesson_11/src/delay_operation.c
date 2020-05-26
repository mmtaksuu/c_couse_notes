/**
 * @file    : LESSON_11 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 26 / May / 2020
 * @code    : delay_operation.c file
 * @details : 
 */

#include <time.h>
#include <stdio.h>


void delay(double sec)
{
    clock_t start = clock();

    while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}

int main(void)
{
    clock_t start = clock();

    printf("Started\n");
    delay(2);
    printf("Ended\n");

    clock_t end = clock();

    clock_t second  = (end - start) / CLOCKS_PER_SEC;
    clock_t minute  = 0;

    minute += second / 60;
    second %= 60;
    minute %= 60;

    printf("Total time is %ld minutes and %ld seconds.\n", minute, second);

    return 0;
}

