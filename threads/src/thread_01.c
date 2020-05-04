/**
 * @file    : THREADS project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 26 / April / 2020
 * @code    : thread_01.c file
 * @details : 
 */

#include <stdio.h>
#include <pthread.h>


int main(void)
{

    pthread_create(&thread_id, &attr, func, NULL);


    return 0;
}
