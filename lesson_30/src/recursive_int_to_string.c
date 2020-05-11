/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : recursive_int_to_string.c file
 * @details : 
 */

#include <stdio.h>


void print_as_str(int x)
{
    if (x < 0)
    {
        x = - x;
        putchar('-');
    }

    if (x)
        print_as_str(x / 10);
    else
        return;

    putchar(x % 10 + '0');
}


int main(void)
{
    int ival;
    printf("Enter a value : ");
    scanf("%d", &ival);

    print_as_str(ival);

    return 0;
}

