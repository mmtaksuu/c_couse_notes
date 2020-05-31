/**
 * @file    : LESSON_13 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 31 / May / 2020
 * @code    : plots_random_numbers_dynamically.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"


void set_arr(int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        *p++ = rand() % 25;
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
    while (!is_hit_button('Q')) {

        size_t size = (size_t)rand() % 30u + 5u;

        int *pd = (int *)malloc(size * sizeof(int));
        if (!pd) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        randomize();
        set_arr(pd, size);
        display_array(pd, size);
//        qsort(pd, n, sizeof(*pd), &icmp);

        printf("\n\n+-----------------------------------------------------------------------------+\n\n");
        plot_rand_numbers(pd, size);
        printf("\n\n+-----------------------------------------------------------------------------+\n\n");

        delay(0.5);
        system("cls");
        memset(pd, 0, sizeof(*pd) * size);
        free(pd);
    }

    return 0;
}

