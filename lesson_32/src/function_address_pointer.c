/**
 * @file    : LESSON_32 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 02 / Mart / 2020
 * @code    : function_address_pointer_01.c file
 * @details : 
 */

#include <stdio.h>
#include <string.h>


// strcmp gibi bir fonksiyonun adresini tutan degisken turunun typedef bildiriminin yapilmasi
typedef int(*FCMP)(const char *, const char *);

//geri dönüş değeri olmayan parametresi strcmp gibi bir fonksiyonun adresini isteyen ismi foo olan fonksiyonu bildirin
void foo1(int(*fp)(const char *, const char *));
void foo2(FCMP fp);


//geri dönüş değeri olmayan parametre olarak strcmp gibi bir fonksiyonun adresini isteyen iki parametre alan ve ismi func olan fonksiyonu bildirin
void func1(int(*fp1)(const char *, const char *), int(*fp2)(const char *, const char *));
void func2(FCMP fp1, FCMP fp2);


//geri dönüş değeri strcmp gibi bir foksiyonun adresi olan ve parametre olarak strcmp gibi bir fonksiyonun adresini isteyen iki parametre alan ve ismi f olan fonksiyonu bildirin
int(*f1(int(*fp1)(const char *, const char *), int(*fp2)(const char *, const char *)))(const char *, const char *);
FCMP f2(FCMP, FCMP);


int main(void)
{
    // strcmp'nin adresini tutan bir pointer degiskeninin tanimi
    int(*fpx1)(const char *, const char *) = &strcmp;
    FCMP fpx2 = &strcmp;


    // strcmp ile ayni parametre sayisi, turu ve geri donus degerine sahip 3 farkli fonksiyonun adresini tutan bir function pointer array degiskeninin tanimi
    int(*fpa1[])(const char *, const char *) = { strcmp, strcoll, _stricmp };
    FCMP fpa2[] = { strcmp, strcoll, _stricmp };


    // fpx function pointer degiskeninin adresini tutan bir pointer degiskeninin tanimi
    int(**fpp11)(const char *, const char *) = &fpx1;
    FCMP *fpp12 = &fpx2;


    // fpa function pointer array degiskeninin adresini tutan bir pointer degiskeninin tanimi
    int(**fpp21)(const char *, const char *) = &fpa1;
    FCMP *fpp22 = &fpa2;

    return 0;
}
