/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : uretim_kritik_04.c file
 * @details : 
 */


#include <stdio.h>
#include <basetsd.h>
#include <stdint.h>
#include <stdlib.h>

// 16 Bitlik bir tam sayinin ortasindaki 8 bitlik degerin get edilmesi

// 0000 0000 1111 1111     255  0X00FF
// 0000 1111 1111 0000    4080  0X0FF0  x <<= 4
// 0000 0000 0000 1111      15  0X000F  x >>= 8
//-----------------------------------------------

// 1111 1111 1111 1111    65535  0XFFFF
// 1111 1111 1111 0000    65520  0XFFF0  x <<= 4
// 0000 0000 1111 1111      255  0X00FF  x >>= 8
//-----------------------------------------------


void print_bits(int val)
{
    char str[20];
    _itoa(val, str, 2);
    printf("%016s\n", str);
}


int main()
{
    UINT16 x = 255;

    printf("%hu %X\n", x, x);
    print_bits(x);

    x <<= 4;
    printf("%hu %X\n", x, x);
    print_bits(x);

    x >>= 8;
    printf("%hu %X\n", x, x);
    print_bits(x);

    /*x = x << 4 >> 8;
    printf("%hu %X\n", x, x);
    print_bits(x);*/

    return 0;
}