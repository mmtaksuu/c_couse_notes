/**
 * @file    : LESSON_7 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / May / 2020
 * @code    : writes_ascii_characters.c file
 * @details : 
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE * f;

    if ((f = fopen("../src/ascii.txt", "w")) == NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 128; ++i) {
        if (iscntrl(i))
            fprintf(f, "0x%02X  %3d  Control Character\n", i, i); //Control Characters are not printable
        else
            fprintf(f, "0x%02X  %3d   %c\n", i, i, i);
    }

    fclose(f);

    return 0;
}



