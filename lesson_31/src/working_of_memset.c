/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 10 / May / 2020
 * @code    : working_of_memset.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"

int main(void)
{
    int a = 0;

    memset(&a, 1, sizeof(a));
    bit_print((unsigned short int)a);
    printf("set value : %d | a = %d\n\n", 1, a);


    memset(&a, 3, sizeof(a));
    bit_print((unsigned short int)a);
    printf("set value : %d | a = %d\n\n", 3, a);


    memset(&a, 5, sizeof(a));
    bit_print((unsigned short int)a);
    printf("set value : %d | a = %d\n\n", 5, a);


    memset(&a, 255, sizeof(a));
    bit_print((unsigned short int)a);
    printf("set value : %d | a = %d\n\n", 255, a);

    return 0;
}
