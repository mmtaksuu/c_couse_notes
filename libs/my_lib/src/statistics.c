/**
 * @file    : QUEUE project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 14 / March / 2020
 * @code    : statistics.c file
 * @details : 
 */

#include <math.h>
#include <stdlib.h>
#include "helper.h"
#include "statistics.h"
#include "sorting_algorithms.h"

double sum_array(const double *p, size_t size)
{
    double sum = 0.;

    while (size--)
        sum += *p++;

    return sum;
}

double get_max(const double * p, size_t size)
{
    double max = *p;

    for (size_t i = 1; i < size; ++i)
        if (p[i] > max)
            max = p[i];

    return max;
}

double get_min(const double * p, size_t size)
{
    double min = *p;

    for (size_t i = 1; i < size; ++i)
        if (p[i] < min)
            min = p[i];

    return min;
}


double get_mean(const double *p, size_t size)
{
    return sum_array(p, size) / size;
}


double get_median(double *p, size_t size)
{
    qsort(p, size, sizeof(*p), &dcmp);

    if (size % 2 != 0)
        return p[size/2];

    return (p[(size-1)/2] + p[size/2]) / 2.0;
}


double get_variance(const double *p, size_t size)
{
    double mean = get_mean(p, size);
    double sum_square = 0.;

    for (int i = 0; i < size; ++i)
        sum_square += (p[i] - mean) * (p[i] - mean);

    return sum_square / size;
}


double get_std_dev(const double *p, size_t size)
{
    return sqrt(get_variance(p, size));
}


double get_direct_std_dev(const double *p, size_t size)
{
    double mean = get_mean(p, size);
    double sum_square = 0.;

    for (int i = 0; i < size; ++i)
        sum_square += pow((p[i] - mean), 2);

    return sqrt(sum_square / (size - 1));
}


/** Estimate standard error of mean */
double get_std_err_of_mean(double std_dev, size_t size)
{
    return std_dev / sqrt(size);
}



