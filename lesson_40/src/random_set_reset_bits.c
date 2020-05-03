/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / April / 2020
 * @code    : random_set_reset_bits.c file
 * @details : 
 */

#include <ctype.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdint.h>
#include "helper.h"


#define     EXIT        'Q'

void set_bit(UINT16 uval_u16)
{
    do {
        bit_print(uval_u16);
        SET_RAND_BIT(uval_u16, int);
        Sleep(35);
    } while (uval_u16 != UINT16_MAX && !kbhit());
}


void reset_bit(UINT16 uval_u16)
{
    do {
        bit_print(uval_u16);
        RESET_RAND_BIT(uval_u16, int);
        Sleep(35);
    } while (uval_u16 != 0 && !kbhit());
}


void flip_bit(UINT16 uval_u16)
{
    do {
        bit_print(uval_u16);
        FLIP_RAND_BIT(uval_u16, int);
        Sleep(35);
    } while (!kbhit());
}

void get_bit(UINT16 uval_u16)
{
    do {
        bit_print(uval_u16);
        printf("%d sayisinin bit degeri %d dir.\n", uval_u16, GET_RAND_BIT(uval_u16, int));
        Sleep(35);
    } while (!kbhit());
}


int main(void)
{
    UINT16 uval_u16 = 0;

    printf("The beginning bit status is : ");
    bit_print(uval_u16);

    randomize();
    while (!kbhit() || toupper(_getch() )!= EXIT )
    {
        set_bit(uval_u16);
        reset_bit(uval_u16);
        flip_bit(uval_u16);
    }

    return 0;
}

