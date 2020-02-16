/*
  Project Name: LESSON_27
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 16 / February / 2020	
  File Description: puts_function.c file 
*/

#include <stdio.h>


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

int puts_(char *p)
{
    char * ptemp = p;

    while (*ptemp != '\0') {
        putchar(*ptemp);
        ++ptemp;
    }

    putchar('\n');

    return (int)(ptemp - p);
}



int main(void)
{
    char str[SIZE];

    printf("Enter a text : ");
    sgets(str);

    puts(str);

    int len = puts_(str);
    printf("len is %d\n", len);

    return 0;
}
