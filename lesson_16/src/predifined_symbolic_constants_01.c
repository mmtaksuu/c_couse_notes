/**
 * @file    : lesson_16 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 18 / April / 2020
 * @code    : predifined_symbolic_constants_01.c file
 * @details : 
 */


#include <stdio.h>
#include <string.h>

void func1(void)
{
    printf("%s function is called\n", __func__);
}

void print_compile_time(void)
{
    printf("%s function is called\n", __func__);

    char str[100] = {0};

    memcpy(str, __TIME__, sizeof(__TIME__));
    printf("Compile time is %s\n", __TIME__);
    printf("Compile time is %s\n", str);
}


void print_file_info(void)
{
    printf("%s function is called\n", __func__);

    printf("Program file path is %s\n", __FILE__);
}


void print_compile_date(void)
{
    printf("%s function is called\n", __func__);
    printf("Compile date is %s\n", __DATE__);
}

void print_counter(void)
{
    printf("%s function is called\n", __func__);

    printf("Counter is %d\n", __COUNTER__);
    printf("Counter is %d\n", __COUNTER__);
    printf("Counter is %d\n", __COUNTER__);
    printf("Counter is %d\n", __COUNTER__);
    printf("Counter is %d\n", __COUNTER__);
}

int main(void)
{
    printf("%s function is called\n", __func__);
    printf("Line number is %d\n", __LINE__);

    func1();

    print_compile_time();

    print_file_info();

    print_compile_date();

    print_counter();


    return 0;
}


