/**
 * @file    : LESSON_8 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 24 / May / 2020
 * @code    : putchar_examples.c file
 * @details : 
 */


#include <stdio.h>

int main(void)
{
    printf("Prints English Alphabet in Capital\n");
    for (int i = 0; i < 26; ++i)
        putchar(i + 'A'); // 'A' --> 65
    printf("\n\n");

    printf("Prints English Alphabet in Lowercase\n");
    for (int i = 0; i < 26; ++i)
        putchar(i + 'a');  // 'a' --> 97
    printf("\n\n");

    printf("Prints Numbers From 0 to 9\n");
    for (int i = 0; i < 10; ++i)
        putchar(i + '0');  // '0' --> 48
    printf("\n\n");

    return 0;
}
