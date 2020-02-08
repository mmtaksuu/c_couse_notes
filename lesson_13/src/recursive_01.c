/*
  Project Name: LESSON_13
  Author: MEHMET AKSU
  Author Email: mmtaksu.25@gmail.com
  Date: 02 / Ocak / 2020
  Description: recursive_01.c file
*/

#include <stdio.h>
#include <time.h>

int recursive_power(int base, int exp)
{
    return exp == 0 ? 1 : base * recursive_power(base,exp -1);
}

int iterative_power(int base, int exp)
{
    int result = 1;

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
    int res1 = recursive_power(x,y);
    clock_t end1 = clock();
    printf("%d power %d is %d\n", x, y, res1);
    printf("Total time %f seconds \n", (double)(end1 - start1) / CLOCKS_PER_SEC);

    clock_t start2 = clock();
    int res2 = iterative_power(x,y);
    clock_t end2 = clock();
    printf("%d power %d is %d\n", x, y, res2);
    printf("Total time %f seconds \n", (double)(end2 - start2) / CLOCKS_PER_SEC);

    return 0;

}
