/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 29 / February / 2020
 * @code    : endianness_with_binary.c file
 * @details : Sistemde tanimlanan bir degiskenin dusuk anlamli biti LSB yuksek sayisal adreste tutuluyor ise little endian mimaridir.
 */

#include <stdio.h>
#include <basetsd.h>


int main(void)
{
    UINT32 uval = 1;

    unsigned char * p = (unsigned char *)&uval;

    if (*p)
        printf("Your system is little endian\n"); // 0000 0000 0000 0000 0000 0000 0000 0001
    else
        printf("Your system is big endian\n");    // 0001 0000 0000 0000 0000 0000 0000 0000


    size_t size = sizeof(uval);
    printf("%u Bytes\n", size);  // 4 Bytes (32 Bits)

    while (size--)
        printf("%d\n", *p++);

    return 0;
}





