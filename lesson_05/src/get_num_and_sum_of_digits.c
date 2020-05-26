/**
 * @file    : LESSON_5 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / May / 2020
 * @code    : main.c file
 * @details : 
 */

#include <stdio.h>

int ndigit(int x)
{
    int nOfdigit = 0;

    if (!x)
        return 1;

    while (x != 0)
    {
        ++nOfdigit;
        x /= 10;
    }

    return nOfdigit;
}

int sum_digit(int x)
{
    int sum_of_digit = 0;

    if (!x)
        return 0;

    while (x != 0)
    {
        sum_of_digit += x % 10;
        x /= 10;
    }

    return sum_of_digit;
}

int main(void)
{
    int ival;
    printf("Enter a number : ");
    scanf("%d", &ival);

    printf("The number of digits %-5d\n", ndigit(ival));
    printf("The sum of digits %-5d\n", sum_digit(ival));

    return 0;
}


