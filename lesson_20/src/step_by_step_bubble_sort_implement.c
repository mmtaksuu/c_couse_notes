/*
  Project Name: LESSON_20
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 25 / January / 2020	
  File Description: main.c file indicates step by step bubble sort algorithm implementation
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define     SIZE            40
#define     randomize()     (srand((unsigned)time(NULL)))


void set_random_array(int *p, int size)
{
    for (int i = 0; i < size; ++i) {
        p[i] = rand() % 20;
    }
}


void display_array(int *p, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%2d%c", p[i], i % 20 == 19 ? '\n' : ' ');
    }
}


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
            if (p[k] > p[k+1])
            {
                swap_array_items(&p[k], &p[k+1]);
            }
        }

        printf("%d th sorting operation : \n", i+1);
        _getch();
        system("cls");
        display_array(p, size);
    }
}


int main(void)
{
    int a[SIZE];

    randomize();

    // Fill array with random numbers
    set_random_array(a, SIZE);

    printf("\nUnsorted Array : \n");
    display_array(a, SIZE);

    // Sort this array using bubble short algorithm
    do_bubble_sort(a, SIZE);

    printf("\nSorted Array : \n");
    display_array(a, SIZE);

    return 0;
}
