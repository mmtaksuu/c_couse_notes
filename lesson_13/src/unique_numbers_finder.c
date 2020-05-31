/*
  Project Name: LESSON_13
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 03 / Ocak / 2020	
  File Description: unique_numbers.c file finds unique numbers in an array. Array can fill either by the user or randomly.
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "helper.h"


#define     SIZE              20


int * find_unique_numbers(const int *p, size_t size, int *p_unique)
{
    size_t j;

    for (size_t i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            if (p[i] == p[j] && i != j)
                break;
        }
        if (j == size)
            *p_unique++ = p[i];
    }

    *p_unique = -1;

    return p_unique;
}

void print_unique_numbers(const int *p_unique, size_t size)
{
    printf("\nUnique numbers : \n");
    for (size_t i = 0; i < size && p_unique[i] != -1; ++i) {
        printf("%3d%c", p_unique[i], i % 20 == 19 ? '\n' : ' ');
    }
    printf("\n-------------------------------------------------------------------------------\n");
}


int * find_repetetive_numbers(const int *p, size_t size) {

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (p[i] == p[j] && i != j)
                return (int *)&p[i];
        }
    }
    return NULL;
}


int main(void)
{
    int a[SIZE] = {0};
    int unique[SIZE] = {0};

    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);

    find_unique_numbers(a, SIZE, unique);
    print_unique_numbers(unique, SIZE);


//    printf("\nRepetetive numbers : ");
//    find_repetetive_numbers(a, SIZE);
}

