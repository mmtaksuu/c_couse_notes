/*
  Project Name: LESSON_21
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 26 / January / 2020	
  File Description: reverse_with_swap.c file 
*/


#include <stdio.h>

#define     SIZE              100


char *sgets(char *p)
{
    char *temp = p;
    int ch;

    while ((ch = getchar()), ch != '\n')
        *temp++ = (char)ch;

    *temp = '\0';

    return temp;
}


int main(void)
{
    char str[SIZE];

    printf("Enter a text : ");
    sgets(str);

    int i;
    for (i = 0; str[i] != '\0'; ++i) {
        printf("%c", str[i]);
    }

    for (int j = 0; j < i / 2; ++j) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    printf("\n");
    puts(str);

    return 0;
}



