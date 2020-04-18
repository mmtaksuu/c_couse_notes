/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : random_set_reset_2.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <basetsd.h>
#include <winbase.h>

void print_bits(int val)
{
    char str[40];
    _itoa(val, str, 2);
    printf("%032s\r", str);
}

int main(void)
{
    INT32 ival = 0;

    printf("\n");
    print_bits(ival);
    printf("\n");
    printf("Tum bitler set ediliyor...\n");
    while (ival != -1)
    {
        ival |= (1 << ((UINT32)rand() % (sizeof(INT32) * 8)));
        print_bits(ival);
        Sleep(35);
    }

    printf("\n");
    printf("Tum bitler reset yapiliyor...\n");
    while (ival != 0)
    {
        ival &= ~(1 << (rand() % (sizeof(INT32) * 8)));
        print_bits(ival);
        Sleep(35);
    }

    printf("\n");
    printf("Tum bitler flip yapiliyor...\n");
    while (ival != -1)
    {
        ival ^= (1 << (rand() % (sizeof(INT32) * 8)));
        print_bits(ival);
        Sleep(35);
    }

    printf("\n");

    return 0;
}
