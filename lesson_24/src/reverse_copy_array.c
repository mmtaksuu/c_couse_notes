/**
 * @file    : LESSON_24 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / March / 2020
 * @code    : reverse_copy_array.c file
 * @details : 
 */


#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define     asize(a)        (sizeof(a) / sizeof(a[0]))
#define     randomize()     (srand((unsigned)time(NULL)))
#define     SIZE            10


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
    printf("-----------------------------------------------\n");
}


int* reverse_copy_array(int *pdest, const int *psrc, size_t size)
{
    int * ptemp = pdest;
    int * pend  = (int*)(psrc + size);

    while (size--)
        *ptemp++ = *--pend;

    return pdest;
}

int main(void)
{
    int src_arr[SIZE];
    int dst_arr[SIZE];

    randomize();
    set_random_array(src_arr, asize(src_arr));

    printf("Source Array      : ");
    display_array(src_arr, SIZE);

    reverse_copy_array(dst_arr, src_arr, SIZE);

    printf("Destination Array : ");
    display_array(dst_arr, SIZE);

    return 0;
}

