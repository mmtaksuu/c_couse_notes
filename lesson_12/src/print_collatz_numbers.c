/**
 * @file    : LESSON_12 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 31 / May / 2020
 * @code    : print_collatz_numbers.c file
 * @details : 
 */

#include <stdio.h>

// 100 50 25 76 38 19 58 29 88 44 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

void print_collatz(unsigned long long int uval)
{
    while (uval != 1) {
        printf("%llu ", uval);
        if (uval % 2 == 0)
            uval /= 2;
        else
            uval = uval * 3 + 1;
    }

    printf("1\n");
}


int main()
{
    print_collatz(100ull);

    return 0;
}

