/**
 * @file    : LESSON_20 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / February / 2020
 * @code    : main.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define     randomize()       (srand((unsigned)time(NULL)))
#define     SIZE              10


int gen_rand_int_nums(int num_of_digits);
float gen_rand_float_nums(int num_of_digits);


int main(void)
{
    randomize();

    for (int i = 0; i < SIZE; ++i) {

        int itemp = gen_rand_int_nums(3);
        printf("%d\n", itemp);

        float ftemp = gen_rand_float_nums(4);
        printf("%.2lf\n\n", ftemp);
    }

    return 0;
}


int gen_rand_int_nums(int num_of_digits)
{
    switch (num_of_digits){
        case 1:
            return rand() % 10;
        case 2:
            return rand() % 100;
        case 3:
            return rand() % 1000;
        case 4:
            return rand() % 10000;
        default:
            return rand();
    }
}


float gen_rand_float_nums(int num_of_digits)
{
    switch (num_of_digits){
        case 1:
            return (float)rand()/(float)(RAND_MAX/10.0);
        case 2:
            return (float)rand()/(float)(RAND_MAX/100.0);
        case 3:
            return (float)rand()/(float)(RAND_MAX/1000.0);
        case 4:
            return (float)rand()/(float)(RAND_MAX/10000.0);
        default:
            return (float)rand()/(float)(RAND_MAX/1.0);
    }
}




