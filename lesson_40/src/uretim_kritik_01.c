/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : uretim_kritik_01.c file
 * @details : 
 */

#include <stdio.h>


int main(void)
{
    unsigned int x;
    printf("bir tamsayi girin: ");
    scanf("%u", &x);

    x = ~-x;     // x'in degerini bir azaltir.
    printf("x = %d\n", x);

    x = -~x;    // x'in degerini bir artirir.
    printf("x = %d\n", x);

    return 0;
}

