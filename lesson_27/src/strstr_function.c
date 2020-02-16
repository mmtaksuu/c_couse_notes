/*
  Project Name: LESSON_27
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 16 / February / 2020	
  File Description: strstr_function.c file 
*/


#include <stdio.h>
#include <string.h>

#define     SIZE              100


char* sgets(char *p)
{
    char *ptemp = p;
    int ch;

    while ((ch = getchar()) != '\n')
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
    char key[SIZE];

    printf("Enter a text : ");
    sgets(str);

    printf("Enter a text you want to find : ");
    sgets(key);

    char * ptr = strstr(str, key);

    if (ptr == NULL)
        printf("It didn't find!\n");
    else
        printf("Found at %d index.\n", ptr - str);

    for (size_t i = 0; i < strlen_(key); ++i)
    {
        *(ptr + i) = '*';
    }

    puts(str);

    return 0;
}
