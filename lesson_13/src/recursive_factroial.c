/*
  Project Name: LESSON_13
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 03 / Ocak / 2020	
  File Description: recursive_factroial.c file 
*/

#include <stdio.h>

long long int rec_factorial(int x)
{
    return x <= 1 ? 1 : x * rec_factorial(x-1);
}


int main(void)
{
    for (int i = 1; i < 21; ++i)
    {
        printf("%2d! --> %lld\n", i, rec_factorial(i));
    }

    return 0;
}

