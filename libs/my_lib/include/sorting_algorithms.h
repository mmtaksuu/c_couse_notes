/**
 * @file    : MY_LIB project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 14 / June / 2020
 * @code    : sorting_algorithms.h file
 * @details : 
 */

#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

void iswap(int *p1, int *p2);

void bubble_sort(int * p, size_t size);

void gswap(void *vp1, void *vp2, size_t width);

void g_bubble_sort(void *vpa, size_t size, size_t width, int(*fp)(const void *, const void *));

int icmp(const void *vp1, const void *vp2);

int dcmp(const void *vp1, const void *vp2);

void insertion_sort(int * p, size_t size);

void selection_sort(int * p, size_t size);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* SORTING_ALGORITHMS_H */