/**
 * @file    : LESSON_6 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / May / 2020
 * @code    : power_func.c file
 * @details : 
 */

#include <stdio.h>

double power_iter(double base, int exp)
{
    double res = 1.;

    while (exp--)
        res *= base;

    return res;
}


double power_recursive(double base, int exp)
{
    return exp == 0 ? 1 : base * power_recursive(base, exp-1);
}


int main(void)
{
    double base;
    int pow;
    printf("Enter the base and power : ");
    scanf("%lf%d", &base, &pow);

    printf("%d power of %.2f is %.2f\n", pow, base, power_iter(base, pow));
    printf("%d power of %.2f is %.2f\n", pow, base, power_recursive(base, pow));

    return 0;
}

