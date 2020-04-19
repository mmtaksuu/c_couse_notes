/**
 * @file    : LESSON_17 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 19 / April / 2020
 * @code    : log_file_name_generator.c file
 * @details : 
 */


#include <locale.h>
#include <time.h>
#include <string.h>
#include "log_file_name_generator.h"


char * get_time_label(char * p_time)
{
    setlocale(LC_TIME, "turkish");
    //printf("locale degistirildi yeni locale: (%s)\n", p);

    time_t timer;
    time(&timer);
    strftime(p_time, TIME_LABEL_LEN, "%d_%b_%Y_%a_%H_%M_%S", localtime(&timer));
//    printf("TIME : (%s)\n", p_time);

    return p_time;
}


char* generate_log_file_name(char *p_fname, const char *p_extension)
{
    char FILE_LABEL[FILE_NAME_LEN] = "Kayit_Log_";

    /** Deifines time label */
    char TIME_LABEL[TIME_LABEL_LEN];


    /** Deifines file extension and binds with time label */
    char *fname = strcat(get_time_label(TIME_LABEL), p_extension);

    p_fname = strcat(FILE_LABEL, fname);
//    printf("Log File Name : (%s)\n", full_name);

    return p_fname;
}


