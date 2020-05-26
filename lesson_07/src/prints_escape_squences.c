/**
 * @file    : LESSON_7 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / May / 2020
 * @code    : prints_escape_squences.c file
 * @details : 
 */

#include <stdio.h>

int main(void)
{
    printf("null character  = 0x%02X %3d %c\n", '\0', '\0', '\0');
    printf("alert           = 0x%02X %3d %c\n", '\a', '\a', '\a');
    printf("newline         = 0x%02X %3d %c\n", '\n', '\n', '\n');
    printf("horizontal  tab = 0x%02X %3d %c\n", '\t', '\t', '\t');
    printf("vertical tab    = 0x%02X %3d %c\n", '\v', '\v', '\v');
    printf("carriage return = 0x%02X %3d %c\n", '\r', '\r', '\r');
    printf("backspace       = 0x%02X %3d %c\n", '\b', '\b', '\b');
    printf("form feed       = 0x%02X %3d %c\n", '\f', '\f', '\f');
    printf("back slash      = 0x%02X %3d %c\n", '\\', '\\', '\\');
    printf("single quote    = 0x%02X %3d %c\n", '\'', '\'', '\'');
    printf("double quote    = 0x%02X %3d %c\n", '\"', '\"', '\"');
    printf("double quote    = 0x%02X %3d %c\n", '"' , '"' , '"' );
    printf("question mark   = 0x%02X %3d %c\n", '\?', '\?', '\?');
    printf("question mark   = 0x%02X %3d %c\n", '?' , '?' , '?' );

    return 0;
}

