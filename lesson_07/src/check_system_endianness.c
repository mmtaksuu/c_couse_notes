/**
 * @file    : LESSON_7 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / May / 2020
 * @code    : check_system_endianness.c file
 * @details : 
 */

#include <stdio.h>

void check_system_endianness(void)
{
    unsigned int uval = 1u;

    char * p = (char *)&uval;

    if (*p == 1)
        printf("Your system is Little endian\n");
    else
        printf("Your system is Big endian\n");
}

int main(void)
{
    check_system_endianness();

    return 0;
}


