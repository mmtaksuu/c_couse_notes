Kosullu Derleme
---------------

```c
#defined NECO
#ifdef   NECO
	#ifndef  DOGAN
	typedef int Word
	#endif
#endif
```

```c
#define  NECO

#if defined   NECO &&  !defined  DOGAN
	typedef int Word
#endif
```


multiple inclusion guard
------------------------

```c
#ifndef  NUTILITY_H
#define  NUTILITY_H

struct Data {
	int x, y, z;
};

#endif
```


```c
#define   DOLLAR    1
#define   EURO		2
#define   GBP		3
#define   YEN		4

#define   CURRENCY       YEN


#if  CURRENCY == DOLLAR
	const char *const pcur = "dollar";
#else
	#if  CURRENCY == EURO
		const char *const pcur = "dollar";
	#else
#if  CURRENCY == GBP
const char *const pcur = "pound";
#else
#if  CURRENCY == YEN
const char *const pcur = "yen";
#endif
#endif
#endif
#endif
```


```c
#define   DOLLAR    1
#define   EURO		2
#define   GBP		3
#define   YEN		4

#define   CURRENCY       YEN


#if  CURRENCY == DOLLAR
	const char *const pcur = "dollar";
#elif  CURRENCY == EURO
		const char *const pcur = "dollar";
#elif  CURRENCY == GBP
const char *const pcur = "pound";
#elif  CURRENCY == YEN
const char *const pcur = "yen";
#endif


#undef
```



```c
#define    max2(a, b)   ((a) > (b) ? (a) : (b))
#undef  max2


#undef      NEC
#define     NEC   100
```


ÖN TANIMLI SEMBOLİK SABİTLER
predefined symbolic constants
-----------------------------

```c
__LINE__
__FILE__
__DATE__
__TIME__

__func__
__STDC__
```


``` c
#include <stdio.h>

void print_name()
{
    printf("%s\n", __func__);
    ///....
}

int main()
{
    printf("%s dosyasinin %d. satiri\n", __FILE__, __LINE__);
    printf("DATE = %s\n", __DATE__);
    printf("TIME = %s\n", __TIME__);
    print_name();
}
```

``` c
#include <stdio.h>

int main()
{
    printf("%d\n", __COUNTER__);
    printf("%d\n", __COUNTER__);
    printf("%d\n", __COUNTER__);
    printf("%d\n", __COUNTER__);
    printf("%d\n", __COUNTER__);
}
```

``` c
#include <stdio.h>
#include "nutility.h"

int main()
{
    int x, y;
    
    printf("iki tamsayi giriniz: ");
    scanf("%d%d", &x, &y);
    if (x > y)
        x ^= y, y ^= x, x ^= y;  //xorswap

}
```

``` c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

int main()
{
    int x, y;
    
    printf("iki tamsayi giriniz: ");
    scanf("%d%d", &x, &y);
    if (x > y)
        swap(&x, &y);

    int size = 0;

    for (int i = x; i <= y; ++i) {
        if (isprime(i)) {
            printf("%d ", i);
            if (size && size % 10 == 0)
                sl();
            sleep(0.03);
            ++size;
        }
    }

    return 0;
}
```


switch statement
---------------

label


```c
switch (integer exp) {
case 2:
case 5:
    statementx;
case 6:

}
```

``` c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	switch (x) {
	case 1: printf("bir\n");
	case 2: printf("iki\n");
	case 3: printf("uc\n");
	case 4: printf("dort\n");
	case 5: printf("bes\n");
	}

}
```


```c
case 'A' :

case "B" : //gecersiz

case 3.4:

case ival:
```

sembolik sabit
enumaration


```c
switch (getCardSuit(Card)) {
case CLUB   :
case DIAMOND:
case HEART  :
case SPADE :
}
```

```c
case  NEC + XYZ:

case 1 << 4 :
case 1 << 4 :
case 1 << 5 :
```

``` c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"


int main()
{
	int d, m, y;

	printf("dogum tarihinizi giriniz: ");
	scanf("%d%d%d", &d, &m, &y);

	switch (day_of_the_week(d, m, y)) {
	case 0: printf("Pazar\n"); break;
	case 1: printf("Pazartesi\n"); break;
	case 2: printf("Sali\n"); break;
	case 3: printf("Carsamba\n"); break;
	case 4: printf("Persembe\n"); break;
	case 5: printf("Cuma\n"); break;
	case 6: printf("Cumartesi\n"); break;
	}

}
```

``` c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n;

	printf("haftanin kacinci gunu : ");
	scanf("%d", &n);

	switch (n) {
	default:printf("gecersiz gun\n"); break;
	case 1: printf("Pazartesi\n"); break;
	case 2: printf("Sali\n"); break;
	case 3: printf("Carsamba\n"); break;
	case 4: printf("Persembe\n"); break;
	case 5: printf("Cuma\n"); break;
	case 6: printf("Cumartesi\n"); break;
	case 7: printf("Pazar\n"); break;
	}

}
```


``` c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print_season(int m)
{
	switch (m) {
	case 3:
	case 4:
	case 5: printf("ilkbahar\n"); break;
	case 6:
	case 7:
	case 8: printf("Yaz\n"); break;
	case 9:
	case 10:
	case 11: printf("sonbahar\n"); break;
	case 12:
	case 1:
	case 2: printf("kis\n"); break;
	default: printf("gecersiz ay\n");
	}
}

int main()
{
	int n;

	printf("haftanin kacinci gunu : ");
	scanf("%d", &n);

	switch (n) {
	default:printf("gecersiz gun\n"); break;
	case 1: printf("Pazartesi\n"); break;
	case 2: printf("Sali\n"); break;
	case 3: printf("Carsamba\n"); break;
	case 4: printf("Persembe\n"); break;
	case 5: printf("Cuma\n"); break;
	case 6: printf("Cumartesi\n"); break;
	case 7: printf("Pazar\n"); break;
	}

}
```
