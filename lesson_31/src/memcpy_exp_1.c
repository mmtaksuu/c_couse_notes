/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 10 / May / 2020
 * @code    : memcpy_example_1.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"

#define     SIZE              100

int main(void)
{
    int src[SIZE] = {0};
    int dst[SIZE] = {0};

    set_random_array(src, asize(src));
    printf("Source array : \n");
    display_array(src, asize(src));

    size_t start_idx, end_idx = 0;
    printf("Enter start and end idx : ");
    scanf("%u%u", &start_idx, &end_idx);

    memcpy(dst+start_idx, src+start_idx, (end_idx-start_idx)*sizeof(*src));
    printf("Destination array : \n");
    display_array(dst, asize(dst));

    return 0;
}

