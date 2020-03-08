/**
 * @file    : codility project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / March / 2020
 * @code    : test.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define     SIZE              10
#define     randomize()       (srand((unsigned)time(NULL)))


void set_random_array(int *p, size_t size)
{
    while (size--)
        *p++ = rand() % 10;
}

void display_array(const int *p, size_t size)
{
    while (size--)
        printf("%2d", *p++);

    printf("\n----------------------\n");
}


void rotate_array(int *p, size_t size, int rot_num)
{

    if (rot_num == 0 || rot_num == size)
        return;
    else if (rot_num > size)
        rot_num = rot_num % size;


    int num_of_reminder = size - rot_num;
    int * reminder_array = (int *)malloc(num_of_reminder * sizeof(int));

    for (int i = 0; i < num_of_reminder; ++i) {
        reminder_array[i] = p[i];
    }

    for (int i = 0; i < size; ++i) {

        if (i < rot_num)
            p[i] = p[num_of_reminder + i];
        else
            p[i] = reminder_array[i - rot_num];
    }

    free(reminder_array);

}

int main(void)
{
    int a[SIZE];

    randomize();

    set_random_array(a, SIZE);
    display_array(a, SIZE);

    rotate_array(a, SIZE, 8);
    display_array(a, SIZE);

    return 0;
}



