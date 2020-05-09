/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : indicate_as_bin_hex_dec.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ival;
    printf("Enter a value : ");
    scanf("%d", &ival);

    char str[100];

    printf("10'luk sayi sisteminde : ");
    _itoa(ival, str, 10);
    printf("%s\n", str);

    printf("16'lik sayi sisteminde : ");
    _itoa(ival, str, 16);
    printf("0X%s\n", str);

    printf("2'lik sayi sisteminde : ");
    _itoa(ival, str, 2);
    printf("%s\n", str);

    return 0;
}

