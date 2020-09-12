/**
 * @file    : LESSON_34 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / September / 2020
 * @code    : realloc_func_usage.c file
 * @details : 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define     randomize()       (srand((unsigned)time(NULL)))


void set_rand_arr(int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        p[i] = rand() % 100 + 15;
    }
}

void display_arr(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%3d%c", p[i], i%10==9 ? '\n' : ' ');
    }
    printf("\n\n");
}

int main(void)
{
    printf("Enter number of member : ");
    size_t n = 0;
    scanf("%u", &n);

    int * pd = (int *)malloc(n * sizeof(*pd));
    if (!pd) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    randomize();

    set_rand_arr(pd, n);
    display_arr(pd, n);

    printf("Address returned from malloc : (%p)\n", pd);

    printf("Enter increase of the number of member : ");
    size_t n_plus = 0;
    scanf("%u", &n_plus);

    size_t new_size = n + n_plus;

    pd = (int *)realloc(pd, new_size*sizeof(*pd));
    if (!pd) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }

    set_rand_arr(pd, new_size);
    display_arr(pd, new_size);

    printf("Address returned from realloc : (%p)\n", pd);

    free(pd);

    return 0;
}


