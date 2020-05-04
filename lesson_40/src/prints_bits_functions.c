/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : prints_bits_2.c file
 * @details : 
 */

#include <stdlib.h>
#include <stdio.h>

void print_bits_1(int val)
{
    char str[40];
    _itoa(val, str, 2);
    printf("%032s\n", str);
}

void print_bits_2(int val)
{
    unsigned mask = ~(~0u >> 1u);  // 10000000 00000000 00000000 00000000 = 2147483648

    while (mask)
    {
        putchar(val & mask ? '1' : '0');
        mask >>= 1;
    }
    putchar('\n');
}

void print_bits_3(int val)
{
    for (int i = (int)(sizeof(int) * 8 - 1); i >= 0; --i)
        putchar((val >> i) & 1 ? '1' : '0');

    putchar('\n');
}

int main(void)
{
    int ival;
    printf("Enter a value : ");
    scanf("%d", &ival);

    printf("\n");
    print_bits_1(ival);
    print_bits_2(ival);
    print_bits_3(ival);

    return 0;
}
