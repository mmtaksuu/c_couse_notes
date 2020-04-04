/**
 * @file    : LESSON_24 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / March / 2020
 * @code    : array_traversal.c file
 * @details : 
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define     asize(a)        (sizeof(a) / sizeof(a[0]))
#define     randomize()     (srand((unsigned)(time(NULL))))


void set_random_arr(int *p, size_t size)
{
    while (size--)
        *p++ = rand() % 10;
}

void display_array(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%d%c", p[i], i % size == size-1 ? '\n' : ' ');
    }
    printf("--------------------------------------\n");
}


int main(void)
{
    int a[10];

    randomize();
    set_random_arr(a, asize(a));

    display_array(a, asize(a));
    display_array(a, 3);
    display_array(a+5, 5);


    return 0;
}
