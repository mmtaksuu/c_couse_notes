/*
  Project Name: LESSON_20
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 25 / January / 2020	
  File Description: merge_algorithm.c file 
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>


#define     SIZE              10
#define     randomize()       (srand((unsigned)time(NULL)))
#define     asize(x)          (sizeof(x) / sizeof (x[0]))



void set_random_array(int *p, int size)
{
    while (size--)
        *p++ = rand() % 50;
}

void display_array(const int *p, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%3d%c", p[i], i % 20 == 19 ? '\n' : ' ');
    }
    printf("\n");
}

int icmp(const void *vp1, const void *vp2)
{
    return *(const int *)vp1 - *(const int *)vp2;
}

void qsort_sort_array(int *p, int size)
{
    qsort(p, (size_t) size, sizeof(*p), &icmp);
}


void step_by_step_merging(const int *arr, int size)
{
    for (int j = 0; j < size; ++j) {
        printf("%d%c", arr[j], j % 20 == 19 ? '\n' : ' ');
    }
    _getch();
    system("cls");
}


int main(void)
{

    int a[SIZE];
    int b[SIZE];
    int c[2 * SIZE] = { 0 };

    randomize();
    set_random_array(a, SIZE);
    set_random_array(b, SIZE);

    qsort_sort_array(a, SIZE);
    qsort_sort_array(b, SIZE);

    display_array(a, SIZE);
    display_array(b, SIZE);


    int idx_a = 0, idx_b = 0;

    for (int i = 0; i < 2 * SIZE; ++i)
    {
        if (idx_a == SIZE)  // Array a'nin sonuna gelinmis ise geri kalanlari b arrayinden yaz
            c[i] = b[idx_b++];
        else if (idx_b == SIZE) // Array b'nin sonuna gelinmis ise geri kalanlari a arrayinden yaz
            c[i] = a[idx_a++];
        else if (a[idx_a] < b[idx_b])
            c[i] = a[idx_a++];
        else
            c[i] = b[idx_b++];

        // Display merging step by step.
        step_by_step_merging(c, asize(c));
    }

    printf("\nMerged Array :\n");
    display_array(c, 2*SIZE);

    return 0;
}
