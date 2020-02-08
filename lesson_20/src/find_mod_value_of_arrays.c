/*
  Project Name: LESSON_
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 25 / January / 2020	
  File Description: find_mod_value_of_arrays.c file 
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define     SIZE              40
#define     MAX_VAL           50
#define     randomize()       (srand((unsigned)time(NULL)))


void set_random_array(int *p, int size)
{
    while(size--)
        *p++ = rand() % 50;
}

void display_array(int *p, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%2d%c", p[i], i % 20 == 19 ? '\n' : ' ');
    }
    printf("\n");
}


int main()
{
    int a[SIZE];
    int f[MAX_VAL] = { 0 };

    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);


    for (int i = 0; i < SIZE; ++i)
        ++f[a[i]]; // f array holds the freq number of the items of the array a

    int freq = f[0];
    int mod = 0;


    for (int i = 1; i < MAX_VAL; ++i) {
        if (f[i] > freq) {
            freq = f[i];
            mod = i;
        }
    }


    if (freq <= 0)
        printf("The array has not a mod value");
    else
        printf("The mod of the array is %d and its frequency is %d\n", mod, freq);

    return 0;
}
