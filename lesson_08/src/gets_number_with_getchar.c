/**
 * @file    : LESSON_8 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 24 / May / 2020
 * @code    : gets_number_with_getchar.c file
 * @details : Standart inputa girilen sayinin basamak degerleri toplamini ve sayiyi yazdirir.
 */


#include <stdio.h>

int get_decimal_input(void)
{
    int c;
    int input = 0;

    while ((c = getchar()) != '\n') {
        int digit_value = c - '0';       // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. '0' = 48'dir.
        input = input * 10 + digit_value;
    }

    return input;
}


int get_hex_input(void)
{
    int c;
    int input = 0;

    while ((c = getchar()) != '\n') {
        int digit_value = 0;
        if (c >= '0' && c <= '9')
        {
            digit_value = c - '0';             // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. '0' = 48'dir.
            input = input * 16 + digit_value;
        }
        else
        {
            digit_value = c - 'A' + 10;        // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. 'A' = 65'dir.
            input = input * 16 + digit_value;  // A --> 10
        }                                      // B --> 11
    }                                          // C --> 12
                                               // D --> 13
                                               // E --> 14
                                               // F --> 15
    return input;
}


int main(void)
{
    printf("Enter a decimal number : ");
    printf("Entered Value is %d as decimal\n", get_decimal_input());

    printf("Enter a hexadecimal number : ");
    printf("Entered Value is %d as hex\n", get_hex_input());

    return 0;
}

