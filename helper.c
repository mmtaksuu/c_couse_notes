/**
 * @file    : LESSON_20 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / February / 2020
 * @code    : helper.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int gen_rand_int_nums(int num_of_digits)
{
    switch (num_of_digits){
        case 1:
            return rand() % 10;
        case 2:
            return rand() % 100;
        case 3:
            return rand() % 1000;
        case 4:
            return rand() % 10000;
        default:
            return rand();
    }
}


float gen_rand_float_nums(int num_of_digits)
{
    switch (num_of_digits){
        case 1:
            return (float)rand()/(float)(RAND_MAX/10.0);
        case 2:
            return (float)rand()/(float)(RAND_MAX/100.0);
        case 3:
            return (float)rand()/(float)(RAND_MAX/1000.0);
        case 4:
            return (float)rand()/(float)(RAND_MAX/10000.0);
        default:
            return (float)rand()/(float)(RAND_MAX/1.0);
    }
}


void set_random_array(void *vp, size_t size, int num_of_digits, const char *ptype)
{
    if (!strcmp(ptype, "int"))
    {
        int *p = (int *)vp;

        while (size --)
            *p++ = gen_rand_int_nums(num_of_digits);
    }
    else if (!strcmp(ptype, "double"))
    {
        double *p = (double *)vp;

        while (size --)
            *p++ = gen_rand_float_nums(num_of_digits);
    }
}


void display_array(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%3d%c", p[i], i % 20 == 19 ? '\n' : ' ');
    }
    printf("\n-------------------------------------------------------------------------------\n");
}


char *sgets(char *p)
{
    char *ptemp = p;
    int ch;

    while((ch = getchar()) != '\n')
        *p++ = (char)ch;

    *p = '\0';

    return ptemp;
}

void swap_arr_items(int *p1, int *p2)
{
    int ptemp = *p1;
    *p1 = *p2;
    *p2 = ptemp;
}


void bsort(int *p, int size)
{

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (p[j] > p[j+1])
                swap_arr_items(&p[j], &p[j+1]);
        }
    }
}


int gcmp(const void *vp1, const void *vp2, size_t width)
{
    const char *p1 = (const char *)vp1;
    const char *p2 = (const char *)vp2;

    int p1_cnt = 0;
    int p2_cnt = 0;

    while (width--)
    {
        if (*p1 > *p2)
            ++p1_cnt;

        if (*p1 < *p2)
            ++p2_cnt;

        ++p1;
        ++p2;
    }

    if (p1_cnt > p2_cnt)
        return 1;

    if (p1_cnt < p2_cnt)
        return -1;

    return 0;
}





