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
#include <stdlib.h>

void print_bits(int val)
{
    char str[40];
    _itoa(val, str, 2);
    printf("%032s\n", str);
}


int main(void)
{
    int ival;
    printf("Enter a value : ");
    scanf("%d", &ival);

    print_bits(ival);

    if (ival & (1 << 0))   // Checks the first bit of the given number
        printf("Given number is an odd number.\n");
    else
        printf("Given number is an even number.\n");


    if (ival & (1 << ((sizeof(int)*8)-1)))    // Checks the last bit of the given number
        printf("Given number is a negative number.\n");
    else
        printf("Given number is a positive number.\n");

    return 0;
}


