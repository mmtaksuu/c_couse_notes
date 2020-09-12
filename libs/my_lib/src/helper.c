/**
 * @file    : MY_LIB project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / February / 2020
 * @code    : helper.c file
 * @details : 
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "helper.h"


int gen_rand_int_nums(void)
{
    return rand() % 30;
}


double gen_rand_real_nums(void)
{
    return rand()/(RAND_MAX/30.0);
}


void set_random_array(int *p, size_t size)
{
    while (size --)
        *p++ = gen_rand_int_nums();
}


void display_array(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%3d%c", p[i], i % 20 == 19 ? '\n' : ' ');
    }
    printf("\n-------------------------------------------------------------------------------\n");
}


void set_random_array_d(double *p, size_t size)
{
    while (size--)
        *p++ = gen_rand_real_nums();
}


void display_array_d(const double *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%.3f%c", p[i], i % 10 == 9 ? '\n' : ' ');
    }
    printf("\n-------------------------------------------------------------------------------\n");
}

int find_imax(const int *p, size_t size)
{
    int max = p[0];

    for (size_t i = 1; i < size; ++i)
        if (p[i] > max)
            max = p[i];

    return max;
}

double find_dmax(const double *p, size_t size)
{
    double max = p[0];

    for (size_t i = 1; i < size; ++i)
        if (p[i] > max)
            max = p[i];

    return max;
}

void hist_rand_numbers(const int *p, size_t size)
{
    int max = find_imax(p, size);

    for (int i = max; i > 0; --i) {
        printf("%2d |  ", i);
        for (size_t j = 0; j < size; ++j) {
            if (p[j] >= i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}


char *sgets(char *p)
{
    char *ptemp = p;
    int ch;

    while((ch = getchar()) != '\n')
        *p++ = (char)ch;

    *p = '\0';

    return ptemp;
}



int gcmp(const void *vp1, const void *vp2, size_t width)
{
    const char *p1 = (const char *)vp1;
    const char *p2 = (const char *)vp2;

    int p1_cnt = 0;
    int p2_cnt = 0;

    while (width--)
    {
        if (*p1 > *p2)
            ++p1_cnt;

        if (*p1 < *p2)
            ++p2_cnt;

        ++p1;
        ++p2;
    }

    if (p1_cnt > p2_cnt)
        return 1;

    if (p1_cnt < p2_cnt)
        return -1;

    return 0;
}


void delay(double sec)
{
    clock_t start = clock();

    while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}

int is_hit_button(int ch)
{
    return (_kbhit() && toupper(_getch()) == ch);
}


void bit_print(UINT16 val)
{
    char str[20];
    _itoa(val, str, 2);
    printf("%016s\n", str);
}

const char *pnames[300] = {
        "Kamil", "Korhan", "Beril", "Turhan", "Ufuk", "Murathan", "Figen", "Malik", "Bulent", "Cengiz",
        "Baran", "Nurullah", "Dilber", "Tuncer", "Recep", "Pelinsu", "Cihan", "Yesim", "Aziz", "Kazim",
        "Afacan", "Tevfik", "Sumeyye", "Hande", "Aslihan", "Emine", "Temel", "Gulsah", "Hasan", "Gul",
        "Soner", "Ayla", "Cuneyt", "Tekin", "Binnaz", "Emrecan", "Yasar", "Yilmaz", "Feraye", "Tugra",
        "Melek", "Garo", "Yurdagul", "Tarik", "Derin", "Handan", "Aytac", "Petek", "Cem", "Aylin",
        "Gursel", "Haldun", "Nazife", "Hulusi", "Sevilay", "Sabriye", "Gulden", "Tansel", "Ege", "Turgut",
        "Cahit", "Berk", "Nazli", "Aykut", "Kayhan", "Cemre", "Murat", "Kunter", "Gunay", "Cahite",
        "Nedim", "Metin", "Kerim", "Utku", "Cumhur", "Kurthan", "Poyraz", "Can", "Candan", "Hikmet",
        "Izzet", "Perihan", "Tufan", "Zahide", "Samet", "Melih", "Hakan", "Ayse", "Refik", "Efe",
        "Belgin", "Bilal", "Niyazi", "Fugen", "Melike", "Saadet", "Cemile", "Nahit", "Arda", "Ugur",
        "Aynur", "Yasin", "Polat", "Naz", "Yusuf", "Gulsen", "Nazif", "Demir", "Egemen", "Necmi",
        "Fazilet", "Celal", "Ismail", "Kamile", "Mahir", "Caner", "Suleyman", "Cezmi", "Diana", "Sadullah",
        "Atif", "Huseyin", "Necmettin", "Devlet", "Sezen", "Hulya", "Necmiye", "Ece", "Julide", "Onat",
        "Emre", "Sinem", "Teoman", "Irmak", "Cihat", "Adem", "Bilgin", "Muzaffer", "Suphi", "Pelin",
        "Yalcin", "Kenan", "Atalay", "Akin", "Durmus", "Haluk", "Kelami", "Alparslan", "Busra", "Kasim",
        "Durriye", "Tarcan", "Nihal", "Gizem", "Bilge", "Dilek", "Yasemin", "Fahri", "Furkan", "Papatya",
        "Hakki", "Fadime", "Devrim", "Abdi", "Tayyip", "Yurdakul", "Zekai", "Nagehan", "Ata", "Naci",
        "Mert", "Yelda", "Cebrail", "Rumeysa", "Beyhan", "Azize", "Cemil", "Sezer", "Beste", "Ciler",
        "Enes", "Cahide", "Tayyar", "Cansu", "Burak", "Ediz", "Sefa", "Anil", "Alev", "Atil",
        "Nefes", "Cetin", "Tansu", "Bora", "Sevim", "Sarp", "Fuat", "Kaya", "Zarife", "Tanju",
        "Su", "Kerem", "Handesu", "Jade", "Halime", "Gurbuz", "Okan", "Azmi", "Sevda", "Leyla",
        "Galip", "Alican", "Atakan", "Feramuz", "Efecan", "Osman", "Nihat", "Sefer", "Zerrin", "Binnur",
        "Taner", "Kayahan", "Nalan", "Tonguc", "Kezban", "Kaan", "Abdulmuttalip", "Dost", "Deniz", "Refika",
        "Tijen", "Umit", "Yunus", "Zahit", "Melisa", "Hulki", "Hilmi", "Edip", "Muslum", "Canan",
        "Dogan", "Berivan", "Adnan", "Helin", "Fikret", "Derya", "Sidre", "Abdullah", "Billur", "Nurdan",
        "Agah", "Engin", "Burhan", "Suheyla", "Esra", "Sadri", "Sezai", "Esen", "Askin", "Rupen",
        "Ercument", "Birhan", "Ahmet", "Polathan", "Tayfun", "Mustafa", "Zubeyde", "Pakize", "Nevsin", "Naciye",
        "Erdem", "Asim", "Orkun", "Sami", "Sade", "Demet", "Keriman", "Yavuz", "Mehmet", "Muhsin",
        "Saniye", "Cesim", "Aydan", "Eda", "Hilal" ,"Burak", "Taylan", "Fedai", "Ilke", "Dogancan",	"Rezzan",
        "Ozer", "Tacettin", "Nurettin", "Seyfettin", "Safiye", "Aydin", "Latife", "Sercan", "Benfero"
};

