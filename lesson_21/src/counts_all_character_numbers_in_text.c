/*
  Project Name: LESSON_21
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 26 / January / 2020	
  File Description: counts_all_character_numbers_in_text.c file 
*/

#include <stdio.h>
#include <ctype.h>

#define     SIZE                    100
#define     ALPHANUMERIC_CHARS      26

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
    int chars[ALPHANUMERIC_CHARS] = { 0 };
    char str[SIZE];

    printf("Enter a text : ");
    sgets(str);

    printf("[%s]\n", str);


    for (int i = 0; str[i] != '\0'; ++i) {
        if (isalpha(str[i])){
            ++chars[(toupper(str[i]) - 'A')];
            //printf("%c %d\n", str[i], (toupper(str[i]) - 'A'));
        }
    }

    for (int i = 0; i < ALPHANUMERIC_CHARS; ++i) {
        if(chars[i] > 0){
            printf("%c %d\n", (i + 'A'), chars[i]);
        }

    }

    return 0;
}



