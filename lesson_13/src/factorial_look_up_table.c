/*
  Project Name: LESSON_13
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 03 / Ocak / 2020	
  File Description: factorial_look_up_table.c file 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int factorial(int x, FILE *f)
{
    int result = 1;

    if (x < 0)
        x = -x;

    // if x is 5 then result = 5 * 4 * 3 * 2 * 1 = 120
    for (int i = x; i >= 1; --i)
    {
        result *= i;
    }

    fprintf(f, "%d,", result);

    return result;
}

int main(void)
{
    FILE *fptr;

    fptr = fopen("../src/factorials_table.txt", "w");

    if (fptr == NULL)
        printf("File couldn't created !\n");

    fprintf(fptr, "int fac_arr[] = {\n");
    for (int i = 2; i <= 16; ++i)
    {
        factorial(i, fptr);
        fprintf(fptr, "\n");
    }
    fprintf(fptr, "};\n");

    return 0;
}


/*int fac_arr[] = {
2,
6,
24,
120,
720,
5040,
40320,
362880,
3628800,
39916800,
479001600,
1932053504,
1278945280,
2004310016,
2004189184,
};


int main(void)
{
    int x;
    printf("Enter a value between 2-16 : ");
    scanf("%d", &x);

    if (x >= 2 && x <= 16)
        printf("%d! --> %d \n", x, fac_arr[x-2]);
    else
        return printf("Invalid value !"), 1;

    return 0;
}*/
