/**
 * @file    : LESSON_13 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 02 / Ocak / 2020
 * @code    : recursive_and_iterative_power_func.c file
 * @details : This file indicates programmer to compare recursive and iterative function declaration.
 */

#include <stdio.h>
#include <time.h>


double recursive_power(int base, int exp)
{
    return exp == 0 ? 1 : base * recursive_power(base,exp -1);
}


double iterative_power(int base, int exp)
{
    double result = 1.;

    if (exp == 0)
        return 1;

    while(exp--)
        result *= base;

    return result;
}


int main(void)
{
    int x, y;
    printf("Enter 2 value to get power : ");
    scanf("%d%d", &x, &y);

    clock_t start1 = clock();
    double res1 = recursive_power(x,y);
    clock_t end1 = clock();
    printf("%d power %d is %.5f\n", x, y, res1);
    printf("Total time %.20f seconds \n", (double)(end1 - start1) / CLOCKS_PER_SEC);


    clock_t start2 = clock();
    double res2 = iterative_power(x,y);
    clock_t end2 = clock();
    printf("%d power %d is %.5f\n", x, y, res2);
    printf("Total time %.20f seconds \n", (double)(end2 - start2) / CLOCKS_PER_SEC);

    return 0;

}
