/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : uretim_kritik_05.c file
 * @details : 
 */

#include <stdio.h>

#define     powof2(x)    ((x) && !((x) & ((x) - 1)))

// Girilen bir sayinin ikinin kuvveti olup olmadiginin kontrolu

int main(void)
{
    int ival;
    printf("Enter a value : ");
    scanf("%d", &ival);

    if powof2(ival)
    {
        printf("Girilen deger 2.inin kuvveti\n");
    }
    else
    {
        printf("Girilen deger 2.inin kuvveti degil\n");
    }

    return 0;
}
