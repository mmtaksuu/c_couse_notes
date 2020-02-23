/*
  Project Name: LESSON_20
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 24 / January / 2020	
  File Description: buble_short_1.c file sorts an array using bubble sort algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../helper.h"

#define     SIZE            40



void swap_array_items(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


void do_bubble_sort(int *p, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int k = 0; k < size - 1 - i; ++k) {
            if (p[k] > p[k+1]) {
                swap_array_items(&p[k], &p[k+1]);
            }
        }
    }
}


int main(void)
{
    int a[SIZE];

    randomize();

    // Fill array with random numbers
    set_random_array(a, SIZE, 3);

    printf("\nUnsorted Array : \n");
    display_array(a, SIZE);

    // Sort this array using bubble short algorithm
    do_bubble_sort(a, SIZE);

    printf("\nSorted Array : \n");
    display_array(a, SIZE);

    return 0;
}
