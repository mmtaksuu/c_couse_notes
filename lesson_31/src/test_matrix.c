/**
 * @file    : MY_LIB project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / Mayıs / 2020
 * @code    : test_matrix.c file
 * @details : 
 */


#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "helper.h"

int main(void)
{
    HMATRIX hmatrix;

    hmatrix = create_matrix(3, 3);
    display_matrix(hmatrix);

    randomize();
    random_matrix(hmatrix);
    display_matrix(hmatrix);

    printf("matrix[%d][%d] = %d\n", 2, 3, get_matrix_item(hmatrix, 1, 2));
    close_matrix(hmatrix);

    return 0;
}
