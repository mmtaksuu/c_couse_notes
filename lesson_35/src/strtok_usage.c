/**
 * @file    : LESSON_35 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 19 / September / 2020
 * @code    : strtok_usage.c file
 * @details : 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * sgets(char *p)
{
    char * ptemp = p;
    int ch;

    while ((ch = getchar()) != '\n')
        *p++ = (char)ch;

    *p = '\0';

    return ptemp;
}


int main(void)
{
    printf("Enter a text : ");
    char text[200] = {0};
    sgets(text);

    printf("Enter delimiters : ");
    char delim[5] = {0};
    sgets(delim);

    char * token = NULL;
    for (token = strtok(text, delim); token != NULL; token = strtok(NULL, delim)) {
        printf("%s\n", token);
    }

    free(token);

    return 0;
}



