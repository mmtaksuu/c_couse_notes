/**
 * @file    : project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 19 / April / 2020
 * @code    : babil_algorithm.c file
 * @details : 
 */


#include <stdio.h>

#define     SIZE    100
#define     BELIRLENEN_HATA_DEGERI    0.002


double get_babil_sqrt(double n, double x)
{
    double tahmin[SIZE]    = {0};

    double tahminin_karesi = 0.0;
    double hata_degeri     = 0.0;

    tahmin[0] = x;

    int i = 0;


    while (1)
    {
        tahmin[i+1] = ( tahmin[i] + (n / tahmin[i]) ) * 0.5;

        tahminin_karesi = ( tahmin[i+1] * tahmin[i+1] );

        hata_degeri = tahminin_karesi - n;

        printf("%-.16f %.16f\n", tahmin[i], hata_degeri);

        if (hata_degeri < BELIRLENEN_HATA_DEGERI)
        {
            return tahmin[i+1];
        }

        ++i;

    }

}


int main(void)
{
    double n, x;
    printf("Karekoku alinacak sayiyi ve tahmin degerini giriniz : \n");
    scanf("%lf%lf", &n, &x);

    double result = get_babil_sqrt(n, x);
    printf("Girdiginiz sayinin karekoku %.3f\n", result);

    return 0;
}


