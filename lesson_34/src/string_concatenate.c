/**
 * @file    : LESSON_34 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / September / 2020
 * @code    : string_concatenate.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strcon(const char *p1, const char *p2)
{
    char *pd = (char *)malloc(strlen(p1) + strlen(p2) + 1);
    if (!pd) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

//    strcpy(pd, p1);
//    strcpy(pd+strlen(p1), p2);
    strcat(strcpy(pd, p1), p2);

    return pd;
}

char *sgets(char *p)
{
    int ch;
    while ((ch = getchar()) != '\n') {
        *p++ = (char)ch;
    }
    *p = '\0';

    return p;
}

int main(void)
{
    printf("Enter 1st text : ");
    char str1[100];
    sgets(str1);

    printf("Enter 2nd text : ");
    char str2[100];
    sgets(str2);

    char *pd = strcon(str1, str2);

    printf("Concatenated String is : %s\n", pd);

    free(pd);
    pd = NULL;

    return 0;
}



