/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / May / 2020
 * @code    : return_string.c file
 * @details : 
 */

#include <stdio.h>

char * foo(void)
{
    return "LOG Kaydedildi!";
}

int main(void)
{
    printf("%s\n", foo());

    return 0;
}

