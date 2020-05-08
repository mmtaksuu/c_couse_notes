/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : check_is_all_characters_unique.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "helper.h"


static int is_all_unique(const char * p)
{
    if (*p == '\0')
        return 0;

    int char_set[256] = {0};

    for (size_t i = 0; p[i] != '\0' ; ++i) {
        int ch = tolower(p[i]);
        ++char_set[ch];
    }

    size_t i;
    for (i = 0; p[i] != '\0' ; ++i) {
        if (char_set[tolower(p[i])] != 1)
            break;
    }

    if (i == strlen(p))
        return 1;

    return 0;

}

int main(void)
{
    for (size_t i = 0; i < asize(pnames); ++i) {
        if (is_all_unique(pnames[i]))
            printf("%-16s\n", pnames[i]);
    }

    return 0;
}


