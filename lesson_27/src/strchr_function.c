/*
  Project Name: LESSON_27
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 16 / February / 2020	
  File Description: strchr_function.c file 
*/


#include <stdio.h>

#define     SIZE              100

char * sgets(char *p)
{
    char *ptemp = p;
    int ch;

    while ((ch = getchar()) != '\n')
        *p++ = (char)ch;

    *p = '\0';

    return ptemp;
}


char* strchr_(const char *p, int ch)
{
    while (*p != '\0'){
        if(*p == ch)
            return (char *)p;
        ++p;
    }

    if(ch == 0)
        return (char *)p;

    return NULL;
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

    char c;
    printf("Enter the character you want to find : ");
    scanf("%c", &c);

    char * cptr = strchr_(str, c);    // searches by starting 0 index

    if (cptr == NULL)
        printf("It didn't find!\n");
    else
        printf("Found at %d index %s\n", cptr - str, cptr);

    return 0;
}
