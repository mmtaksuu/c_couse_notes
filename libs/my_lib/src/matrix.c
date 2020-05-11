/**
 * @file    : MY_LIB project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / Mayıs / 2020
 * @code    : matrix.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "helper.h"


HMATRIX create_matrix(size_t row, size_t col)
{
    HMATRIX hmatrix;

    if ((hmatrix = (HMATRIX)malloc(sizeof(MATRIX))) == NULL )
        return NULL;

    if ((hmatrix->pData = (DATATYPE *)malloc(row * col * sizeof(DATATYPE))) == NULL) {
        free(hmatrix);
        return NULL;
    }

    memset(hmatrix->pData, 0, sizeof(DATATYPE)* row * col);

    hmatrix->row = row;
    hmatrix->col = col;

    return hmatrix;
}

void set_matrix(HMATRIX hmatrix, const DATATYPE *pSet)
{
    for (size_t i = 0; i < hmatrix->row * hmatrix->col; ++i) {
        hmatrix->pData[i] = pSet[i];
    }
}

DATATYPE get_matrix_item(HMATRIX hmatrix, size_t row, size_t col)
{
    return hmatrix->pData[hmatrix->col * row + col];
}

void set_matrix_item(HMATRIX hmatrix, size_t row, size_t col, DATATYPE set_val)
{
    hmatrix->pData[row * col + col] = set_val;
}

void random_matrix(HMATRIX hmatrix)
{
    for (size_t i = 0; i < hmatrix->col * hmatrix->row; ++i) {
        hmatrix->pData[i] = gen_rand_int_nums();
    }
}

void display_matrix(HMATRIX hmatrix)
{
    for (size_t i = 0; i < hmatrix->row * hmatrix->col; ++i)
        printf("%-5d%c", hmatrix->pData[i], i % hmatrix->col == hmatrix->col - 1 ? '\n' : ' ');

    printf("\n------------------------------------------------\n");
}

void close_matrix(HMATRIX hmatrix)
{
    free(hmatrix->pData);
    free(hmatrix);
}
