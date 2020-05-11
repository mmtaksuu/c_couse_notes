/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 10 / May / 2020
 * @code    : my_memcpy_func.c file
 * @details : 
 */

#include <stdio.h>
#include "helper.h"

#define     SIZE              100


void * my_memcpy(void * vp_dest, const void * vp_src, size_t n)
{
    char * pdest      = (char *)vp_dest;
    const char * psrc = (const char *)vp_src;

    while (n--)
        *pdest++ = *psrc++;

    return vp_dest;
}


int main(void)
{
    int src[SIZE] = {0};
    int dst[SIZE] = {0};

    set_random_array(src, asize(src));
    printf("Source Array : \n");
    display_array(src, asize(src));

    size_t idx_at_src, idx_at_dst, n_of_items = 0;
    printf("Enter idx_at_src, idx_at_dst, n_of_items = ");
    scanf("%u%u%u", &idx_at_src, &idx_at_dst, &n_of_items);

    my_memcpy(dst+idx_at_dst, src+idx_at_src, n_of_items*sizeof(*src));
    printf("Destination Array : \n");
    display_array(dst, asize(dst));

    return 0;
}


