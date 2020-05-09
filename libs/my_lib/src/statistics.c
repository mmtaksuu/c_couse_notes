/**
 * @file    : QUEUE project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 14 / March / 2020
 * @code    : statistics.c file
 * @details : 
 */

#include <math.h>
#include "statistics.h"

double sum_array(const double *p, size_t size)
{
    double sum = 0.;

    while (size--)
        sum += *p++;

    return sum;
}


double get_mean(const double *p, size_t size)
{
    return sum_array(p, size) / size;
}


double get_std_dev(const double *p, size_t size)
{
    double mean = get_mean(p, size);
    double sum_square = 0.;

    for (int i = 0; i < size; ++i)
        sum_square += (p[i] - mean) * (p[i] - mean);

    return sqrt(sum_square / size);
}



