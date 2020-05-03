/**
 * @file    : LESSON_40 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 03 / May / 2020
 * @code    : test04.c file
 * @details : 
 */


#include <stdio.h>
#include <basetsd.h>
#include <stdlib.h>


typedef union _Sinyal_Hata_Durum {
    UINT8 sinyal_hata_durum_u8;
    struct {
        UINT8 sinyal_1_aralik_durum  : 1;
        UINT8 sinyal_1_donma_durum   : 1;
        UINT8 sinyal_1_ziplama_durum : 1;
        UINT8 sinyal_1_supheli_durum : 1;
        UINT8 sinyal_2_aralik_durum  : 1;
        UINT8 sinyal_2_donma_durum   : 1;
        UINT8 sinyal_2_ziplama_durum : 1;
        UINT8 sinyal_2_supheli_durum : 1;
    };
}Sinyal_Hata_Durum_t;


void print_bit(UINT8 val)
{
    char str[20];
    _itoa(val, str, 2);
    printf("%08s\n", str);
}


int main(void)
{
    Sinyal_Hata_Durum_t sinyal_t = { 0 };

    printf("sizeof sinyal_hata_durum = %u Bytes \n", sizeof(sinyal_t));
    printf("sinyal_hata_durum_u8 = %u\n", sinyal_t.sinyal_hata_durum_u8);


    const char * const sinyal_hatalari[8] = {"sinyal_1_aralik_durum",
                                             "sinyal_1_donma_durum",
                                             "sinyal_1_ziplama_durum",
                                             "sinyal_1_supheli_durum",
                                             "sinyal_2_aralik_durum",
                                             "sinyal_2_donma_durum",
                                             "sinyal_2_ziplama_durum",
                                             "sinyal_2_supheli_durum",
    };


    print_bit(sinyal_t.sinyal_hata_durum_u8);
    printf("sinyal_hata_durum_u8 = %hhd\n", sinyal_t.sinyal_hata_durum_u8);
    printf("\\----------------------------------------\n");


    UINT8 bit_val = 0;
    for (size_t i = 0; i < 8; ++i)
    {
        printf("%s : ", sinyal_hatalari[i]);
        scanf("%hhd", &bit_val);

        if (bit_val == 1u)
        {
            switch (i)
            {
                case 0 : sinyal_t.sinyal_1_aralik_durum  = 1; break;
                case 1 : sinyal_t.sinyal_1_donma_durum   = 1; break;
                case 2 : sinyal_t.sinyal_1_ziplama_durum = 1; break;
                case 3 : sinyal_t.sinyal_1_supheli_durum = 1; break;
                case 4 : sinyal_t.sinyal_2_aralik_durum  = 1; break;
                case 5 : sinyal_t.sinyal_2_donma_durum   = 1; break;
                case 6 : sinyal_t.sinyal_2_ziplama_durum = 1; break;
                case 7 : sinyal_t.sinyal_2_supheli_durum = 1; break;
                default: ; break;
            }
        }

    }

    print_bit(sinyal_t.sinyal_hata_durum_u8);
    printf("sinyal_hata_durum_u8 = %hhd\n", sinyal_t.sinyal_hata_durum_u8);
    printf("\\----------------------------------------\n");

    return 0;
}

