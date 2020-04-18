/**
 * @file    : LESSON_17 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 18 / April / 2020
 * @code    : mt_impl_01.c file
 * @details : 
 */

#include "mersenne_twister.h"
#include <stdio.h>

int main(void)
{
    int i;
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, (int) length);

//    printf("1000 outputs of genrand_int32()\n");
//    for (i=0; i<1000; i++) {
//        printf("%10lu ", genrand_int32());
//        if (i%5==4) printf("\n");
//    }

    printf("\n\n");
    printf("\n1000 outputs of genrand_real2()\n");
    for (i=0; i<1000; i++) {
        printf("%10.8f ", genrand_real2());
        if (i%5==4) printf("\n");
    }

    return 0;
}
