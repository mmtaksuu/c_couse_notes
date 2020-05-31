/**
 * @file    : LESSON_13 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 31 / May / 2020
 * @code    : calc_sum_of_series.c file
 * @details : 
 */

#include <stdio.h>

double calc_sum_of_series(int n)
{
    double sum = 0.;
    int factorial = 1;

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
        sum += 1. / factorial;
    }

    return sum;
}

int main(void)
{
    int n;
    printf("How many series do you want to sum : ");
    scanf("%d", &n);

    printf("Sum of the %d series is = %f\n", n, calc_sum_of_series(n));

    return 0;
}



