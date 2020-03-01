LESSON_32
--------

####Definition of Type of Function Addresses in C

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


//geri dönüş değeri olmayan patametresi strcmp gibi bir fonksiyon adresi isteyen ismi foo olan fonksiyonu bildirin
void foo(int(*fp)(const char *, const char *));
void func(int(*fp1)(const char *, const char *), int(*fp2)(const char *, const char *));
int(*f(int(*fp1)(const char *, const char *), int(*fp2)(const char *, const char *)))(const char *, const char *);


int main()
{
    int(*fp)(const char *, const char *) = &strcmp;
    int(*fpa[])(const char *, const char *) = { strcmp, strcoll, _stricmp };
    int(**fpp)(const char *, const char *) = &fp;

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


typedef int(*FCMP)(const char *, const char *);

//geri dönüş değeri olmayan patametresi strcmp gibi bir fonksiyon adresi isteyen ismi foo olan fonksiyonu bildirin
//void foo(int(*fp)(const char *, const char *));
void foo(FCMP);


//void func(int(*fp1)(const char *, const char *), int(*fp2)(const char *, const char *));
void func(FCMP, FCMP);

//int(*f(int(*fp1)(const char *, const char *), int(*fp2)(const char *, const char *)))(const char *, const char *);
FCMP f(FCMP, FCMP);

int main()
{

    //int(*fp)(const char *, const char *) = &strcmp;
    FCMP fp = &strcmp;
    
    
    //int(*fpa[])(const char *, const char *) = { strcmp, strcoll, _stricmp };
    FCMP fpa[] = { strcmp, strcoll, _stricmp };
    //int(**fpp)(const char *, const char *) = &fp;
    FCMP *fpp = &fp;

}
```

```c++
#include <iostream>

using namespace std;

typedef void(*TerminateHandler)(void);

//void(*set_terminate(void(*)(void)))(void);
TerminateHandler set_terminate(TerminateHandler);

int main()
{

}
```

####Implementation of Qsort Using Standard Library Function
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "nutility.h"

#define			SIZE		100

int icmp(const void *vp1, const void *vp2)
{
    if (*(const int *)vp1 > *(const int *)vp2)
        return 1;
    
    if (*(const int *)vp1 < *(const int *)vp2)
        return -1;
    
    return 0;
}

int icmp(const void *vp1, const void *vp2)
{
    return *(const int *)vp1 - *(const int *)vp2;  //populer ama yanlis cunku tasma riski var.
}


int dcmp(const void *vp1, const void *vp2)
{
    if (*(const double *)vp1 > *(const double *)vp2)
        return 1;
    
    if (*(const double *)vp1 < *(const double *)vp2)
        return -1;
    
    return 0;
}


int main()
{
    int a[SIZE];
    
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    
    qsort(a, SIZE, sizeof(int), &icmp);
    
    display_array(a, SIZE);
    
    double da[] = { 9.8, 7.2, 45.78, 1.29, 8.7, 4.5, 87.61, 6.78, 92.57, 69.81, 245.78, 8.714 };
    qsort(da, asize(da), sizeof(*da), &dcmp);
    
    for (size_t i = 0; i < asize(da); ++i) {
        printf("%f\n", da[i]);
    }

}
```

```text
Bir int turden diziyi qsort işlevi ile
ciftler basta (buyukten kucuge)
tekler ciftlerden sonra (buyukten kucuge)
siralayacak sekilde bir callback yazip qsort'u cagirin
```


####Implementation of Bubble Sort Algorithm by Writing a Generic gsort() Function
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "nutility.h"

#define			SIZE		100


void gsort(void *vpa, size_t size, size_t width, int(*fp)(const void *, const void *))
{
    char *p = vpa;
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t k = 0; k < size - 1 - i; ++k) {
            if (fp(p + k * width, p + (k + 1) * width) > 0) {
                gswap(p + k * width, p + (k + 1) * width, width);
            }
        }
    }
}


int icmp(const void *vp1, const void *vp2)
{
    if (*(const int *)vp1 > *(const int *)vp2)
        return -1;
    
    if (*(const int *)vp1 < *(const int *)vp2)
        return 1;
    
    return 0;
}


