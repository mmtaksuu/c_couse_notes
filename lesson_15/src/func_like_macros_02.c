/*
  Project Name: LESSON_15
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 10 / Ocak / 2020	
  File Description: func_like_macros_02.c file 
*/


// Definitions of some function-like moacros

#define     isupper(c)      ((c) >= 'A' && (c) <= 'Z')
#define     islower(c)      ((c) >= 'a' && (c) <= 'z')
#define     isalpha(c)      (isupper(c) || islower(c))

#include <stdio.h>

int main(void)
{
    char ch;
    printf("Enter a character : ");
    scanf("%c", &ch);

    if isupper(ch)
        printf("%c is upper word.\n", ch);
    else if islower(ch)
        printf("%c is lower word.\n", ch);
    else if isalpha(ch)
        printf("%c is an alphanumeric.\n", ch);
    else
        printf("%c is not an alphanumeric.\n", ch);






    return 0;
}
