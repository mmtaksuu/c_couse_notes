/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / May / 2020
 * @code    : defining_ptr_array.c file
 * @details : 
 */

#include <stdlib.h>
#include <stdio.h>
#include "helper.h"

int main(void)
{
    randomize();

    double dx = gen_rand_real_nums();
    double dy = gen_rand_real_nums();
    double dz = gen_rand_real_nums();

    double *p_arr[] = { &dx, &dy, &dz };

    printf("sizeof(p_arr)     : %u Bytes\n", sizeof(p_arr));    //12
    printf("sizeof(*p_arr)    : %u Bytes\n", sizeof(*p_arr));   //4
    printf("sizeof(p_arr[0])  : %u Bytes\n", sizeof(p_arr[0]));  //4
    printf("sizeof(**p_arr)   : %u Bytes\n", sizeof(**p_arr));   //8

    return 0;
}
