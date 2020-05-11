/**
 * @file    : c_couse_notes project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / Mayıs / 2020
 * @code    : my_strtok_func.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"


char * my_strtok(const char * str, const char * delim)
{
    static char * dyn_pos;
    char * begin, * dyn_str;

    if (str != NULL)
        dyn_pos = (char *)str;

    /** Delimiter bulunmasi */
    while (*dyn_pos != '\0' && strchr(delim, *dyn_pos) != NULL)
        ++dyn_pos;

    if (*dyn_pos == '\0')
        return NULL;
    else
        begin = dyn_pos;

    /** Delimiter bulunmamasi */
    while (*dyn_pos != '\0' && strchr(delim, *dyn_pos) == NULL)
        ++dyn_pos;

    if ((dyn_str = (char *)malloc((unsigned int) (dyn_pos - begin + 1))) == NULL)
        return NULL;

    strncpy(dyn_str, begin, (unsigned int)(dyn_pos - begin));
    dyn_str[dyn_pos - begin] = '\0';

    if (*dyn_pos != '\0')
        ++dyn_pos;

    return dyn_str;
}



int main(void)
{
    char str[100];
    printf("Enter a text : ");
    sgets(str);

    char *token = my_strtok(str, " ");

    while (token != NULL){
        printf("%s\n", token);
        token = my_strtok(NULL, " ");
    }


    return 0;
}
