/**
 * @file    : LESSON_13 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 31 / May / 2020
 * @code    : plots_random_numbers.c file
 * @details : 
 */

#include <stdio.h>
#include "helper.h"

#define     SIZE              20

void set_arr(int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        *p++ = rand() % 10;
    }
}

void plot_rand_numbers(const int *p, size_t size)
{
    int max = find_imax(p, size);

    for (int i = max; i > 0; --i) {
        printf("%2d |  ", i);
        for (size_t j = 0; j < size; ++j) {
            if (p[j] >= i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}



int main(void)
{
    int a[SIZE] = {0};

    randomize();
    set_arr(a, SIZE);
    display_array(a, SIZE);

    plot_rand_numbers(a, SIZE);

    return 0;
}
