/**
 * @file    : LESSON_24 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / March / 2020
 * @code    : std_dev_of_an_array.c file
 * @details : 
 */

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define     randomize()       (srand((unsigned)time(NULL)))
#define     asize(x)          (sizeof(x) / sizeof (x[0]))
#define     SIZE                20


typedef struct {
    double sinyal_1_olcum;
    double sinyal_2_olcum;
    double mean;
    double std_dev;
    double min;
    double max;
} OLCUMLER_t;


double sum_array(double sinyal_1, double sinyal_2)
{
    return sinyal_1 + sinyal_2;
}

double get_mean(double sinyal_1, double sinyal_2)
{
    return sum_array(sinyal_1, sinyal_2) / 2;
}

double get_std_dev(double sinyal_1, double sinyal_2)
{
    double mean = get_mean(sinyal_1, sinyal_2);
    double sum_square = 0.;

    sum_square += (sinyal_1 - mean) * (sinyal_1 - mean);
    sum_square += (sinyal_2 - mean) * (sinyal_2 - mean);

    return sqrt(sum_square / 2);
}

double get_min(double sinyal_1, double sinyal_2)
{
    return sinyal_1 < sinyal_2 ? sinyal_1 : sinyal_2;
}

double get_max(double sinyal_1, double sinyal_2)
{
    return sinyal_1 > sinyal_2 ? sinyal_1 : sinyal_2;
}


int main(void)
{
    OLCUMLER_t olcumler_t = {0};

    FILE *fptr = fopen("../src/sinyal_olcumler.tab", "w");

    if (fptr == NULL)
        return printf("File is not created!\n"), 1;

    fprintf(fptr, "sinyal_1\tsinyal_2\tmean\t\tstd_dev\t\tmin\t\t\tmax\n");


    randomize();

    for (int i = 0; i < SIZE; ++i) {
        olcumler_t.sinyal_1_olcum = rand()/(RAND_MAX/500.0);
        olcumler_t.sinyal_2_olcum = rand()/(RAND_MAX/500.0);
        olcumler_t.mean           = get_mean(olcumler_t.sinyal_1_olcum, olcumler_t.sinyal_2_olcum);
        olcumler_t.std_dev        = get_std_dev(olcumler_t.sinyal_1_olcum, olcumler_t.sinyal_2_olcum);
        olcumler_t.min            = get_min(olcumler_t.sinyal_1_olcum, olcumler_t.sinyal_2_olcum);
        olcumler_t.max            = get_max(olcumler_t.sinyal_1_olcum, olcumler_t.sinyal_2_olcum);

        fprintf(fptr, "%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", olcumler_t.sinyal_1_olcum,
                                                                        olcumler_t.sinyal_2_olcum,
                                                                        olcumler_t.mean,
                                                                        olcumler_t.std_dev,
                                                                        olcumler_t.min,
                                                                        olcumler_t.max);
    }

    fclose(fptr);

    return 0;
}
