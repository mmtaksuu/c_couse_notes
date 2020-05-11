/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / May / 2020
 * @code    : character_manipulations_in_pnames.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helper.h"


static void convert_to_upper(char *p)
{
    for (size_t i = 0; p[i] != '\0'; ++i) {
        p[i] = (char)toupper(p[i]);
    }
}

int main(void)
{
    for (size_t i = 0; i < asize(pnames); ++i) {
        char stemp[100];
        strcpy(stemp, pnames[i]);
        convert_to_upper(stemp);
        printf("%-16s %-16s\n", pnames[i], stemp);
    }

    return 0;
}

