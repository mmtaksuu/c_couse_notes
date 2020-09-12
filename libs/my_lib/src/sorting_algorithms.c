/**
 * @file    : MY_LIB project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 14 / June / 2020
 * @code    : sorting_algorithms.c file
 * @details : 
 */

#include "helper.h"
#include "sorting_algorithms.h"

void iswap(int *p1, int *p2)
{
    int ptemp = *p1;
    *p1 = *p2;
    *p2 = ptemp;
}

void bubble_sort(int * p, size_t size)
{
    int flag;

    for (size_t i = 0; i < size-1; ++i) {
        flag = 0;
        for (size_t j = 0; j < size-1-i; ++j) {
            if (p[j] > p[j+1]) {
                iswap(p+j, p+j+1);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
}



void gswap(void *vp1, void *vp2, size_t width)
{
    char *p1 = (char *)vp1;
    char *p2 = (char *)vp2;

    while (width--) {
        char temp = *p1;
        *p1++ = *p2;
        *p2++ = temp;
    }
}


void g_bubble_sort(void *vpa, size_t size, size_t width, int(*fp)(const void *, const void *))
{
    char * p = (char *)vpa;
    int flag;

    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - 1 - i; ++j) {
            if (fp(p + j * width, p + (j + 1) * width) > 0) {
                gswap(p + j * width, p + (j + 1) * width, width);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
}

int icmp(const void *vp1, const void *vp2)
{
    const int *p1 = (const int *)vp1;
    const int *p2 = (const int *)vp2;

    if (*p1 > *p2)
        return 1;

    if (*p1 < *p2)
        return -1;

    return 0;
}


int dcmp(const void *vp1, const void *vp2)
{
    const double *p1 = (const double *)vp1;
    const double *p2 = (const double *)vp2;

    if (*p1 > *p2)
        return 1;

    if (*p1 < *p2)
        return -1;

    return 0;
}


void insertion_sort(int * p, size_t size)
{
    for (size_t i = 1; i < size; ++i) {

        for (size_t j = i; j > 0 && p[j-1] > p[j]; --j) {
            iswap(&p[j-1], &p[j]);
        }
    }
}


static size_t find_min_idx(const int * p, size_t start, size_t end)
{
    int min = p[start];
    size_t min_idx = start;

    for (size_t i = start + 1; i < end; ++i) {
        if (p[i] < min) {
            min = p[i];
            min_idx = i;
        }
    }

    return min_idx;
}


void selection_sort(int * p, size_t size)
{
    size_t idx = 0;

    for (size_t i = 0; i < size; ++i) {
        idx = find_min_idx(p, i, size);
        iswap(p+i, p+idx);
    }
}