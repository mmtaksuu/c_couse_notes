/**
 * @file    : LESSON_12 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 30 / May / 2020
 * @code    : factorial_finder.c file
 * @details : 
 */

#include <stdio.h>
#include <stdint.h>


int64_t factorial_iter(int ival)
{
    int64_t res = 1;

    for (int i = 1; i <= ival; ++i)
        res *= i;

    return res;
}

int64_t factorial_recursive(int ival)
{
    return ival < 2 ? 1 : ival * factorial_recursive(ival-1);
}


int64_t factorial_look_up(int n)
{
    static const int64_t vals[] = {
                                    1,
                                    1,
                                    2,
                                    6,
                                    24,
                                    120,
                                    720,
                                    5040,
                                    40320,
                                    362880,
                                    3628800,
                                    39916800,
                                    479001600,
                                    6227020800,
                                    87178291200,
                                    1307674368000,
                                    20922789888000,
                                    355687428096000,
                                    6402373705728000,
                                    121645100408832000,
                                    2432902008176640000,
                                    };

    return vals[n];
}


int main(void)
{
    /*int x;
    printf("Enter a number : ");
    scanf("%d", &x);

    printf("Factorial of %d is %lld\n", x, factorial_iter(x));
    printf("Factorial of %d is %lld\n", x, factorial_recursive(x));
    printf("Factorial of %d is %lld\n", x, factorial_look_up(x));*/

    for (int i = 0; i < 21; ++i) {
        printf("%2d! = %lld\n", i, factorial_iter(i));
    }

    return 0;
}
