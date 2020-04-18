/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / April / 2020
 * @code    : random_set_reset_bits.c file
 * @details : 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define     randomize()       (srand((unsigned)time(NULL)))

void sleep(double sec)
{
    clock_t start = clock();

    while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}

void print_bits(int val)
{
    char str[40];

    _itoa(val, str, 2);
    printf("%032s\r", str);
}

int main()
{
    randomize();
    int x = 0;

    do
    {
        print_bits(x);
        x |= 1 << ((unsigned int) rand() % (sizeof(int) * 8));  // Random olarak bitlerin set edilmesi
        Sleep(35);
    } while (x != -1); // Isaretli bir tamsayinin tum bitleri bir ise degeri -1 olur.

    print_bits(x);
    Sleep(35);
    printf("\n\n");

    do
    {
        print_bits(x);
        x &= ~(1 << ((unsigned int) rand() % (sizeof(int) * 8)));  // Random olarak bitlerin reset edilmesi
        Sleep(35);
    } while (x);   // Isaretli bir tamsayinin tum bitleri 0 ise degeri 0 olur.

    print_bits(x);
    printf("\n\n");

    // Hepsi resetlenen bitlerin 1 tanesi flip yapar.
    x ^= 1 << (rand() % 32);
    Sleep(35);
    print_bits(x);

    return 0;
}
