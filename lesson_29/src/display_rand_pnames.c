/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / May / 2020
 * @code    : display_rand_pnames.c file
 * @details : 
 */

#include <stdio.h>
#include <conio.h>
#include <winbase.h>
#include "helper.h"

#define     EXIT    'Q'

int main(void)
{
    randomize();
    while (is_hit_button(EXIT))
    {
        size_t idx = rand() % asize(pnames);
        printf("%c ", pnames[idx][0]);      // prints first character
        printf("%-16s %u ", pnames[idx], strlen(pnames[idx])); // prints string and its len
        printf("%c \n", pnames[idx][strlen(pnames[idx]) - 1]); // prints last character
        Sleep(200);
    }

    return 0;
}

