/*
  Project Name: LESSON_14
  Author: MEHMET AKSU
  Author Email: mmtaksu.25@gmail.com
  Date: 02 / Ocak / 2020
  Description: nutility.c file
*/

#include "nutility.h"

double sum_square(int x, int y)
{
    return power(x, 2) + power(y, 2);
}


int ndigit(int x)
{
    int digit = 0;

    if (!x)
        return 1;

    while (x)
    {
        ++digit;
        x = x/10;
    }

    return digit;

}


double power(int base, int exp)
{
    int result = 1;

    if (!exp)
        return 1;

    while (exp--)
    {
        result *= base;
    }

    return result;
}

/* Definition :
 * A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
 */
int isprime(int x)
{
    if (x < 1)
        return 0;

    int i;
    for (i = 2; i < x/2; ++i)
    {
        if (x % i == 0)
            return 0;
    }

    if(i == x/2)
        return x;
}


