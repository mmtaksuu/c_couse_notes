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

void get_hex(int * val)
{
    printf("Hex deger girin : ");
    scanf("%X", val);
}


void print_hex_bits(const int * val)
{
    char str[40];
    _itoa(*val, str, 2);
    printf("%016s\n", str);
}


int main(void)
{
    int val;
    get_hex(&val);
    print_hex_bits(&val);

    return 0;
}


