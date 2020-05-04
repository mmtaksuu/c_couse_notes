/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 03 / May / 2020
 * @code    : test01.c file
 * @details : 
 */

#include <basetsd.h>
#include <stdlib.h>
#include <stdio.h>


#define     BIT_0   0X00u
#define     BIT_1   0X01u
#define     BIT_2   0X02u
#define     BIT_3   0X03u
#define     BIT_4   0X04u
#define     BIT_5   0X05u
#define     BIT_6   0X06u
#define     BIT_7   0X07u

#define     set_bit(val, n)     ((val) |= (1u << (n)))


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

    set_bit(ival, BIT_0);
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    set_bit(ival, BIT_1);
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    set_bit(ival, BIT_2);
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    set_bit(ival, BIT_3);
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    set_bit(ival, BIT_4);
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    set_bit(ival, BIT_5);
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    set_bit(ival, BIT_6);
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    set_bit(ival, BIT_7);
    print_bit(ival);
    printf("ival = %hhd\n", ival);
    ival = 0;
    printf("\\----------------------------------------\n");

    return 0;
}


