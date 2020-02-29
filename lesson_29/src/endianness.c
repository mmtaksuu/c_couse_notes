/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 29 / February / 2020
 * @code    : endianness.c file
 * @details : Sistemde tanimlanan bir degiskenin dusuk anlamli biti LSB yuksek sayisal adreste tutuluyor ise little endian mimaridir.
 */

#include <stdio.h>

int main(void)
{
    int x = 1;  // 0000 0000 0000 0000 0000 0000 0000 0001  4 Bytes (32 Bits)  0x0001 hex
    char *p = (char *)&x;

    size_t size = sizeof(x);
    printf("%u Bits\n", size);

    for (size_t i = 0; i < size; ++i) {
        printf("%d\n", *(p+i));
    }

    if (*p != 0) // Verilen adresteki ilk indise bakilir.
        printf("%d little endian\n", *p);
    else
        printf("big endian\n");

    return 0;
}