int dcmp(const void *vp1, const void *vp2)
{
    if (*(const double *)vp1 > *(const double *)vp2)
        return 1;
    
    if (*(const double *)vp1 < *(const double *)vp2)
        return -1;
    
    return 0;
}


int main()
{
    int a[SIZE];
    
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    
    gsort(a, SIZE, sizeof(int), &icmp);
    
    display_array(a, SIZE);
    
    double da[] = { 9.8, 7.2, 45.78, 1.29, 8.7, 4.5, 87.61, 6.78, 92.57, 69.81, 245.78, 8.714 };
    gsort(da, asize(da), sizeof(*da), &dcmp);
    
    for (size_t i = 0; i < asize(da); ++i) {
        printf("%f\n", da[i]);
    }

}
```

####Implementation of Binary Search Algorithm Using Standard Library Function called bsearch() and our generic gsort() Function
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "nutility.h"

#define			SIZE		100


void gsort(void *vpa, size_t size, size_t width, int(*fp)(const void *, const void *))
{
    char *p = vpa;
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t k = 0; k < size - 1 - i; ++k) {
            if (fp(p + k * width, p + (k + 1) * width) > 0) {
                gswap(p + k * width, p + (k + 1) * width, width);
            }
        }
    }
}


int icmp(const void *vp1, const void *vp2)
{
    if (*(const int *)vp1 > *(const int *)vp2)
        return 1;
    
    if (*(const int *)vp1 < *(const int *)vp2)
        return -1;
    
    return 0;
}


int dcmp(const void *vp1, const void *vp2)
{
    if (*(const double *)vp1 > *(const double *)vp2)
        return 1;
    
    if (*(const double *)vp1 < *(const double *)vp2)
        return -1;
    
    return 0;
}


int main()
{
    int a[SIZE];
    
    randomize();
    set_random_array(a, SIZE);
    
    qsort(a, SIZE, sizeof(int), &icmp);
    
    display_array(a, SIZE);
    
    int ival;
    printf("aranacak degeri girin: ");
    scanf("%d", &ival);
    
    int *ptr = (int *)bsearch(&ival, a, SIZE, sizeof *a, &icmp);
    
    if (ptr != NULL) {
        printf("bulundu...  %d. indisli oge\n", ptr - a);
    }
    else {
        printf("bulunamadi\n");
    }
		
}
```


####Sorting a char Array using standard qsort() Function 
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nutility.h"


char *p[] = {
    "kamil", "korhan", "beril", "turhan", "ufuk", "murathan", "figen", "malik", "bulent", "cengiz",
    "baran", "nurullah", "dilber", "tuncer", "recep", "pelinsu", "cihan", "yesim", "aziz", "kazim",
    "afacan", "tevfik", "sumeyye", "hande", "aslihan", "emine", "temel", "gulsah", "hasan", "gul",
    "soner", "ayla", "cuneyt", "tekin", "binnaz", "emrecan", "yasar", "yilmaz", "feraye", "tugra",
    "melek", "garo", "yurdagul", "tarik", "derin", "handan", "aytac", "petek", "cem", "aylin",
    "gursel", "haldun", "nazife", "hulusi", "sevilay", "sabriye", "gulden", "tansel", "ege", "turgut",
    "cahit", "berk", "nazli", "aykut", "kayhan", "cemre", "murat", "kunter", "gunay", "cahite",
    "nedim", "metin", "kerim", "utku", "cumhur", "kurthan", "poyraz", "can", "candan", "hikmet",
    "izzet", "perihan", "tufan", "zahide", "samet", "melih", "hakan", "ayse", "refik", "efe",
    "belgin", "bilal", "niyazi", "fugen", "melike", "saadet", "cemile", "nahit", "arda", "ugur",
    "aynur", "yasin", "polat", "naz", "yusuf", "gulsen", "nazif", "demir", "egemen", "necmi",
    "fazilet", "celal", "ismail", "kamile", "mahir", "caner", "suleyman", "cezmi", "diana", "sadullah",
    "atif", "huseyin", "necmettin", "devlet", "sezen", "hulya", "necmiye", "ece", "julide", "onat",
    "emre", "sinem", "teoman", "irmak", "cihat", "adem", "bilgin", "muzaffer", "suphi", "pelin",
    "yalcin", "kenan", "atalay", "akin", "durmus", "haluk", "kelami", "alparslan", "busra", "kasim",
    "durriye", "tarcan", "nihal", "gizem", "bilge", "dilek", "yasemin", "fahri", "furkan", "papatya",
    "hakki", "fadime", "devrim", "abdi", "tayyip", "yurdakul", "zekai", "nagehan", "ata", "naci",
    "mert", "yelda", "cebrail", "rumeysa", "beyhan", "azize", "cemil", "sezer", "beste", "ciler",
    "enes", "cahide", "tayyar", "cansu", "burak", "ediz", "sefa", "anil", "alev", "atil",
    "nefes", "cetin", "tansu", "bora", "sevim", "sarp", "fuat", "kaya", "zarife", "tanju",
    "su", "kerem", "handesu", "jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla",
    "galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
    "taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
    "tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
    "dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
    "agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen",
    "ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
    "erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
    "saniye", "cesim", "aydan", "eda", "hilal", "burak", "taylan", "fedai", "ilke", "dogancan",
    "rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero",
    };


