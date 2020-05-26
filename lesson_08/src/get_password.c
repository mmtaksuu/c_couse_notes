/**
 * @file    : LESSON_8 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 24 / May / 2020
 * @code    : get_password.c file
 * @details : 
 */

#include <stdio.h>
#include <conio.h>

int main(void)
{
    printf("Enter password : ");
    int c1 = _getch();
    putchar('*');
    int c2 = _getch();
    putchar('*');
    int c3 = _getch();
    putchar('*');
    int c4 = _getch();
    putchar('*');

    printf("\nEntered Password is : %c%c%c%c\n", c1, c2, c3, c4);

    return 0;
}
