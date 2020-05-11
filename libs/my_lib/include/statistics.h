/**
 * @file    : MY_LIB project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 02 / April / 2020
 * @code    : statistics.h file
 * @details : 
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include <stddef.h>

double sum_array(const double *p, size_t size);

double get_mean(const double *p, size_t size);

double get_std_dev(const double *p, size_t size);


#endif //STATISTICS_H
