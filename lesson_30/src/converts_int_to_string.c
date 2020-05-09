/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : main.c file
 * @details : Gets the int value from the input stream and converts to string
 */


#include <stdio.h>
#include <string.h>

int main(void)
{
    int ival;
    printf("Enter a value : ");
    scanf("%d", &ival);

    char str[100];
    int temp = ival;
    int idx = 0;

    while (temp)
    {
        str[idx++] = (char)(temp % 10 + '0');
        temp /= 10;
    }

    str[idx] = '\0';
    _strrev(str);
    printf("%s\n", str);

    return 0;
}

