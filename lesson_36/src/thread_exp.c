/**
 * @file    : LESSON_36 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 19 / September / 2020
 * @code    : thread_exp.c file
 * @details : 
 */

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <pthread.h>
#include <mem.h>
#include <stdlib.h>
#include <unistd.h>

void delay(double sec)
{
    clock_t start = clock();

    while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}

int task_1_ended = 0;
int task_2_ended = 0;

void * task_1 (void * thread_id)
{
    time_t begin_time = 0;
    time(&begin_time);

    delay(1);

    time_t end_time   = 0;
    time(&end_time);

    double passed_time = difftime(end_time, begin_time);
    printf("task_1, Passed Time = %.3f sec\n", passed_time);

    task_1_ended = 1;
    pthread_exit(NULL);

    return NULL;
}

void * task_2 (void * thread_id)
{
    unsigned int ival = 0;

    while (1) {
        ++ival;
        ival %= 60;
        if (task_1_ended)
            break;
    }
    printf("task_2, Passed Time = %u sec\n", ival);

    task_2_ended = 1;
    pthread_exit(NULL);

    return NULL;
}


int main(void)
{
    printf("Main thread started\n");

    pthread_t thread_1, thread_2;

    int res1 = pthread_create(&thread_1, NULL, task_1, NULL);
    if (res1) {
        printf("pthread_create : %s\n", strerror(res1));
        exit(EXIT_FAILURE);
    }

    int res2 = pthread_create(&thread_2, NULL, task_2, NULL);
    if (res2) {
        printf("pthread_create : %s\n", strerror(res2));
        exit(EXIT_FAILURE);
    }

    int ext = 0;

    while (1) {
        if (ext == 2)
            break;
        ext = task_1_ended + task_2_ended;
    }

    printf("Main thread ended\n");


    return 0;
}


