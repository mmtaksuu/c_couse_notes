/**
 * @file    : LESSON_28 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 07 / March / 2020
 * @code    : locale_test.c source file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h>
#include <time.h>
#include <string.h>
#include "../includes/locale_test.h"


char* generate_log_file_name(void)
{
    setlocale(LC_TIME, "turkish");
    //printf("locale degistirildi yeni locale: (%s)\n", p);

    char FILE_LABEL[SIZE] = "Kayit_Log_";

    /** Deifines time label */
    char TIME_LABEL[40];
    time_t timer;
    time(&timer);
    strftime(TIME_LABEL, sizeof(TIME_LABEL), "%d_%b_%Y_%a_%H_%M_%S", localtime(&timer));
//    printf("TIME : (%s)\n", TIME_LABEL);

    /** Deifines file extension and binds with time label */
    char FILE_EXTENSION[] = ".tab";
    char *fname = strcat(TIME_LABEL, FILE_EXTENSION);

    char *full_name = strcat(FILE_LABEL, fname);
//    printf("Log File Name : (%s)\n", full_name);

    return full_name;
}


void set_random_struct(FILE *f, TOPLU_VERILER_t *toplu_veri_t)
{
    randomize();
    for (size_t i = 0; i < SIZE; ++i) {
        toplu_veri_t->girdiler_t.sistem_zamani_ms      = (UINT16) (i + 1);
        toplu_veri_t->girdiler_t.enlem                 = (float)rand()/(float)(RAND_MAX/10.0);
        toplu_veri_t->girdiler_t.boylam                = (float)rand()/(float)(RAND_MAX/10.0);
        toplu_veri_t->girdiler_t.sinyal_1_irtifa_cm    = (float)rand()/(float)(RAND_MAX/1000.0);
        toplu_veri_t->girdiler_t.sinyal_2_irtifa_cm    = (float)rand()/(float)(RAND_MAX/1000.0);
        toplu_veri_t->girdiler_t.sinyal_1_ok           = (rand() % 2 ? 1 : 0);
        toplu_veri_t->girdiler_t.sinyal_2_ok           = (rand() % 2 ? 1 : 0);

        write_log(toplu_veri_t);
        save_log_file(f, toplu_veri_t);
    }
}


void write_log(TOPLU_VERILER_t * toplu_veriler_t)
{
    toplu_veriler_t->ciktilar_t.sistem_zamani_ms   = toplu_veriler_t->girdiler_t.sistem_zamani_ms;
    toplu_veriler_t->ciktilar_t.enlem              = toplu_veriler_t->girdiler_t.enlem;
    toplu_veriler_t->ciktilar_t.boylam             = toplu_veriler_t->girdiler_t.boylam;
    toplu_veriler_t->ciktilar_t.sinyal_1_irtifa_cm = toplu_veriler_t->girdiler_t.sinyal_1_irtifa_cm;
    toplu_veriler_t->ciktilar_t.sinyal_2_irtifa_cm = toplu_veriler_t->girdiler_t.sinyal_2_irtifa_cm;
    toplu_veriler_t->ciktilar_t.sinyal_1_ok        = toplu_veriler_t->girdiler_t.sinyal_1_ok;
    toplu_veriler_t->ciktilar_t.sinyal_2_ok        = toplu_veriler_t->girdiler_t.sinyal_2_ok;
}

void save_log_file(FILE *f, TOPLU_VERILER_t *toplu_veri_t)
{
    fprintf(f, "%d\t%f\t%f\t%f\t%f\t%3d\t%3d\n", toplu_veri_t->ciktilar_t.sistem_zamani_ms,
                                                 toplu_veri_t->ciktilar_t.enlem,
                                                 toplu_veri_t->ciktilar_t.boylam,
                                                 toplu_veri_t->ciktilar_t.sinyal_1_irtifa_cm,
                                                 toplu_veri_t->ciktilar_t.sinyal_2_irtifa_cm,
                                                 toplu_veri_t->ciktilar_t.sinyal_1_ok,
                                                 toplu_veri_t->ciktilar_t.sinyal_2_ok);

}


