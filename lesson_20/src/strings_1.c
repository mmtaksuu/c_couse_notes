/*
  Project Name: LESSON_20
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 26 / January / 2020	
  File Description: strings_1.c file 
*/

#include <stdio.h>
#include <string.h>

#define     SIZE              100

int main(void)
{
    printf("Null Character : %d\n", '\0'); // 0
    printf("Zero Character : %d\n", '0');  // 48

    // Yaziyi Ekrana tersten yazdirin.
    // Extra dizi kullanmadan yapin.

    char str[SIZE] = "MEHMET AKSU";

    int len = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        ++len;

    printf("Normal string: ");
    for (int i = 0; str[i] != '\0'; ++i)
        printf("%c", str[i]);

    printf("\nReversed string: ");
    for (int i = 0; str[i] != '\0'; ++i)
        printf("%c", str[len - 1 - i]);


    return 0;
}
