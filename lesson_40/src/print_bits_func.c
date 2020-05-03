/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : print_bits_func.c file
 * @details : 
 */

#include <stdio.h>
#include "helper.h"


int main(void)
{
    UINT8 uval;
    printf("Enter a value : ");
    scanf("%hhd", &uval);

    bit_print(uval);

    for (size_t i = 0; i < 8; ++i)
    {
        printf("%d sayisinin %d.inci bit degeri %d dir.\n", uval, i, GET_BIT(uval, i));
    }
    printf("\n\n");

    printf("Sets all of the bits\n");
    for (size_t i = 0; i < 8; ++i)
    {
        SET_BIT(uval, i);
    }

    printf("Prints only setted bits\n");
    bit_print(uval);
    for (size_t i = 0; i < 8; ++i)
    {
        if (GET_BIT(uval, i))
        {
            printf("%d sayisinin %d.inci bit 1 dir.\n", uval, i);
        }
    }
    printf("\n\n");

    printf("Toggles all of the bits\n");
    for (size_t i = 0; i < 8; ++i)
    {
        FLIP_BIT(uval, i);
    }

    for (size_t i = 0; i < 8; ++i)
    {
        printf("%d sayisinin %d.inci bit degeri %d dir.\n", uval, i, GET_BIT(uval, i));
    }

    return 0;
}
