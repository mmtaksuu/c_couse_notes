/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / April / 2020
 * @code    : uretim_kritik_02.c file
 * @details : 
 */

#include <stdio.h>


int main(void)
{
    int x, y;
    printf("Enter two value : ");
    scanf("%d%d", &x, &y);

    if ((x ^ y) < 0)  ///* Iki sayinin isaret bitlerinin ayni olup olmadiginin kontrolu */
    {
        printf("Zit isaretliler\n");
    }
    else
    {
        printf("Ayni isaretliler.\n");
    }

    return 0;
}


