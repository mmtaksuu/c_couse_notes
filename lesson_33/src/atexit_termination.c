/**
 * @file    : LESSON_33 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / September / 2020
 * @code    : atexit_termination.c file
 * @details : 
 */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void f4()
{
    printf("f4 cagrildi cleanup islemleri yapildi\n");
}

void f3()
{
    printf("f3 cagrildi cleanup islemleri yapildi\n");
}

void f2()
{
    printf("f2 cagrildi cleanup islemleri yapildi\n");
}


void f1()
{
    printf("f1 cagrildi cleanup islemleri yapildi\n");
}


int main(void)
{
    atexit(f1);
    atexit(f2);
    atexit(f3);
    atexit(f4);
    _getch();

    exit(EXIT_SUCCESS);
}


