/**
 * @file    : LESSON_34 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / September / 2020
 * @code    : generate_rand_2d_solid_array.c file
 * @details : 
 */


#include <stdio.h>
#include <stdlib.h>

int * gen_rand_2D_solid_arr (size_t row, size_t col)
{
    int *pd = (int *)malloc(row * col * sizeof(*pd));
    if (!pd) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    return pd;
}

void destroy_2D_solid_arr (int * pd)
{
    free(pd);
}


void clear_2D_solid_arr (int * pd, size_t row, size_t col)
{
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            pd[i * col + j] = 0;
        }
    }
}

void set_rand_2D_solid_arr (int * pd, size_t row, size_t col)
{
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            pd[i * col + j] = rand() % 100 + 15;
        }
    }
}

void display_2D_solid_arr (int * pd, size_t row, size_t col)
{
    printf("\n");
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            printf("%3d%c", pd[i * col + j], (j%col == col-1) ? '\n' : ' ');
        }
    }
    printf("\n\n");
}


int main(void)
{
    printf("Enter row and col : ");
    size_t row = 0, col = 0;
    scanf("%u%u", &row, &col);

    int *pd = gen_rand_2D_solid_arr(row, col);
    clear_2D_solid_arr(pd, row, col);

    set_rand_2D_solid_arr(pd, row, col);

    display_2D_solid_arr(pd, row, col);
    destroy_2D_solid_arr(pd);

    return 0;
}




