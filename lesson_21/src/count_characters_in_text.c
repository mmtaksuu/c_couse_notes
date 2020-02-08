/*
  Project Name: LESSON_21
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 26 / January / 2020	
  File Description: count_characters_in_text.c file counts alphanumeric characters in entered text.
*/

#include <stdio.h>
#include <ctype.h>

#define     SIZE              100

char *sgets(char *p)
{
    char *temp = p;
    int ch;

    while((ch = getchar()), ch != '\n')
        *temp++ = (char)ch;

    *temp = '\0';

    return temp;
}


int main(void)
{
    char str[SIZE];

    printf("Enter a text : ");
    sgets(str);

    printf("[%s]\n", str);

    int word_cnt = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isalpha(str[i]))
            ++word_cnt;
    }

    printf("[%s] has %d number of alphanumeric characters!\n", str, word_cnt);

    return 0;
}





