/**
 * @file    : LESSON_29 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / May / 2020
 * @code    : find_name_in_pnames.c file
 * @details : 
 */


#include <stdio.h>
#include <string.h>
#include "helper.h"

int main(void)
{
    char entry_name[30];
    printf("Enter a name : ");
    scanf("%s", entry_name);

    size_t i;
    for (i = 0; i < asize(pnames); ++i) {
        if (!stricmp(pnames[i], entry_name))
            break;
    }

    if (i < asize(pnames))
        printf("%s is found at %u index\n", pnames[i], i);
    else
        printf("%s is not found\n", entry_name);

    return 0;
}


