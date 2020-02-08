/*
  Project Name: LESSON_20
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 26 / January / 2020	
  File Description: sizeof_strings.c file 
*/

#include <stdio.h>

#define     SIZE              10
#define     asize(x)          (sizeof(x) / sizeof (x[0]))


int main(void)
{
    char name[SIZE] = "mehmet";
    printf("Storage of name char array is : %u Bytes\n", asize(name));

    char str[] = { 'E', 'S', 'M', 'A' };
    printf("Storage of name char array is : %u Bytes\n", asize(str));

    return 0;
}

