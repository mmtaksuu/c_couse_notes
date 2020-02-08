/*
  Project Name: LESSON_13
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 03 / Ocak / 2020	
  File Description: unique_numbers.c file finds unique numbers in an array. Array can fill either by the user or randomly.
*/

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>  // For srand(), rand() functions.


#define SIZE 20

int arr[SIZE];

void fill_array_ramdomly(int *ptr)
{
    srand((unsigned)time(0));

    for (int i = 0; i < SIZE; ++i)
    {
        ptr[i] = rand() % 20;
    }
}


void fill_array_by_user(int *ptr)
{
    for (int i = 0; i < SIZE; ++i) {
        printf("arr[%d+1] = ", i);
        scanf("%d", &ptr[i]);
    }
}


void find_unique_numbers(int *ptr)
{
    int j;

    for (int i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (ptr[i] == ptr[j] && i != j)
                break;
        }
        if (j == SIZE)
            printf("%3d ", ptr[i]);
    }
}


void find_repetetive_numbers(int *ptr) {

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (ptr[i] == ptr[j] && i != j)
                printf("%3d ", ptr[i]);
        }
    }
}


int main(void)
{
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("arr_size = %d\n", arr_size);
    printf("sizeof(arr) = %d\n", sizeof(arr));
    printf("sizeof(arr[0]) = %d\n", sizeof(arr[0]));

    int choosing;

    printf("\nEnter the filling type of array : \n/"
           "(1) For Randomly\n/"
           "(2) By User\n");

    scanf("%d", &choosing);

    if (choosing == 1)
        fill_array_ramdomly(arr);
    else if (choosing == 2)
        fill_array_by_user(arr);

    printf("Elements of array :\n");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%3d ", arr[i]);
    }

    printf("\nUnique numbers : ");
    find_unique_numbers(arr);

    printf("\nRepetetive numbers : ");
    find_repetetive_numbers(arr);
}

