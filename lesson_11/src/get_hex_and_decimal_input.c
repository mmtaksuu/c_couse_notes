/**
 * @file    : LESSON_11 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 26 / May / 2020
 * @code    : get_hex_and_decimal_input.c file
 * @details : 
 */

#include <ctype.h>
#include <stdio.h>

int get_decimal_input(void)
{
    int c;
    int x = 0;

    while ((c = getchar()) != '\n') {
        if (isdigit(c))
        {
            // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. '0' = 48'dir.
            x = x * 10 + c - '0';
        }
    }

    return x;
}

int get_hex_input(void)
{
    int x = 0;

    int c;
    while ((c = getchar()) != '\n') {
        if (isdigit(c))
        {
            // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. '0' = 48'dir.
            x = x * 16 + c - '0';
        }
        else if (isxdigit(c))
        {
            // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. 'A' = 65'dir.
            x = x * 16 + toupper(c) - 'A' + 10;    // A --> 10
        }                                          // B --> 11
    }                                              // C --> 12
                                                   // D --> 13
                                                   // E --> 14
                                                   // F --> 15
    return x;
}


int main(void)
{
    int input1 = get_decimal_input();
    printf("input = %d\n", input1);

    int input2 = get_hex_input();
    printf("input = 0X%02X\n", input2);

    return 0;
}
