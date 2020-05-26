/**
 * @file    : LESSON_8 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 24 / May / 2020
 * @code    : get_presicion_after_comma_for_numbers.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ndigit(int x)
{
    int digit_cnt = 0;

    if (!x)
        return 1;

    while (x != 0) {
        ++digit_cnt;
        x /= 10;
    }

    return digit_cnt;
}


int get_presicion(char *str)
{
    int vals[2] = {0};
    int i = 0;

    char * token = NULL;
    for (token = strtok(str, "."); token != NULL; token = strtok(NULL, "\n")){
        vals[i++] = atoi(token);
    }

    return ndigit(vals[1]);
}



int main(void)
{
    char str[100];
    printf("Enter a real number : ");
    scanf("%s", str);

    printf("Presicion is %d digit\n", get_presicion(str));

    return 0;
}


