/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : atof_example.c file
 * @details : 
 */


#include <stdio.h>
#include <string.h>
#include "helper.h"
#include "statistics.h"

int main(void)
{
    char str[100];
    printf("Enter real numbers : ");
    sgets(str);

    double data[100] = {0};
    size_t i;

    char * token = strtok(str, " ");
    for (i = 0; token && i < asize(data); ++i)
    {
        data[i] = atof(token);
        token = strtok(NULL, " ");
    }

    display_array_d(data, i);

    printf("Sum of  is %.5f\n", sum_array(data, i));
    printf("Mean    is %.5f\n", get_mean(data, i));
    printf("Std dev is %.5f\n", get_std_dev(data, i));

    return 0;
}

