/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / May / 2020
 * @code    : main.c file
 * @details : 
 */


#include <stdio.h>
#include <string.h>
#include "helper.h"


int main(void)
{
    int a[sizeof "ali"];
    int b[strlen("ali")];

    printf("asize(a) %u\n", asize(a));
    printf("asize(b) %u\n", asize(b));

    printf("sizeof (\"ali\") : %u\n", sizeof "ali");
    printf("strlen(\"ali\")  : %u\n", strlen("ali"));
    printf("sizeof (\"\")    : %u\n", sizeof "");
    printf("strlen(\"\")     : %u\n", strlen(""));

    return 0;
}
