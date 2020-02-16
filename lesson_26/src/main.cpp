/*
  Project Name: LESSON_26
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 11 / February / 2020	
  File Description: main.cpp file
*/

#if __cplusplus
extern "C" {
    #include "../includes/search.h"
};

#include <iostream>

#endif




int main()
{

    int a[SIZE];

    randomize();

    set_random_array(a, SIZE);
    display_array(a, SIZE);

    int ival;
    printf("Enter the desired value : ");
    scanf("%d", &ival);

    int *ptr = search(a, SIZE, &ival);

    if (ptr == nullptr)
        printf("Desired value was not found !\n");
    else
        printf("Desired value found at %d index : %d", ptr-a, *ptr);

    return 0;
}


