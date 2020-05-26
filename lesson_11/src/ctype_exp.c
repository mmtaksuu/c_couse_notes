/**
 * @file    : LESSON_11 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 26 / May / 2020
 * @code    : ctype_exp.c file
 * @details : 
 */

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define     EXIT    'Q'

void delay(double delay_time)
{
    clock_t start = clock();

    while ((double )(clock() - start)/CLOCKS_PER_SEC < delay_time)
        ;
}

int is_hit_button(int ch)
{
    return (_kbhit() && toupper(_getch()) == ch);
}

void randomize(void)
{
    srand((unsigned)time(NULL));
}

void print_char(int c)
{
    if (isupper(c))
        printf("Upper Case\n");

    if (islower(c))
        printf("Lower Case\n");

    if (isalpha(c))
        printf("Alphabetic Character\n");

    if (isdigit(c))
        printf("Digit\n");

    if (isalnum(c))
        printf("Alpha Numeric\n");

    if (isxdigit(c))
        printf("Hexadecimal Digit\n");

    if (ispunct(c))
        printf("Punctuation Character\n");

    if (isspace(c))
        printf("Space Character\n");

    if (isblank(c))
        printf("Blank Character\n");

    if (isprint(c))
        printf("Printable Character\n");

    if (isgraph(c))
        printf("Graphical Character\n");

    if (iscntrl(c))
        printf("Control Character \n");
}


int main(void)
{
    randomize();

    for (;;) {
        int c = rand() % 128;
        if (isgraph(c)) {
            printf("%c\n", c);
            print_char(c);
            printf("\n\n");
            delay(1); // sn
        }

        if (is_hit_button(EXIT))
            break;
    }

    return 0;
}
