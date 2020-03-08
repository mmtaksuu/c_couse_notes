/**
 * @file    : codility project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / March / 2020
 * @code    : OddOccurrencesInArray.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>


#define     SIZE              7

int solution(int A[], int N);


int main(void)
{
    int a[SIZE] = {9, 7, 3, 7, 5, 9, 3, };

    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n-----------------------\n");

    int unpaired = solution(a, SIZE);
    printf("Unpaired value is %d \n", unpaired);

    return 0;
}


int solution(int A[], int N)
{
    int *pArr = (int *)calloc(N, sizeof(int));

    for (int i = 0; i < N; ++i)
        ++pArr[*(A+i)];

    int j;
    for (j = 0; j < N; ++j) {
        if (pArr[j] % 2 != 0)
            break;
    }

    free(pArr);
    pArr = NULL;

    return j;
}
