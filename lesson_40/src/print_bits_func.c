/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : random_set_reset_2.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <basetsd.h>

void print_bits(UINT16 val)
{
    char str[20];
    _itoa(val, str, 2);
    printf("%016s", str);
}


int main(void)
{
    UINT16 uval;
    printf("Enter a value : ");
    scanf("%hd", &uval);

    printf("\n");
    print_bits(uval);
    printf("\n");


    for (int i = 0; i < 16; ++i)
    {
        if ( uval & (1 << i) )
        {
            printf("%d sayisinin %d.inci bit 1 dir.\n", uval, i);

        }
    }

    return 0;
}
