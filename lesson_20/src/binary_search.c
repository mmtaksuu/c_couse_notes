/*
  Project Name: LESSON_20
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 25 / January / 2020	
  File Description: binary_search.c file shows Binary Search Algorithm Implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


#define     SIZE              20
#define     randomize()       (srand((unsigned)time(NULL)))


void set_random_array(int *p, int size)
{
    while (size--)
        *p++ = rand() % 50;
}


void display_array(const int *p, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%2d%c ", p[i], i % 20 == 19 ? '\n' : ' ');
    }
    printf("\n");
}


void swap_array_items(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


void bubble_sort_array(int *p, int size)
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
    }
}


void do_binary_search(int *p, int size, int desired_val)
{
    int idx_first = 0;
    int idx_last = size - 1;
    int idx_mid;

    int itr_counter = 0;

    while (idx_first <= idx_last) {
        ++itr_counter;

        idx_mid = (idx_first + idx_last) / 2;

        if (p[idx_mid] == desired_val)
            break;

        if (p[idx_mid] < desired_val)
            idx_first = idx_mid + 1;
        else
            idx_last = idx_mid - 1;
    }

    if (idx_first > idx_last) {
        printf("Desired Value was not found!\n");
    }
    else {
        printf("Found at arr[%d] = %d\n", idx_mid+1, p[idx_mid]);
    }

    printf("%d number of iteration(s) has done!", itr_counter);

}


int main(void)
{
    int a[SIZE];

    randomize();

    set_random_array(a, SIZE);
    bubble_sort_array(a, SIZE);
    display_array(a, SIZE);

    int desired;
    printf("Enter a value : ");
    scanf("%d", &desired);


    printf("To start the binary search hit the Enter Button!\n");
    _getch();

    do_binary_search(a, SIZE, desired);

    return 0;
}




