/*
  Project Name: LESSON_21
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 26 / January / 2020	
  File Description: is_text_polindrom.c file indicates entered text is a polindrom or not.
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

void is_polindrom(char *p)
{
    char *temp = p;
    int idx = 0;

    for (int i = 0; p[i] != '\0'; ++i) {
        if(isalpha(p[i]))
            temp[idx++] = p[i];
    }

    int j;
    for (j = 0; j < idx/2; ++j) {
        if (toupper(temp[j]) != toupper(temp[idx - j -1 ]))
            break;
    }


    if(j == idx/2)
        printf("Entered text is a polindrom!\n");
    else
        printf("Entered text is not a polindrom!\n");

}

int main(void)
{
    char str[SIZE];

    printf("Enter a text : ");
    sgets(str);

    printf("[%s]\n", str);

    is_polindrom(str);

    return 0;
}




