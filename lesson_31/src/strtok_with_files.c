/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / Mayıs / 2020
 * @code    : strtok_with_files.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"

#define     BUF_SIZE    1024

void get_from_file(void)
{
    FILE * f;
    char line[BUF_SIZE];

    if ((f = fopen("C:\\Users\\Cezeri_NPC\\Desktop\\Ucus_Verileri\\Veriler\\log_file_01.tab", "r")) == NULL){
        fprintf(stderr, "File couldn't openned!\n");
        exit(EXIT_FAILURE);
    }

    fgets(line, sizeof(line), f);

    char * token = NULL;
    while (fgets(line, sizeof(line), f) != NULL){
        for (token = strtok(line, "\t\n"); token != NULL; token = strtok(NULL, "\t\n"))
            printf("%s\n", token);
        printf("\n------------------------------------------\n");
    }

    free(token);

}

int main(void)
{

    get_from_file();

    return 0;
}
