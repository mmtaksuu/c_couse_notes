/**
 * @file    : LESSON_39 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 04 / April / 2020
 * @code    : test.c file
 * @details : 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void sleep(double sec)
{
    clock_t start = clock();

    while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}

void print_bits(int val)
{
    char str[40];

    _itoa(val, str, 2);
    printf("%32s\n", str);
}

int main(void)
{
    int ival;
    printf("Enter a value : ");
    scanf("%d", &ival);

    printf("ival : \n");
    print_bits(ival);
    sleep(1);

    printf("~ival : \n");
    print_bits(~ival);
    sleep(1);

    printf("~~ival : \n");
    print_bits(~~ival);
    sleep(1);


    printf("ival  = %d\n", ival);

    ival = ~ival;
    printf("~ival = %d\n", ival);

    unsigned int uval = ~0u;
    printf("uval (~0u)= %u\n", uval);

    int x = 0b00001111;
    printf("0b00001111 : %d\n", x);

    print_bits(x);
    sleep(1);


    return 0;
}
