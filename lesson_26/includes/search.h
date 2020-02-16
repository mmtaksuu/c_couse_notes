/*
  Project Name: LESSON_26
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 11 / February / 2020	
  File Description: search.c file 
*/

#ifndef SEARCH_H
#define SEARCH_H

#include <time.h>

#define     randomize()       (srand((unsigned)time(NULL)))
#define     SIZE              20


void set_random_array(int *, size_t);
void display_array(const int *, size_t);
int * search(const int *, size_t, int *);

#endif // SEARCH_H
