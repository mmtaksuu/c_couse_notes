/**
 * @file    : LESSON_13 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 31 / May / 2020
 * @code    : uniqe_numbers_finder.c file
 * @details :
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "helper.h"

#define     SIZE              20

int * find_unique_numbers(const int *p, size_t size, int *p_unique)
{
    size_t j;

    for (size_t i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            if (p[i] == p[j] && i != j)
                break;
        }
        if (j == size)
            *p_unique++ = p[i];
    }

    *p_unique = -1;

    return p_unique;
}

void print_unique_numbers(const int *p_unique, size_t size)
{
    printf("\nUnique numbers : \n");
    for (size_t i = 0; i < size && p_unique[i] != -1; ++i) {
        printf("%3d%c", p_unique[i], i % 20 == 19 ? '\n' : ' ');
    }
    printf("\n-------------------------------------------------------------------------------\n");
}


int main(void)
{
    int a[SIZE] = {0};
    int unique[SIZE] = {0};

    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);

    find_unique_numbers(a, SIZE, unique);
    print_unique_numbers(unique, SIZE);

    return 0;
}

