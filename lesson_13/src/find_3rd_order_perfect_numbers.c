/*
  Project Name: LESSON_13
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 03 / Ocak / 2020	
  File Description: find_3rd_order_perfect_numbers.c file displays 3 order perfect numbers among from 100 to 999 ( 153, 370, 371, 407)
*/

#include <stdio.h>

int main(void)
{
    printf("\n\n3rd order perfect numbers are : \n");

    int val = 100;

    // This loop counts from 100 to 999 to finds 3 order perfect numbers ( 153, 370, 371, 407)
    for (int i = 1; i <= 9; ++i) {           // represents 100 order
        for (int j = 0; j <= 9; ++j) {       // represents 10 order
            for (int k = 0; k <= 9; ++k) {   // represents 1 order
                if (val == i * i * i + j * j * j + k * k * k)
                    printf("%d\n", val);
                ++val;
            }
        }
    }

    return 0;
}


