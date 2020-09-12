/**
 * @file    : LESSON_34 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / September / 2020
 * @code    : strdup_imp.c file
 * @details : 
 */


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sgets(char * p)
{
    int ch;
    while ((ch = getchar()) != '\n') {
        *p++ = (char)ch;
    }

    *p = '\0';

    return p;
}

char * my_strdup (const char *p)
{
    char * pd = (char *)malloc(strlen(p)+1);
    if (!pd) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(pd, p);

    return pd;
}

int main(void)
{
    printf("Enter a text: ");
    char str[200];
    sgets(str);

//    char *pd = _strdup(str);
    char *pd = my_strdup(str);

    printf("(%s) (%s)\n", str, pd);
    _strrev(pd);
    printf("(%s) (%s)\n", str, pd);
    free(pd);
    pd = NULL;

    return 0;
}


