/**
 * @file    : MY_LIB project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / February / 2020
 * @code    : helper.c file
 * @details : 
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "helper.h"


int gen_rand_int_nums(void)
{
    return rand() % 10;
}


float gen_rand_float_nums(void)
{
    return (float)rand()/(float)(RAND_MAX/10.0);
}


void set_random_array(int *p, size_t size)
{
    while (size --)
        *p++ = gen_rand_int_nums();
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


void sleep(double sec)
{
    clock_t start = clock();

    while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}

int is_hit_button(char ch)
{
    return (!kbhit() || toupper(_getch() )!= ch);
}


void bit_print(UINT16 val)
{
    char str[20];
    _itoa(val, str, 2);
    printf("%016s\n", str);
}

