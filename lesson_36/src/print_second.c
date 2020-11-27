/**
 * @file    : LESSON_36 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 19 / September / 2020
 * @code    : print_second.c file
 * @details : 
 */


#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>


int is_hit_button(int ch)
{
    return (_kbhit() && toupper(_getch()) == ch);
}

int main(void)
{
    while (!is_hit_button('Q'))
        printf("Second : %ld\r", time(NULL));

    return 0;
}



