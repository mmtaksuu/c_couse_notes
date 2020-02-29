/*
  Project Name: LESSON_27
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 16 / February / 2020	
  File Description: strlen_function.c file 
*/

#include <stdio.h>
#include <string.h>

#define     SIZE              100

char *sgets(char *p)
{
    char *ptemp = p;
    int ch;

    while((ch = getchar()) != '\n')
        *p++ = (char)ch;

    *p = '\0';

    return ptemp;
}


size_t strlen_(const char *p)
{
    size_t len = 0;

    while (*p++ != '\0')
        ++len;

    return len;
}


int main(void)
{
    char str[SIZE];

    printf("Enter a text : ");
    sgets(str);

    puts(str);
    printf("The length of the entered text is %u.\n", strlen(str));
    printf("The length of the entered text is %u.\n", strlen_(str));

    return 0;
}

