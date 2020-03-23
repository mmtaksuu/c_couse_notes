/**
 * @file    : c_programing_course project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 15 / March / 2020
 * @code    : main.c file
 * @details : 
 */

#include <stdio.h>
#include "test.h"


int main(void)
{
    Data_t test_data_t = data_init;

    printf("test_data_t.x = %d\n", test_data_t.x);
    printf("test_data_t.y = %d\n", test_data_t.y);
    printf("test_data_t.z = %d\n", test_data_t.z);

    return 0;
}


