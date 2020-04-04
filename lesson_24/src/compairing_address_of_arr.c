/**
 * @file    : LESSON_24 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / March / 2020
 * @code    : compairing_address_of_arr.c file
 * @details : 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define     asize(a)        (sizeof(a) / sizeof(a[0]))


void set_random_array(int *p, size_t size)
{
    while (size--)
        *p++ = rand() % 10;
}


void display_array_v2(const int * pstart, const int * pend)
{
    size_t size = (size_t) (pend - pstart);

    for (size_t i = 0; &pstart[i] != pend; ++i){
      printf("%d%c", pstart[i], i % size == size-1 ? '\n' : ' ');
    }
    printf("--------------------------\n");
}


int main(void)
{
    int a[10];

    set_random_array(a, asize(a));

    int * pstart = a;
    int * pend   = a + asize(a);

    display_array_v2(pstart, pend);
    display_array_v2(pstart+3, pend);
    display_array_v2(pstart+5, pend);
    display_array_v2(pstart+5, pend-2);

    return 0;
}

