/*
  Project Name: LESSON_
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 17 / February / 2020	
  File Description: CyclicRotation.c file 
*/

#include <stdio.h>

#define     asize(x)          (sizeof(x) / sizeof (x[0]))

typedef struct {
    int * A;
    int N; // Length of the array
} Results;

Results solution(int A[], int N, int K);
void swap(int *, int *);


int main(void)
{
    int a[] = {3, 8, 9, 7, 6};
    int size = (int)asize(a);

    printf("Given   : = ");
    printf("[ ");
    for (int i = 0; i < size; ++i) {
        printf("%d%c ", a[i], i % size == size-1 ? ' ' : ',');
    }
    printf("]\n");


    Results result_t;

    result_t.A = a;
    result_t.N = size;
    result_t = solution(result_t.A, result_t.N, 3);


    printf("Rotated : = ");
    printf("[ ");
    for (int i = 0; i < result_t.N; ++i) {
        printf("%d%c ", *(result_t.A + i), i % result_t.N == result_t.N-1 ? ' ' : ',');
    }
    printf("]\n");


    return 0;
}


void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


Results solution(int A[], int N, int K)
{
    Results temp_t;

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N-1; ++j) {
            swap(&A[j], &A[j+1]);
//            if (j != N-1)
//                swap(&A[j], &A[j+1]);
//            else
//                swap(&A[j], &A[N-1]);
        }
    }


    temp_t.A = A;
    temp_t.N = N;

    return temp_t;
}
