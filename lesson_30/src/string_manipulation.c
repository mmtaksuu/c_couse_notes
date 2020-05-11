/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : string_manipulation.c file
 * @details : 
 */


#include <stdio.h>
#include <string.h>

char *f1(void)
{
    return "Oruc";
}

char *f2(void)
{
    return "Tut";
}

char *f3(void)
{
    return "Sihhat";
}

char *f4(void)
{
    return "Bul!";
}

char *f5(void)
{
    return "\n";
}

int main(void)
{
    char s1[] = "ali";
    char s2[] = "mehmet";
    char s3[] = "kayhan";
    char s4[] = "cetin";
    char s5[] = "semih";

    char *p[] = { s1, s2, s3, s4, s5 };
    char *fp[] = { f1(), f2(), f3(), f4(), f5() };

    puts(s4);

    p[3][0] = 's';
    p[3][2] = 'l';

    puts(s4);

    putchar('\n');
    for (size_t i = 0; i < 5; ++i)
        printf("%s ", p[i]);

    for (size_t i = 0; i < 5; ++i) {
        strcpy(p[i], fp[i]);
    }

    putchar('\n');
    for (size_t i = 0; i < 5; ++i)
        printf("%s ", p[i]);


    return 0;
}

