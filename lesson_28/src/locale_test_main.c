/**
 * @file    : LESSON_28 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / March / 2020
 * @code    : locale_test_main.c client code file
 * @details : 
 */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../includes/locale_test.h"
#include "log_file_name_generator.h"



int main(void)
{

    TOPLU_VERILER_t toplu_veriler_t = {0};

    char log_file_name[SIZE] = {0};
    strcpy(log_file_name, generate_log_file_name(log_file_name, ".csv"));

    char path[SIZE] = "../";
    strcat(path, log_file_name);

    FILE *fptr;

    fptr = fopen(path, "w");

    if (fptr == NULL)
        return printf("File is not created!\n"), 1;

    fprintf(fptr, "sistem_zamani_ms\t"
                  "enlem\t"
                  "boylam\t"
                  "sinyal_1_irtifa_cm\t"
                  "sinyal_2_irtifa_cm\t"
                  "sinyal_1_ok\t"
                  "sinyal_2_ok\n");


    set_random_struct(fptr, &toplu_veriler_t);

    fclose(fptr);

    printf("%s file was succesfully saved! \n", log_file_name);


    return 0;
}
