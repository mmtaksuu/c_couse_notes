/**
 * @file    : LESSON_35 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 19 / September / 2020
 * @code    : urand_impl.c file
 * @details : 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define     URAND_MAX         50
#define     randomize()       (srand((unsigned)time(NULL)))


int urand(void)
{
    static int look_up[URAND_MAX] = {0};

    int idx = 0;
    static int call_count = 0;

    if (call_count >= URAND_MAX)
        return -1;

    while (look_up[idx = rand() % URAND_MAX])
        ;

    look_up[idx] = 1;
    ++call_count;

    return idx;
}

int main(void)
{
    randomize();

    for (int i = 0; i < URAND_MAX; ++i) {
        printf("%d ", urand());
    }

    return 0;
}




