/**
 * @file    : LESSON_19 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 13 / June / 2020
 * @code    : ders19.c file
 * @details : 
 */

#include <stdio.h>
#include <conio.h>
#include "helper.h"
#include "statistics.h"
#include "sorting_algorithms.h"

#define     SIZE    50

int callback(int x, int y)
{
    return x < y;
}

int partition(int * p, int low, int high, int(*fp)(int, int))
{
    int i = low - 1;
    int pivot = p[high - 1];

    for (int j = low; j < high - 1; ++j) {
        if (fp(p[j], pivot)) {
            i++;
            iswap(&p[i], &p[j]);
        }
    }
    iswap(&p[i+1], &p[high - 1]);

    return i+1;
}

void quick_sort(int * p, int start, int end)
{
    if (start < end)
    {
        int pp = partition(p, start, end, callback);
        quick_sort(p, start, pp - 1);
        quick_sort(p, pp + 1, end);
    }
}


int main(void)
{
    int c[SIZE] = {0};
    randomize();
    system("cls");
    set_random_array(c, SIZE);

    display_array(c, SIZE);
    hist_rand_numbers(c, SIZE);
    printf("\n+--------------------------+\n\n");

    //insertion_sort(c, SIZE);
    //selection_sort(c, SIZE);
    quick_sort(c, 0, SIZE);

    display_array(c, SIZE);
    hist_rand_numbers(c, SIZE);
    printf("\n+--------------------------+\n\n");


    return 0;
}
