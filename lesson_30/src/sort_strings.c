/**
 * @file    : LESSON_30 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 09 / May / 2020
 * @code    : sort_pnames.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"

void display_names(char **p, size_t size)
{
    while (size--)
    {
        printf("%s \n", *p++);
    }
    printf("\n-------------------------------------------------------------------------------\n");
}


void swap_str(char **p1, char **p2)
{
    char *ptemp = *p1;
    *p1 = *p2;
    *p2 = ptemp;
}


int scmp(const char *p1, const char *p2)
{
    return strcmp(p1, p2);
}


void sort_string(char **p, size_t size, int(*fp)(const char *, const char *))
{
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t k = 0; k < size - 1 - i; ++k) {
            if (fp(p[k], p[k+1]) > 0)
                swap_str(&p[k], &p[k+1]);
        }
    }
}


int main(void)
{
    /** Defines pointer array to (char *) */
    char *names[] = {"Kamil", "Korhan", "Beril", "Turhan", "Ufuk", "Murathan", "Figen", "Malik", "Bulent", "Cengiz", "Ali"};

    display_names(names, asize(names));
    sort_string(names, asize(names), &scmp);
    display_names(names, asize(names));

    return 0;
}


