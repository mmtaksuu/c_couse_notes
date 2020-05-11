/**
 * @file    : MY_LIB project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / Mayıs / 2020
 * @code    : matrix.h file
 * @details : 
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

typedef int DATATYPE;

typedef struct MATRIX_ {
    DATATYPE *pData;
    size_t row;
    size_t col;
}MATRIX, *HMATRIX;


/** Function Declerations */
HMATRIX create_matrix(size_t row, size_t col);
void set_matrix(HMATRIX hmatrix, const DATATYPE *pSet);
void random_matrix(HMATRIX hmatrix);
DATATYPE get_matrix_item(HMATRIX hmatrix, size_t row, size_t col);
void set_matrix_item(HMATRIX hmatrix, size_t row, size_t col, DATATYPE set_val);
void display_matrix(HMATRIX hmatrix);
void close_matrix(HMATRIX hmatrix);


#endif //MATRIX_H
