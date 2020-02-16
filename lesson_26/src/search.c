/*
  Project Name: c_programing_course
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 09 / February / 2020	
  File Description: search.c file 
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
//#include <time.h>


//#define     randomize()       (srand((unsigned)time(NULL)))
//#define     SIZE              20


void set_random_array(int *p, size_t size)
{
    while (size --)
        *p++ = rand() % 50;
}


void display_array(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%3d%c", p[i], i % 20 == 19 ? '\n' : ' ');
    }
    printf("\n----------------------------------------------------------------\n");
}


int * search(const int *p, size_t size, int * desired_val)
{
    while (size --)
    {
        if (*p == *desired_val)
            return (int *)p;

        ++p;
    }

    return NULL;
}


//int main(void)
//{
//
//    int a[SIZE];
//
//    randomize();
//
//    set_random_array(a, SIZE);
//    display_array(a, SIZE);
//
//    int ival;
//    printf("Enter the desired value : ");
//    scanf("%d", &ival);
//
//    int *ptr = search(a, SIZE, &ival);
//
//    if (ptr == NULL)
//        printf("Desired value was not found !\n");
//    else
//        printf("Desired value found at %d index : %d", ptr-a, *ptr);
//
//    return 0;
//}


