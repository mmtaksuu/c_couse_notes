# LESSON 36
## Yapi Nesneleri ve Fonksiyonlar Arasindaki Iliski

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	int x, y, z;
	char str[20];
	int a[20];
}Data;


void f1(Data); //call by value
void f2(Data *); //mutator - set functions //output parameter
void f3(Data *); //input-output  in-out

void f4(const Data *); //accessor - getter - get functions - input parameter
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//matrix.h

typedef struct Matrix_ {
	int a[40][40];
	int row, col;
}Matrix;

void add_matrix(const Matrix *p1, const Matrix *p2, Matrix *presult);

int main()
{
	printf("sizeof(Matrix) = %zu\n", sizeof(Matrix));
	//mx = ma + mb;

	Matrix ma, mb;
	///
	Matrix mx; //toplam işleminden elde edilen matrisi tutacak

	add_matrix(&ma, &mb, &mx);
}
```



```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


typedef struct {
	int x, y, z;
	char str[20];
	int a[20];
}Data;

Data f1(/* ???? */);

Data *f2(/* ???? */);
const Data *f3(/* ???? */);

int main()
{
	Data mydata;
	///

	mydata = f1();

}
```



```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


struct Data{
	int x, y, z;
}Data;

typedef struct Data Data;
typedef struct Data* DataPtr;

int main()
{
	Data mydata = { 10, 20, 30 };
	Data dx= { 20, 79, 45 };
	const DataPtr p = &mydata;

	p = &dx;  // struct Data *const p = &mydata;
	*p = dx;  // const struct Data *p = &mydata;

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


struct Data{
	int x, y, z;
};


typedef const struct Data* CDataPtr;

int main()
{
	struct Data d1 = { 1, 3, 5 };
	struct Data d2 = { 2, 5, 1};

	CDataPtr p = &d1;

	p = &d2;
	*p = d2; //gecersiz
}
```

## Yapilar ile ilgili Kutuphaneler

```text
1) C tarzı kütüphaneler 
2) OOP tarzı kütüphaneler


struct Fighter {
	int power;
	Weapon a[10];
	int gender;
	int age;
};


struct Fighter {
	void *vptr;
};


get_age(&f)
set_age


struct Fighter {
	
	Weapon a[10];
	int gender;
	int age;
	int d, m, y;
};
```




```c

#include <stdio.h>
#include <string.h>
#include "nutility.h"
#include <stdlib.h>


#define			SIZE		5

int main()
{
	char entry[100];
	char *p[SIZE];

	for (int i = 0; i < 5; ++i) {
		printf("yazi girin: ");
		sgets(entry);
		p[i] = _strdup(entry);
	}

	for (int i = 0; i < 5; ++i) {
		puts(p[i]);
	}

	for (int i = 0; i < 5; ++i) {
		free(p[i]);
	}

}
```


```c
#include <stdio.h>
#include <string.h>
#include "nutility.h"
#include <stdlib.h>


#define			SIZE		5
#define			MAX_LEN		32

int main()
{
	char names[SIZE][MAX_LEN + 1];

	for (int i = 0; i < 5; ++i) {
		printf("ismi girin: ");
		sgets(names[i]);
	}

	for (int i = 0; i < 5; ++i) {
		puts(names[i]);
	}
	
}
```


# Standart Time Kutuphanesi
## <time.h> Header File

```text
time_t		türü  (calender time)
struct tm	türü  (broken-down time)

clock_t		türü



struct tm {
	int tm_year;  //2020 - 1900
	int tm_mon;   //0 Ocak, 1 Subat 2 Mart
	int tm_mday;  //
	int tm_yday;   //0 => 1 ocak  
	int tm_wday;   //0 Pazar ---> 1 Pazartesi
	int tm_hour;  // 0 - 24
	int tm_min;   //0-59
	int tm_sec;    //0 - 59
	int tm_isdst; 
};

is daylight saving time

tm_isdst < 0
	bilgi tutulmuyor
tm_isdst > 0  gun isigi t.modunda
tm_isdst = 0  gun isigi t.modunda
```



```c
#include <time.h>
#include <stdio.h>

int main(void)
{
    time_t timer;

    time(&timer);

    printf("saniye = %ld\n", timer);

    return 0;
}
```


```c
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define     EXIT     'Q'

int main(void)
{

    while (!kbhit() || toupper(_getch() )!= EXIT)
        printf("saniye = %ld\r", time(NULL));
    
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdio.h>
#include <conio.h>

void display_current_time()
{
	static const char *const pmons[] = {
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
	};

	static const char *const pdays[] = {
	"Pazar",
	"Pazartesi",
	"Sali",
	"Carsamba",
	"Persembe",
	"Cuma",
	"Cumartesi",
	};

	time_t timer;
	time(&timer);
	struct tm *p = localtime(&timer);

	printf("%02d %s %d %s %02d:%02d:%02d\r", p->tm_mday, pmons[p->tm_mon], p->tm_year + 1900,
	pdays[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
	
}

#define			ESC      0X1B

int main()
{
	while (!_kbhit() || _getch() != ESC)
		display_current_time();

	printf("\nprogram calismaya devam ediyor\n");
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdio.h>
#include <conio.h>

void display_current_time()
{
	static const char *const pmons[] = {
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
	};

	static const char *const pdays[] = {
	"Pazar",
	"Pazartesi",
	"Sali",
	"Carsamba",
	"Persembe",
	"Cuma",
	"Cumartesi",
	};

	time_t timer;
	time(&timer);
	struct tm *p = gmtime(&timer);

	printf("%02d %s %d %s %02d:%02d:%02d\n", p->tm_mday, pmons[p->tm_mon], p->tm_year + 1900,
	pdays[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
	
	if (p->tm_isdst < 0) {
		printf("bu sistemde gun isigi tasarruf modu verisi tutulmuyor\n");
	}
	else if (p->tm_isdst) {
		printf("gun isigi tarassuf modundayiz\n");
	}
	else {
		printf("gun isigi tarassuf modunda degiliz\n");
	}

}


int main()
{
	display_current_time();
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdio.h>
#include "nutility.h"
#include <stdlib.h>
#include <conio.h>


int main()
{
	size_t n;

	printf("kac ogeli bir dizi: ");
	scanf("%zu", &n);
	int *pd = malloc(n * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n");
		return 1;
	}
	set_random_array(pd, n);

	printf("siralama basladi\n");
	clock_t start = clock();
	sort(pd, n);
	clock_t end = clock();
	double sec = (double)(end - start) / CLOCKS_PER_SEC;

	printf("siralama bitti %f saniye\n", sec);
	_getch();
	display_array(pd, n);
	free(pd);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void delay(double sec)
{
	clock_t timer = clock();

	while ((double)(clock() - timer) / CLOCKS_PER_SEC < sec)
		;
}



int main()
{
	int stime = 200;
	int i = 0;
	for (;;) {
		printf(".");
		if (i % 10 == 0) {
			stime -= 10;
			if (stime == 0)
				break;
		}
		++i;
		Sleep(stime);
	}

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

int main()
{
	time_t timer;
	time(&timer);
	struct tm *p = localtime(&timer);

	printf("(%s)\n", ctime(&timer));
	printf("(%s)\n", asctime(p));

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

int main()
{
	int min;

	printf("bu andan kac dakika sonrasi: ");
	scanf("%d", &min);

	time_t timer;
	time(&timer);

	timer += min * 60;
	puts(ctime(&timer));

}
```

