/**
 * @file    : LESSON_11 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 26 / May / 2020
 * @code    : prime_numbers_finder.c file
 * @details : 
 */

#include <stdio.h>
#include <conio.h>

unsigned power(unsigned base, size_t exp)
{
    if (exp == 0)
        return 1;

    unsigned res = 1;

    while (exp--) {
        res *= base;
    }

    return res;
}

int is_prime(unsigned val)
{
    if (val == 0 || val == 1)
        return 0;

    if (val % 2 == 0)
        return val == 2;

    if (val % 3 == 0)
        return val == 3;

    if (val % 5 == 0)
        return val == 5;

    for (size_t i = 7; power(i,2) <= val; i += 2)
        if (val % i == 0)
            return 0;

    return 1;
}

int main(void)
{
    while (!_kbhit() || _getch() != 'Q')
    {
        unsigned test_val;
        printf("Enter a number : ");
        scanf("%u", &test_val);

        printf("prime situation of %u is %s\n", test_val, is_prime(test_val) > 0 ? "PRIME" : "NOT PRIME");
    }

    /*for (unsigned i = 2; i < 1000; ++i) {
        if (is_prime(i))
            printf("%u ", i);
    }*/

    return 0;
}
