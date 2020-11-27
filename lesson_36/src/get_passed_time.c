/**
 * @file    : LESSON_36 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 19 / September / 2020
 * @code    : get_passed_time.c file
 * @details : 
 */

#include <time.h>
#include <stdio.h>
//#include <winbase.h>


void delay(double sec)
{
    clock_t start = clock();

    while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}


int main(void)
{
    time_t time1;
    time(&time1);

    delay(2);  // gets as sn
//    Sleep(2000); // gets as ms

    time_t time2;
    time(&time2);

    double passed_time = difftime(time2, time1);
    printf("Passed Time = %.3f sec\n", passed_time);

    return 0;
}


