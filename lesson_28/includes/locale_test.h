/**
 * @file    : LESSON_28 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / March / 2020
 * @code    : locale_test.h header file
 * @details : 
 */

#ifndef LESSON__LOCALE_TEST_H
#define LESSON__LOCALE_TEST_H

#include <stdint.h>

#define     SIZE              100
#define     randomize()       (srand((unsigned)time(NULL)))

typedef float    FLOAT32;
typedef double   FLOAT64;
typedef uint16_t UINT16;
typedef uint8_t  UINT8;

typedef struct {
    UINT16  sistem_zamani_ms;
    FLOAT64 enlem;
    FLOAT64 boylam;
    FLOAT64 sinyal_1_irtifa_cm;
    FLOAT64 sinyal_2_irtifa_cm;
    UINT8   sinyal_1_ok;
    UINT8   sinyal_2_ok;
} INPUTS_t;

typedef struct {
    UINT16  sistem_zamani_ms;
    FLOAT64 enlem;
    FLOAT64 boylam;
    FLOAT64 sinyal_1_irtifa_cm;
    FLOAT64 sinyal_2_irtifa_cm;
    UINT8   sinyal_1_ok;
    UINT8   sinyal_2_ok;
} OUTPUTS_t;

typedef struct {
    INPUTS_t  girdiler_t;
    OUTPUTS_t ciktilar_t;
} TOPLU_VERILER_t;


void set_random_struct(FILE *f, TOPLU_VERILER_t *);
void save_log_file(FILE *, TOPLU_VERILER_t *);
void write_log(TOPLU_VERILER_t *);


#endif //LESSON__LOCALE_TEST_H
