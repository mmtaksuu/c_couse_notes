/**
 * @file    : LESSON_13 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 31 / May / 2020
 * @code    : find_all_factors.c file file returns the multipliers of the given number. For exp : x is 34 then output : 2 17.
 * @details :
 */

#include <stdio.h>


void find_all_factors (int x)
{
    int n = 2;

    while (x != 1) {
        while (x % n == 0) {
            printf("%d ", n);
            x /= n;
        }
        ++n;
    }
}


int main(void)
{
    int x;
    printf("Enter a number : ");
    scanf("%d", &x);

    find_all_factors(x);

    return 0;
}


