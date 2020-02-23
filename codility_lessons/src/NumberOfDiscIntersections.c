/**
 * @file    : codility project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 17 / February / 2020
 * @code    : NumberOfDiscIntersections.c file
 * @details :
 */

#include <stdio.h>


int solution(const int A[], int N);


int main(void)
{

    int a[6] = {1, 5, 2, 1, 4, 0};

    int numOfDiscIntersection = solution(a, 6);
    printf("%d intersection is found!", numOfDiscIntersection);

    return 0;
}


int solution(const int A[], int N)
{
    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (((i + A[i]) >= (j - A[j])) && i != j){
                printf("A[%d] and A[%d] \n", i, j);
                ++cnt;
            }

        }
    }

    return cnt;
}
