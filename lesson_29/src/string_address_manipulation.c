/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / May / 2020
 * @code    : string_address_manipulation.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"

int main(void)
{
    const char *pmons[] = {
            "",
            "Ocak",
            "Subat",
            "Mart",
            "Nisan",
            "Mayis",
            "Haziran",
            "Temmuz",
            "Agustos",
            "Eylul",
            "Ekim",
            "Kasim",
            "Aralik"
    };

    char entry_name[20];
    printf("Enter a month name : ");
    scanf("%s", entry_name);

    size_t i;
    for (i = 1; i < asize(pmons); ++i) {
        if (!stricmp(pmons[i], entry_name))
            break;
    }

    if (i < asize(pmons))
        printf("%s is the %d th month\n", pmons[i], i);
    else
        printf("%s is not a month name\n", entry_name);

    return 0;
}
