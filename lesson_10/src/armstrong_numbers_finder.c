/**
 * @file    : LESSON_10 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 25 / May / 2020
 * @code    : armstrong_numbers_finder.c file
 * @details : The n-digit numbers equal to sum of n th powers of their digits (a finite sequence), called Armstrong Numbers.
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define     ONE_HOUR        60
#define     ONE_MINUTE      60
#define     ONE_SECOND      60

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

int power(int base, size_t exp)
{
    int result = 1;

    if (!exp)
        return 1;

    while (exp--)
        result *= base;

    return result;
}


int is_armstrong(int x)
{
    size_t nOfdigit    = (size_t)ndigit(x);
    int    temp        = x;
    int    sum         = 0;
    int    digit_value = 0;

    while (temp) {
        digit_value = temp % 10;
        sum += power(digit_value, nOfdigit);
        temp /= 10;
    }

    if (sum == x)
        return 1;

    return 0;
}

// Total time is 2 minutes and 59 seconds.
int main(void)
{
    clock_t start = clock();

    for (int i = 0; i < 999999999; ++i) {
        if (is_armstrong(i))
            printf("%d\n", i);
    }

    clock_t end = clock();

    clock_t second  = (end - start) / CLOCKS_PER_SEC;
    clock_t minute  = 0;

    minute += second / ONE_MINUTE;
    second %= ONE_SECOND;
    minute %= ONE_HOUR;

    printf("Total time is %ld minutes and %ld seconds.\n", minute, second);

    return 0;
}

