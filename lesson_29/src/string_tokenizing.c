/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : tokenizing_in_pnames.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"

int main(void)
{
    char str[100];
    printf("Enter a text : ");
    sgets(str);

    char * token = strtok(str, " ");

    while (token)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}



