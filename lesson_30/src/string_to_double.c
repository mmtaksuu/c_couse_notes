/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : string_to_double.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[100];
    printf("Enter a val : ");
    scanf("%s", str);

    char *p;
    double dval = strtod(str, &p);

    printf("dval           = %f\n", dval);
    printf("basamak sayisi = %d\n", p - str);
    printf("(%d)\n", *p);

    return 0;
}
