/*
  Project Name: LESSON_14
  Author: MEHMET AKSU
  Author Email: mmtaksu.25@gmail.com
  Date: 02 / Ocak / 2020
  Description: main.c file
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

int main(void)
{
    int x, y;
    printf("Enter two values : ");
    scanf("%d%d", &x, &y);

    printf("Sum of the square of %d and %d is %.3f\n", x, y, sum_square(x, y));
    printf("The number of digits %d is %d\n The number of digits %d is %d\n ", x, ndigit(x), y, ndigit(y));
    printf("%d power %d is %.3f\n", x, y, power(x, y));
    printf("The primarity of %d is %d \n The primarity of %d is %d \n", x, isprime(x), y, isprime(y));

    return 0;
}

