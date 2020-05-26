/**
 * @file    : LESSON_8 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 24 / May / 2020
 * @code    : reverse_number.c file
 * @details : 
 */

#include <stdio.h>


int ndigit(int x)
{
    int digit_count = 0;

    if (!x)
        return 1;

    while (x != 0) {
        ++digit_count;
        x /= 10;
    }

    return digit_count;
}

int power(int base, int exp)
{
    return exp == 0 ? 1 : base * power(base, exp-1);
}


int reverse_number(int ival)
{
    int nOfdigit = ndigit(ival);
    int reversed_number = 0;

    for (int i = 0; i < nOfdigit; ++i) {
        int digit_val = (ival / power(10, i)) % 10;
        reversed_number += digit_val * power(10, nOfdigit-i-1);
    }

    return reversed_number;
}

int main(void)
{
    int x;
    printf("Enter a number : ");
    scanf("%d", &x);

    printf("Entered Number  : %d\n", x);
    printf("Reversed Number : %d\n", reverse_number(x));

    return 0;
}

