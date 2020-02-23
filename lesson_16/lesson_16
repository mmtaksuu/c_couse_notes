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

    int cnt = 0;

    for (int i = x; i <= y; ++i) {
        if (isprime(i)) {
            printf("%d ", i);
            if (cnt && cnt % 10 == 0)
                sl();
            sleep(0.03);
            ++cnt;
        }
    }

    return 0;
}
```


switch statement

label


switch (integer exp) {
case 2:
case 5:
statementx;
case 6:

}

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


case 'A' :

case "B" : //gecersiz

case 3.4:

case ival:

sembolik sabit
enumaration


switch (getCardSuit(Card)) {
case CLUB   :
case DIAMOND:
case HEART  :
case SPADE :
}

case  NEC + XYZ:

case 1 << 4 :
case 1 << 4 :
case 1 << 5 :

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
/**********************************************************************************************************************/
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
/**********************************************************************************************************************/
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
/**********************************************************************************************************************/
```


switch (x) {
case 2: case 5: case 123: case 194: case 212: case 345:

x = 10;

}