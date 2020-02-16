/*
  Project Name: LESSON_27
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 16 / February / 2020	
  File Description: rputs_function.c file 
*/


#include <stdio.h>

#define     SIZE              100

char * sgets(char *p)
{
    char * ptemp = p;
    int ch;

    while((ch = getchar()) != '\n')
        *p++ = (char)ch;

    *p = '\0';

    return ptemp;
}


size_t strlen_(const char *p)
{
    size_t len = 0;

    while(*p++ != '\0')
        ++len;

    return len;
}


void rputs_(char *p)
{
    char *pend = p + strlen_(p);

    while (pend != p){
        putchar(*--pend);
    }
    putchar('\n');

}


int main(void)
{
    char str[SIZE];

    printf("Enter a text : ");
    sgets(str);

    puts(str);
    rputs_(str);

    return 0;
}
