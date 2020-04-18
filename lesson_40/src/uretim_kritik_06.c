/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : uretim_kritik_06.c file
 * @details : 
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>


// 1111 1010 1011 1100 0011 1101 1110 1010

//little endian
// FA
// BC
// 3D
// EA


typedef union {
    unsigned int uval;
    unsigned char s[4];
}Data;


int main()
{
    //unsigned int x = 0xFABC3DEA;

    Data dx = { .uval = 0xFABC3DEA };

    printf("%X\n", dx.s[0]);
    printf("%X\n", dx.s[1]);
    printf("%X\n", dx.s[2]);
    printf("%X\n", dx.s[3]);

}