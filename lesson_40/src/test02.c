/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 03 / May / 2020
 * @code    : test02.c file
 * @details :
 */

#include <basetsd.h>
#include <stdlib.h>
#include <stdio.h>


#define     BIT_0   0X01
#define     BIT_1   0X02
#define     BIT_2   0X04
#define     BIT_3   0X08
#define     BIT_4   0X10
#define     BIT_5   0X20
#define     BIT_6   0X40
#define     BIT_7   0X80


void print_bit(UINT8 val)
{
    char str[20];
    _itoa(val, str, 2);
    printf("%08s\n", str);
}


int main(void)
{
    UINT8 ival = 0;
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    printf("\\----------------------------------------\n");

    ival = BIT_0;
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    ival = BIT_1;
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    ival = BIT_2;
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    ival = BIT_3;
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    ival = BIT_4;
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    ival = BIT_5;
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    ival = BIT_6;
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    ival = BIT_7;
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    return 0;
}


