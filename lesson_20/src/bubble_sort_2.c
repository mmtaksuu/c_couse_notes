/*
  Project Name: LESSON_20
  Author: MEHMET AKSU
  Author Email: mmtaksu.25@gmail.com
  Date: 25 / January / 2020
  File Description: main.c file
  Requirements: tekler başta (kendi içinde sirali)
                çiftler sonda (kendi içinde sirali)
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../libs/my_lib/include/helper.h"

#define     SIZE            60


void swap_array_items(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


void do_bubble_sort(int *p, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int k = 0; k < size - 1 - i; ++k)
        {
            // Swap isleminin yapilmasi durumlari
            // Case 1: Ardisik elemanlarin teklik ciftlik kontrolunun yapilmasi,
            // Bu durumda yer degisiminin yapilabilmesi icin a[k] cift, a[k+1] tek olmalidir.
            // (a[k] % 2 == 0 && a[k+1] % 2 != 0) 1. terim cift 2.terim tek ise swap olsun.

            // Case 2: Ardisik elemanlarin tek-cift durumlari ayni ve a[k] > a[k+1] oldugu durumdur.
            // ((a[k] % 2 == a[k+1] % 2) && a[k] > a[k+1])

            if ((p[k] % 2 == 0 && p[k+1] % 2 != 0) || ((p[k] % 2 == p[k+1] % 2) && p[k] > p[k+1]))
            {
                swap_array_items(&p[k], &p[k+1]);
            }
        }
    }
}


int main(void)
{
    int a[SIZE];

    randomize();

    // Fill array with random numbers
    set_random_array(a, SIZE, 2);

    printf("\nUnsorted Array : \n");
    display_array(a, SIZE);

    // Sort this array using bubble short algorithm
    do_bubble_sort(a, SIZE);

    printf("\nSorted Array : \n");
    display_array(a, SIZE);

    return 0;
}
