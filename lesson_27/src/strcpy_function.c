/*
  Project Name: LESSON_27
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 16 / February / 2020	
  File Description: strcpy_function.c file 
*/

#include <stdio.h>
#include <string.h>

#define     SIZE              100

char * sgets(char *p)
{
    char * ptemp = p;
    int ch;

    while ((ch = getchar()) != '\n')
        *p++ = (char)ch;

    *p = '\0';

    return ptemp;
}


char *strcpy_1(char *pdest, const char *psource)
{
    char * ptemp = pdest;

    while (*psource != '\0')
        *pdest++ = *psource++;

    *pdest = '\0';

    return ptemp;
}


char *strcpy_2(char *pdest, const char *psource)
{
    char * ptemp = pdest;

    while ((*pdest++ = *psource++))
        ;

    return ptemp;
}


int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    char s3[SIZE];
    char s4[SIZE];

    printf("Enter a text : ");
    sgets(s1);

    puts(s1);

    // Copies strings using standard library function.
    strcpy(s2, s1);
    printf("(%s) (%s)\n", s1, s2);


    // Copies strings using our function 1.
    strcpy_1(s3, s1);
    printf("(%s) (%s)\n", s1, s3);


    // Copies strings using our function 2.
    strcpy_2(s4, s1);
    printf("(%s) (%s)\n", s1, s4);

    return 0;
}



