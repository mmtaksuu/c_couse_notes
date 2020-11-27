/**
 * @file    : LESSON_19 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 13 / June / 2020
 * @code    : linear_searching_imp.c file
 * @details : 
 */

#include <stdio.h>
#include "helper.h"

#define     SIZE    100

int * do_linear_search(const int *p, size_t size, int key)
{
    size_t i;
    for (i = 0; i < size && p[i] != key; ++i)
        ;

    if (i < size)
        return (int *) &p[i];

    return NULL;
}

int main(void)
{
    int a[SIZE];

    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);

    int key_val;
    printf("Enter a value : ");
    scanf("%d", &key_val);

    int * ptr = do_linear_search(a, SIZE, key_val);

    if (ptr == NULL)
        printf("Value is not found!\n");
    else
        printf("%d found at %d index.\n", key_val, ptr-a);


    return 0;
}

