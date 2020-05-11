/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 10 / May / 2020
 * @code    : memmove_exp.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>


int main(void)
{
    char str[] = "A lot of people infacted by corana virus died in the world!\n";

    printf("Main string : \n");
    printf("%s \n", str);

    memmove(str, str+9, strlen(str) + 1);

    printf("Copied string : \n");
    printf("%s \n", str);

    return 0;
}

