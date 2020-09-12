/**
 * @file    : LESSON_34 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / September / 2020
 * @code    : generate_rand_2d_hibrit_matrix.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>

int *  GL_pd_solid  = NULL;
int ** GL_pd_hibrit = NULL;

int ** gen_rand_2D_hibrit_matrix (size_t row, size_t col)
{
    GL_pd_solid = (int *)malloc(row * col * sizeof(int));
    if (!GL_pd_solid) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    GL_pd_hibrit = (int**)malloc(row * sizeof(int));
    if (!GL_pd_hibrit) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            GL_pd_hibrit[i] = GL_pd_solid + i * col;
        }
    }

    return GL_pd_hibrit;
}

void destroy_2D_hibrit_matrix (int ** pd, int *p, size_t row)
{
    for (size_t i = 0; i < row; ++i) {
        free(pd[i]);
    }
    free(p);
}


void clear_2D_hibrit_matrix (int ** pd, size_t row, size_t col)
{
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            pd[i][j] = 0;
        }
    }
}

void set_rand_2D_hibrit_matrix (int ** pd, size_t row, size_t col)
{
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            pd[i][j] = rand() % 100 + 15;
        }
    }
}

void display_2D_hibrit_matrix (int * const * pd, size_t row, size_t col)
{
    printf("\n");
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            printf("%3d%c", pd[i][j], (j%col == col-1) ? '\n' : ' ');
        }
    }
    printf("\n\n");
}



int main(void)
{
    printf("Enter row and col : ");
    size_t row = 0, col = 0;
    scanf("%u%u", &row, &col);

    int **pd = gen_rand_2D_hibrit_matrix(row, col);
    clear_2D_hibrit_matrix(pd, row, col);

    set_rand_2D_hibrit_matrix(pd, row, col);

    display_2D_hibrit_matrix(pd, row, col);
    destroy_2D_hibrit_matrix(pd, GL_pd_solid, row);

    return 0;
}


