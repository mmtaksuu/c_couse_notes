/**
 * @file    : codility project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / March / 2020
 * @code    : FrogJump.c file
 * @details : 
 */

#include <stdio.h>

int solution(int X, int Y, int D);

int main(void)
{
    int X = 10;
    int Y = 85;
    int D = 30;

    int min_jump = solution(X, Y, D);
    printf("Min jump is %d \n", min_jump);

    return 0;
}


int solution(int X, int Y, int D)
{
    int jump_cnt = 0;
    int y = 0;

    /** y = m*x + b is a linear equation. */
    while (y < Y)
        y = D * ++jump_cnt + X;

    return jump_cnt;

}