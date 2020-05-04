#include <glob.h>

/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : check_given_number.c file
 * @details : 
 */

#include <stdio.h>
#include "helper.h"

#define     LSB_BIT     (1u << 0)
#define     MSB_BIT     (1u << ((sizeof(int)*8)-1))

int main(void)
{
    int ival;
    printf("Enter a value : ");
    scanf("%d", &ival);

    bit_print(ival);

    if (ival & LSB_BIT)   // Checks the first bit of the given number
        printf("Given number is an odd number.\n");
    else
        printf("Given number is an even number.\n");


    if (ival & MSB_BIT)    // Checks the last bit of the given number
        printf("Given number is a negative number.\n");
    else
        printf("Given number is a positive number.\n");

    return 0;
}


