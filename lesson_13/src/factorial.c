/*
  Project Name: LESSON_13
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 03 / Ocak / 2020	
  File Description: factorial.c file calculates factorial for the given number.
*/


#include <stdio.h>

long long int factorial(int x)
{
    long long int result = 1;

    if (x < 0)
        x = -x;

    // if x is 5 then result = 5 * 4 * 3 * 2 * 1 = 120
    for (int i = x; i >= 1; --i)
    {
        result *= i;
    }

    return result;
}

int main()
{
//    int ival;
//    printf("Enter a number : ");
//    scanf("%d", &ival);
//
//    printf("Factorial of %d is %d\n", ival, factorial(ival));

    for (int i = 1; i < 21; ++i)
    {
        //printf("%2d! --> %lld \n", i, factorial(i));
    }

    return 0;
}


