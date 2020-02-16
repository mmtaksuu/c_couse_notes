/*
  Project Name: LESSON_27
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 16 / February / 2020	
  File Description: strcat_function.c file 
*/


#include <stdio.h>
#include <string.h>

#define     SIZE              100


char *strcat_1(char *p1, const char * p2)
{
    char *ptemp = p1;

    while (*p1 != '\0')
        ++p1;

    while ((*p1++ = *p2++))
        ;

    return ptemp;
}


char* strcat_2(char *pdest, const char *psource)
{
    strcpy(pdest + strlen(pdest), psource);

    return pdest;
}


char* strcat_3(char *pdest, const char *psource)
{
    strcpy(strchr(pdest, '\0'), psource);

    return pdest;
}



int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    char s3[SIZE];
    char s4[SIZE];

    printf("Enter your name and surname: ");
    scanf("%s%s", s1, s2);

    strcpy(s3, s1);
    strcpy(s4, s1);

    strcat_1(s1, s2);
    puts(s1);

    strcat_2(s3, s2);
    puts(s3);

    strcat_3(s4, s2);
    puts(s4);

    return 0;
}


