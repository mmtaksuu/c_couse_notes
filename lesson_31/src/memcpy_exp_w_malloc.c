/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 10 / May / 2020
 * @code    : memcpy_exp_w_malloc.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"

#define     SIZE              100

int main(void)
{
    int src[SIZE] = {0};

    set_random_array(src, asize(src));
    printf("Source array : \n");
    display_array(src, asize(src));

    size_t start_idx, end_idx = 0;
    printf("Enter start and end idx : ");
    scanf("%u%u", &start_idx, &end_idx);

    size_t n_of_items = (end_idx-start_idx);
    int * pdest = malloc(n_of_items * sizeof(*src));
    if (!pdest) {
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }

    memcpy(pdest, src+start_idx, n_of_items*sizeof(*src));
    printf("Destination array : \n");
    display_array(pdest, n_of_items);

    free(pdest);

    return 0;
}


