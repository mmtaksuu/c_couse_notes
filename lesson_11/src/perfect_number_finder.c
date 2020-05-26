/**
 * @file    : LESSON_11 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 26 / May / 2020
 * @code    : perfect_number_finder.c file
 * @details : 
 */

#include <stdio.h>
#include <conio.h>

// A positive integer n is called a perfect number
// if it is equal to the sum of all of its positive divisors, excluding n itself.
int is_perfect_number(unsigned val)
{
    unsigned div_sum = 0;

    for (size_t i = 1; i <= val / 2; ++i)
        if (val % i == 0)
            div_sum += i;

    return val == div_sum;
}

int main(void)
{
    while (!_kbhit() || _getch() != 'Q')
    {
        unsigned test_val;
        printf("Enter a number : ");
        scanf("%u", &test_val);

        printf("%u is %s\n", test_val, is_perfect_number(test_val) > 0 ? "Perfect Number" : "Not Perfect Number");
    }

    /*for (unsigned i = 2; i < 1000000; ++i) {
        if (is_perfect_number(i))
            printf("%u ", i);
    }*/

    return 0;
}
