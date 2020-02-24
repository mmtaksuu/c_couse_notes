/**
 * @file    : codility project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 17 / February / 2020
 * @code    : CyclicRotation.c file
 * @details :
 */

#include <stdio.h>
#include "../../helper.h"

#define     SIZE              10

typedef struct {
    int * A;
    int N; // Length of the array
} Results;

Results solution(int A[], int N, int K);


int main(void)
{

    int a[SIZE];
    set_random_array(a, SIZE, 2);
    int rotation_numbers = 7;


    printf("Given   : = ");
    display_array(a, SIZE);

    Results test_t;

    test_t = solution(a, SIZE, rotation_numbers);

    printf("Rotated : = ");
    display_array(test_t.A, (size_t)test_t.N);

    return 0;
}


/**
 *
 * @param A
 * @param N
 * @param K
 * @return
 */
Results solution(int A[], int N, int K)
{
    Results result_t;

    if (K == 0 || K == N){
        result_t.A = A;
        result_t.N = N;
        return result_t;
    }

    else if (K > N){
        K = K % N;
    }

    int remaining_elem_num = (N - K);
    int * pRem_elems = (int *) malloc(sizeof(int) * remaining_elem_num);

    for (int i = 0; i < remaining_elem_num; ++i) {
        pRem_elems[i] = A[i];
    }

    for (int i = 0; i < N; ++i) {

        if (i < K){
            A[i] = A[remaining_elem_num + i];
        }
        else{
            A[i] = pRem_elems[i - K];
        }
    }

    free(pRem_elems);

    result_t.A = A;
    result_t.N = N;

    return result_t;
}
