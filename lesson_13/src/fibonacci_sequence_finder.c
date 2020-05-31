/**
 * @file    : LESSON_13 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 31 / May / 2020
 * @code    : fibonacci_sequence_finder.c file
 * @details :
 */

#include <stdio.h>
#include <stdlib.h>


// Defines recursive fibonacci function.
int fibonacci_recursive(int n)
{
    return n < 2 ? n : fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Defines Iterative fibonacci function.
int fibonacci_iterative(int n)
{
    if (n < 2)
        return n;

    // Rule is xn = xn−1 + xn−2
    int x[45] = {0, 1};

    for (int i = 2; i <= n; ++i) {
        x[i] = x[i-1] + x[i-2];
    }
    return x[n];
}

void create_fibonacci_lookup_table(void)
{
    FILE *fptr;

    fptr = fopen("../src/fibonacci_sequence.txt", "w");

    if (!fptr){
        printf("File couldn't created !\n");
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fprintf(fptr, "int fibonacci_sequence[] = {\n");
    for (int i = 0; i < 46; ++i)
    {
        fprintf(fptr, "%d,\n", fibonacci_recursive(i));
    }
    fprintf(fptr, "};");

    fclose(fptr);
}


int fibonacci_lookup(int n)
{
    if (n < 0 || n > 46)
        return -1;

    int fibonacci_sequence[] = {
            0,
            1,
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
    };

    return fibonacci_sequence[n];
}


int main(void)
{
    //create_fibonacci_lookup_table();

    //------------------------------------------------//
    printf("\n Calculates Fibonacci Series using Iterative Function.\n");
    for (int i = 0; i < 20; ++i) {
        printf("%2d --> %d\n", i, fibonacci_iterative(i));
    }


    //------------------------------------------------//
    printf("\n Calculates Fibonacci Series using Recursive Function.\n");
    for (int i = 0; i < 20; ++i) {
        printf("%2d --> %d\n", i, fibonacci_recursive(i));
    }


    //------------------------------------------------//
    printf("\n Calculates Fibonacci Series using Look-up Table.\n");
    for (int i = 0; i < 20; ++i) {
        printf("%2d --> %d\n", i, fibonacci_lookup(i));
    }

    return 0;
}
