/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 03 / May / 2020
 * @code    : test03.c file
 * @details :
 */

#include <basetsd.h>
#include <stdlib.h>
#include <stdio.h>

#define     SENSOR_SAYISI               2

#define     Set_bit(val, n)         ((val) |= (1u << (n)))
#define     Reset_bit(val, n)       ((val) &= ~(1u << (n)))


typedef struct {
    UINT8 sinyal_hata_durum_u8;
}SINYAL_BILGILER_t;

typedef struct {
    SINYAL_BILGILER_t   sinyal_t;
}VERILER_t;


void print_bit(UINT8 val)
{
    char str[20];
    _itoa(val, str, 2);
    printf("%08s\n", str);
}



int main(void)
{
    VERILER_t veriler_t = {0};

    const char * const sinyal_hatalari[4*SENSOR_SAYISI] = {"sinyal_1_aralik_durum",
                                                           "sinyal_1_donma_durum",
                                                           "sinyal_1_ziplama_durum",
                                                           "sinyal_1_supheli_durum",
                                                           "sinyal_2_aralik_durum",
                                                           "sinyal_2_donma_durum",
                                                           "sinyal_2_ziplama_durum",
                                                           "sinyal_2_supheli_durum",
    };

    print_bit(veriler_t.sinyal_t.sinyal_hata_durum_u8);
    printf("ival = %hhd\n", veriler_t.sinyal_t.sinyal_hata_durum_u8);
    printf("\\----------------------------------------\n");


    UINT8 bit_val;
    for (size_t i = 0; i < 4*SENSOR_SAYISI; ++i)
    {
        printf("Enter %s as a bit value : ", sinyal_hatalari[i]);
        scanf("%hhd", &bit_val);

        if (bit_val == 1u)
            Set_bit(veriler_t.sinyal_t.sinyal_hata_durum_u8, i);
        else
            Reset_bit(veriler_t.sinyal_t.sinyal_hata_durum_u8, i);

    }

    print_bit(veriler_t.sinyal_t.sinyal_hata_durum_u8);
    printf("ival = %hhd\n", veriler_t.sinyal_t.sinyal_hata_durum_u8);
    printf("\\----------------------------------------\n");


    return 0;
}


