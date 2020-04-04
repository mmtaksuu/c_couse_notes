/**
 * @file    : LESSON_24 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / March / 2020
 * @code    : reverse_array.c file
 * @details : 
 */


#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define     asize(a)        (sizeof(a) / sizeof(a[0]))
#define     randomize()     (srand((unsigned)(time(NULL))))



void set_random_array(int *p, size_t size)
{
    while (size--)
        *p++ = rand() % 10;
}

void display_array(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%d%c", p[i], i % size == size-1 ? '\n' : ' ');
    }
    printf("-----------------------------\n");
}

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1  = *p2;
    *p2  = temp;
}

void reverse_array(int *p, size_t size)
{
    int *pend = p + size;
    size_t n = size / 2;

    while (n--)
        swap(p++, --pend);
}


int main(void)
{
    int a[10];

    randomize();
    set_random_array(a, asize(a));
    display_array(a, asize(a));
    reverse_array(a, asize(a));
    display_array(a, asize(a));


    return 0;
}