int scmp(const void *vp1, const void *vp2)
{
    return strcmp(*(char **)vp1, *(char **)vp2);
}


int main()
{
    qsort(p, asize(p), sizeof(char *), &scmp);
    
    for (size_t i = 0; i < asize(p); ++i) {
        if (i && i % 5 == 0)
            printf("\n");
        printf("%-16s ", p[i]);
    }
}
```


Function Pointer Arrays
-----------------------

####Birbirine map edilmis iki look-up table kullanarak girilen karakter ve fonksiyon ismine gore sonucu bulma
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nutility.h"


//standart giriş akımından bir karakter alin.
//yine standart giriş akımından ismi alınan standart c karakter test fonksiyonu ile
//sınama yapıp sonucu ekrana yazdirin

typedef int(*Fptest)(int);

const Fptest fpa[] = { &isupper, &islower, &isalpha, &isdigit, &isalnum, &isxdigit, &ispunct,	&isprint, &isspace, &isblank, &isgraph, &iscntrl };
const char * const fpname[] = { "isupper", "islower", "isalpha", "isdigit", "isalnum", "isxdigit", "ispunct",	"isprint", 
"isspace", "isblank", "isgraph", "iscntrl"};

void test()
{
    printf("bir karakter girin: ");
    int c = getchar();
    char fname_entry[40];
    printf("test islevi ismi: ");
    scanf("%s", fname_entry);
    
    
    size_t i;
    
    for (i = 0; i < asize(fpname) && strcmp(fname_entry, fpname[i]); ++i)
        ;
    
    if (i == asize(fpname)) {
        printf("standart boyle bir islev olmadigindan size hizmet veremiyoruz\n");
    }
    else if (fpa[i](c))
        printf("%s testinde (%c) karakteri sonucu OK!\n", fname_entry, c);
    else
        printf("%s testinde (%c) karakteri sonucu NOT OK!\n", fname_entry, c);
    clear_input_buffer();

}



int main()
{
    test();
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nutility.h"
#include <conio.h>


void moveup()
{
    printf("karakter yukari gidiyor\n");
}

void movedown()
{
    printf("karakter asahi gidiyor\n");
}

void moveleft()
{
    printf("karakter sola gidiyor\n");
}

void moveright()
{
    printf("karakter saga gidiyor\n");
}

void rotateright()
{
    printf("karakter saga donuyor\n");
}

void rotateleft()
{
    printf("karakter sola donuyor\n");
}

void stop()
{
    printf("karakter duruyor\n");
}


void(*fp[])(void) = { &moveup, &movedown, &moveleft, &moveright, &rotateleft, &rotateright, &stop };

int main()
{
    randomize();
    
    for (;;) {
        fp[rand() % asize(fp)]();
        _getch();
    }

}
```

C / C++ Kütüphanelerinde Sık Kullanılan Bir Yapı
------------------------------------------------

