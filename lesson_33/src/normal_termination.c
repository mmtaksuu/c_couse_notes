/**
 * @file    : LESSON_33 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / September / 2020
 * @code    : normal_termination.c file
 * @details : 
 */



#include <stdio.h>


void f4()
{
    printf("f4() basladi\n");

    printf("f4() sona erdi\n");
}

void f3()
{
    printf("f3() basladi\n");
    f4();
    printf("f3() sona erdi\n");
}

void f2()
{
    printf("f2() basladi\n");
    f3();
    printf("f2() sona erdi\n");
}


void f1()
{
    printf("f1() basladi\n");
    f2();
    printf("f1() sona erdi\n");
}


int main(void)
{
    printf("main() basladi\n");
    f1();
    printf("main() sona erdi\n");

    return 0;
}


