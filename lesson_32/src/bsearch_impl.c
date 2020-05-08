/**
 * @file    : LESSON_32 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / Mayıs / 2020
 * @code    : bsearch_impl.c file
 * @details : 
 */

#include <stdio.h>
#include "helper.h"

#define     SIZE    20

int main(void)
{
    randomize();

    int a[SIZE] = {0};
    set_random_array(a, asize(a));
    display_array(a, asize(a));
    qsort(a, asize(a), sizeof(*a), &icmp);
    display_array(a, asize(a));

    int ival;
    printf("Enter a number : ");
    scanf("%d", &ival);

    int *p_retval = (int *)bsearch(&ival, &a, asize(a), sizeof(*a), &icmp);

    if (p_retval != NULL)
        printf("Found %d at %d idx\n", *p_retval, p_retval-a+1);
    else
        printf("Not found\n");


    return 0;
}
