/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 10 / May / 2020
 * @code    : memmove_str_prepend_exp.c file
 * @details : 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * add_prepend(char *pdest, const char * psource)
{
    size_t dest_len = strlen(pdest);
    size_t src_len  = strlen(psource);

    memmove(pdest+src_len, pdest, dest_len+1);
    memcpy(pdest, psource, src_len);

    return pdest;
}

int main(void)
{
    char str[100] = "@hotmail.com";

    char name_entry[100];
    printf("Enter your e-mail address : ");
    scanf("%s", name_entry);

    add_prepend(str, name_entry);
    printf("%s is a valid e-mail address.\n", str);

    return 0;
}
