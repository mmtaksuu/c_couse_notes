/*
  Project Name: LESSON_21
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 26 / January / 2020	
  File Description: main.c file prints the entered text in reverse on the screen.
*/


#include <stdio.h>

#define     SIZE              100


char * sgets(char *p)
{
    char ch;
    char *temp = p;

    while ((ch = (char) getchar()), ch != '\n')
        *temp++ = ch;

    *temp = '\0';

    return temp;
}



int main(void)
{

    char str[SIZE];
    printf("Enter a word : ");
    sgets(str);

    // Yazinin uzunlugunu bul ve normal yazdir.
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        putchar(str[i]);
        ++len;
    }

    // Yazinin uzunlugu -1 'den baslayarak yaziyi tersten yazdir.
    printf("\n");
    for (--len; len >= 0; --len)
        printf("(%c)", str[len]);

    return 0;
}