#### 1. Kullanim Temasi
```text
Global bir function pointer tanimlanarak yapilir.
```
```c
//tema_1.h File
#pragma once

typedef void(*Fptr)(void);

//bfunc islevinin varsayilan davranisi fneco islevini cagirmak
void bfunc(void);
Fptr setbfunc(Fptr);
//------------------------------------------------------------------

//tema_1.c File
#include "tema_1.h"
#include <stdio.h>

void fneco(void);

static Fptr gfp = &fneco;

void fneco(void)
{
    printf("fneco islevi cagrildi\n ");
}

void bfunc(void)
{
    gfp();
}


Fptr setbfunc(Fptr fp)
{
    Fptr retval = gfp;
    gfp = fp;
    return retval;
}
//------------------------------------------------------------------

// main.c File
#include <stdio.h>
#include "tema_1.h"

void fdogan(void)
{
    printf("fdogan islevi cagrildi\n");
}


int main()
{
    bfunc(); //bfunc burada fneco islevini cagirmali
    Fptr fp = setbfunc(&fdogan);
    bfunc(); //bfunc burada fdogan islevini cagirmali
    setbfunc(fp);
    bfunc(); //bfunc burada fneco islevini cagirmali

}
```

#### 2. Kullanim Temasi
```text
Global bir function pointer array tanimlanarak yapilir.

Exit fonksiyonu programi sonlandirmadan once 
AtExit isimli fonksiyon ile kayit edilmis fonksiyonlari
stack sistemi ile çağırır.
Son olarak da programi sonlandirir.
```

```c
// tema_2.h File
#pragma once

typedef void(*FCLEANUP)(void);

void Exit(void);
int AtExit(FCLEANUP);
//------------------------------------------------------------------

// tema_2.c File
#include "tema_2.h"
#include <stdio.h>

#define			MAX_AT_EXIT    10

static FCLEANUP ga[MAX_AT_EXIT];
static int gcount = 0;

void Exit(void)
{
    printf("ben Exit fonksiyonuyum kayit edilen fonksiyonlari cagiriyorum\n");
    
    for (int i = gcount - 1; i >= 0; --i)
        ga[i]();
}

int AtExit(FCLEANUP fp)
{
    if (gcount == MAX_AT_EXIT)
        return 1;
    
    ga[gcount++] = fp;
    return 0;
}
//------------------------------------------------------------------

// main.c File
#include "tema_2.h"

void fc1(void)
{
    printf("fc1 gerekli temizlik islemlerini yapti\n");
}

void fc2(void)
{
    printf("fc2 gerekli temizlik islemlerini yapti\n");
}


void fc3(void)
{
    printf("fc3 gerekli temizlik islemlerini yapti\n");
}

void fc4(void)
{
    printf("fc4 gerekli temizlik islemlerini yapti\n");
}


int main()
{
    AtExit(fc1);
    // Codes
    AtExit(fc2);
    // Codes
    AtExit(fc3);
    // Codes
    AtExit(fc4);
    // Codes
    Exit();

}
//------------------------------------------------------------------
```






Multi-Dimensional Arrays in C
-----------------------------

```c
#include <stdio.h>
#include "nutility.h"

int main()
{
    int a[10][20];
    
    printf("sizeof(a) = %zu\n", sizeof(a));       // 10 * 20 * 4 = 800 
    printf("sizeof(a[0]) = %zu\n", sizeof(a[0])); // 1 * 20 * 4 = 80
    printf("sizeof(a[0][0]) = %zu\n", sizeof(a[0][0])); // 1 * 1 * 4 = 4
    
    printf("boyut a = %zu\n", asize(a)); // 800 / 80 = 10
}
```


```c
#include <stdio.h>
#include "nutility.h"

// b ile c nin turleri ayni yalnizca eleman sayilari farklidir.
// digerlerinin ise turleri tamamen birbirlerinden farklidir.

int main()
{
    int a[10][20]; // Elemanlarinin turu int [20] olan 10 elemanli dizi
    int b[5][10];  // Elemanlarinin turu int [10] olan 5 elemanli dizi
    int c[8][8];   // Elemanlarinin turu int [8]  olan 8 elemanli dizi
    int c[4][10];  // Elemanlarinin turu int [10] olan 4 elemanli dizi

}
```

