/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : uretim_kritik_03.c file
 * @details : 
 */

#include <stdio.h>

int main(void)
{

    int x;
    printf("Enter a value : ");
    scanf("%d", &x);

    if ( x & 1 )          /// Girilen sayinin 0.inci bitinin lojik 1 ile kontrolu dogruysa sayi tektir, degilse cift.
        printf("Tek sayi\n");
    else
        printf("Cift sayi\n");

    return 0;
}

