/*
  Project Name: LESSON_13
  Author: MEHMET AKSU
  Author Email: mmtaksu.25@gmail.com
  Date: 02 / Ocak / 2020
  Description: for_loop1.c file uses functions to build for expressions.
*/

#include <stdio.h>

// Define i as a global loop variable.
int i;

// Define funtion prototypes
int f1(void);
int f2(void);
void f3(void);
void f4(void);


int main(void)
{
	for (f1(); f2(); f3())
		f4();

	return 0;
}

// Function Definitions
int f1(void){
    i = 0;
}


int f2(void){
    return i > 10 ? 0 : 1;
}


void f3(void){
    ++i;
}


void f4(void){
    printf("%d \n", i);
}