/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / May / 2020
 * @code    : endianness_with_hex.c file
 * @details : 
 */

#include <stdio.h>

int main(void)
{
    unsigned int x = 0x12AE23BF;  // 4 Bytes
    unsigned char* p = (unsigned char *)&x;

    size_t size = sizeof(x);
    printf("%u Bytes\n", size);  // 4 Bytes (32 Bits)

    while (size--)
        printf("%X\n", *p++);

    return 0;
}
