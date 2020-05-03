/**
 * @file    : LESSON_41 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 21 / April / 2020
 * @code    : randomize.c file
 * @details : 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winbase.h>
#include <limits.h>

void randomize(void)
{
    srand((unsigned)time(NULL));
}


int main(void)
{
    randomize();

    while (!_kbhit())
    {
//        printf("%ld\r", time(NULL));
        printf("%d\r", rand()/(RAND_MAX));
        Sleep(1000);

    }

    printf( "\nKey struck was '%c'\n", _getch() );


    return 0;
}
