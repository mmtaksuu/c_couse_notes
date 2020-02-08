/*
  Project Name: LESSON_20
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 25 / January / 2020	
  File Description: qsort_implementation.c file 
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


#define   SIZE              10
#define   randomize()       srand((unsigned)time(NULL))


typedef struct {
    int id;
    int age;
} person_t;


void set_random_array(person_t *p, int size)
{
    for (int i = 0; i < size; ++i)
    {
        p[i].id  = rand() % 20;
        p[i].age = rand() % 20 + 15;
    }
}


int pcmp(const void *vp1, const void *vp2)
{
    return ((const person_t *)vp1)->id - ((const person_t *)vp2)->id;
}


int pcmp2(const void *vp1, const void *vp2)
{
    return ((const person_t *)vp1)->age - ((const person_t *)vp2)->age;
}


void swap_array_items(person_t *p1, person_t *p2)
{
    person_t temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


void do_bubble_sort(person_t *p, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int k = 0; k < size - 1 - i; ++k)
        {
            if (p[k].age > p[k + 1].age)
            {
                swap_array_items(&p[k], &p[k+1]);
                /*person_t temp = p[k];
                p[k] = p[k + 1];
                p[k + 1] = temp;*/
            }
        }
    }
}


void display_array(person_t *p, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%2d %d\n", p[i].id, p[i].age);
    }
}


int main()
{
    // Defines an array type of person_t
    person_t a[SIZE];

    randomize();

    set_random_array(a, SIZE);

    // Sort the array through the person id
    qsort(a, SIZE, sizeof(*a), &pcmp);

    printf("Sorted person ids\n");
    display_array(a, SIZE);

    printf("Hit a button to continue with age sorting.\n");
    _getch();

    /* This section we will use qsort and bubble sort to sort the age of the persons. */
    /* Sort the array through the person age. qsort is unstable sorting algorithm. */
//    qsort(a, SIZE, sizeof(*a), &pcmp2);
//    printf("Sorting age with qsort algorithm\n");
//    display_array(a, SIZE);


    // Bubble sort algorithm is stable sort algorithm.
    do_bubble_sort(a, SIZE);
    printf("Sorting age with bubble algorithm\n");
    display_array(a, SIZE);


    return 0;
}


