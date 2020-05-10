/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 01 / March / 2020
 * @code    : fill_array_w_memset.c file
 * @details : void *memset(void *vp, int val, size_t n);
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"

#define     SIZE              100


int main(void)
{
    int a[SIZE];

    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);

    size_t start_idx, n_of_items;
    int set_val;
    printf("Enter start_idx, n_of_items and set_val: ");
    scanf("%u%u%d", &start_idx, &n_of_items, &set_val);

    memset(a + start_idx, set_val, n_of_items * sizeof(*a));

    printf("\n");
    display_array(a, SIZE);

    return 0;
}


