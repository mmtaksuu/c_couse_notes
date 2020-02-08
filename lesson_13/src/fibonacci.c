/*
  Project Name: LESSON_13
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 03 / Ocak / 2020	
  File Description: fibonacci.c file displays the Fibonacci sequence of first n numbers (entered by the user)
*/

#include <stdio.h> // For printf, scanf, etc.
#include <time.h>  // For clock() func. and CLOCKS_PER_SEC etc.
#include <conio.h> // For _getch() func.

// The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21

// Define recursive fibonacci function.
int fibo_r(int n)
{
    return n < 2 ? n :  fibo_r(n - 1) + fibo_r(n - 2);
}

// Define Iterative fibonacci function.
int fibo_i(int n)
{
    if (n < 2)
        return n;

    int t1 = 0, t2 = 1, nextTerm = 0;

    for (int i = 1; i <= n; ++i)
    {
        //printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return nextTerm;
}

void create_fibonacci_lookup_table(void)
{
    FILE *fptr;

    fptr = fopen("../src/fibonacci_series.txt", "w");

    if (fptr == NULL)
        printf("File couldn't created !\n");

    fprintf(fptr, "int fibo_arr[] = {\n");
    for (int i = 0; i < 46; ++i)
    {
        fprintf(fptr, "%d,\n", fibo_i(i));
    }
    fprintf(fptr, "};");
}


int fibo_lookup(int n)
{
    int fibo_arr[] = {
                        0,
                        1,
                        2,
                        3,
                        5,
                        8,
                        13,
                        21,
                        34,
                        55,
                        89,
                        144,
                        233,
                        377,
                        610,
                        987,
                        1597,
                        2584,
                        4181,
                        6765,
                        10946,
                        17711,
                        28657,
                        46368,
                        75025,
                        121393,
                        196418,
                        317811,
                        514229,
                        832040,
                        1346269,
                        2178309,
                        3524578,
                        5702887,
                        9227465,
                        14930352,
                        24157817,
                        39088169,
                        63245986,
                        102334155,
                        165580141,
                        267914296,
                        433494437,
                        701408733,
                        1134903170,
                        1836311903,
                        };

    return fibo_arr[n];
}


int main(void)
{
    //create_fibonacci_lookup_table();


    //------------------------------------------------//
    printf("\n Calculates Fibonacci Series using Iterative Function.\n");
    _getch();
    clock_t start2 = clock();
    int b[50];

    for (int i = 0; i < 47; ++i) {
        b[i] = fibo_i(i);
    }
    clock_t end2 = clock();
    printf("%.12f saniye\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

    _getch();

    for (int i = 0; i < 47; ++i) {
        printf("%d    %d\n", i, b[i]);
    }



    //------------------------------------------------//
    printf("\n Calculates Fibonacci Series using Recursive Function.\n");
    _getch();
    clock_t start1 = clock();
    int a[50];

    for (int i = 0; i < 47; ++i) {
        a[i] = fibo_r(i);
    }
    clock_t end1 = clock();
    printf("%.12f saniye\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

    _getch();

    for (int i = 0; i < 47; ++i) {
        printf("%d    %d\n", i, a[i]);
    }



    //------------------------------------------------//
    printf("\n Calculates Fibonacci Series using Look-up Table.\n");
    _getch();
    clock_t start3 = clock();

    for (int i = 0; i < 46; ++i) {
        printf("%d    %d\n", i, fibo_lookup(i));
    }
    clock_t end3 = clock();
    printf("%.12f saniye\n", (double)(end3 - start3) / CLOCKS_PER_SEC);

    return 0;
}
