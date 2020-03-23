# Complete type / Incomplete type


```c

struct Data;

struct Data f1(struct Data);
struct Data * f2(struct Data *);
struct Data * f3(void);

typedef struct Data Data;
typedef struct Data* DataPtr;

extern struct Data gx;
extern struct Data a[];

struct Neco {
	struct Data *mp;
	//...
};

int main()
{
	struct Data *p = f3();
	f2(p);

}
```


```c
#include <stdio.h>

struct Data;

struct Data* func(void);

int main()
{
	//struct Data mydata;
	struct Data *p = func();

	size_t x = sizeof(struct Data); //Gecersiz
	size_t x = sizeof(*p); //Gecersiz

    // Hepsi gecersizdir
	(*p).x;
	p->y
	*p;
	p[2]

}
```


```c
#include <stdio.h>


struct Data* f1(struct Data *);

typedef struct Mehmet Mehmet;

int main()
{
	struct Cenk *ptr = NULL;
	Mehmet *p;
}
```


# date.h kutuphanesi icin Client Kod Ornekleri

```c
#include "date.h"

int main()
{
	Date d1;
	set_date(&d1, 19, 5, 1976);
	print_date(&d1);

	Date d2;
	set_date_today(&d2);
	print_date(&d2);

	Date d3;
	set_date_str(&d3, "15/05/1992");
	print_date(&d3);

}
```

```c
#include "date.h"

int main()
{
	Date dx;
	for (int i = 0; i < 1000; ++i) {
		random_date(&dx);
		print_date(&dx);
	}
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dcmp(const void *vp1, const void *vp2)
{
	return cmp_date((const Date *)vp1, (const Date *)vp2);
}

int main()
{
	size_t n;

	printf("kac tarih: ");
	scanf("%zu", &n);
	Date *pd = (Date*)malloc(n * sizeof(Date));
	if (!pd) {
		printf("bellek yetersiz\n");
		return 1;
	}


	for (size_t i = 0; i < n; ++i) {
		random_date(pd + i);
	}

	printf("siralama basladi\n ");
	clock_t start = clock();
	
	qsort(pd, n, sizeof(*pd), &dcmp);

	clock_t end = clock();
	printf("siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(pd);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	Date bdate;

	printf("dogum tarihinizi giriniz: ");
	scan_date(&bdate);
	print_date(&bdate);
	Date todays_date;
	set_date_today(&todays_date);

	int n = get_date_diff(&todays_date, &bdate);
	printf("bugun hayatinizin %d. gununu yasiyorsunuz\n", n);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	Date today;
	set_date_today(&today);
	Date future_date;

	printf("bugun : ");
	print_date(&today);
	for (int i = 1; i < 1'000'000'000; i *= 10) {
		printf("%d gun sonrasi: ", i);
		ndaysafter(&future_date, &today, i);
		print_date(&future_date);
	}

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	Date bdate;

	printf("dogum tarihiniz: ");
	scan_date(&bdate);
	print_date(&bdate);
}
```

# Composition (Bilesik Nesneler)


```c
#pragma pack(1)

#include <stdio.h>

struct Neco {
	int x, y, z;
};


struct Data {
	struct Neco ncx;
	int a, b, c;
	double dval;
};

int main()
{
	printf("sizeof(struct Neco) = %zu\n", sizeof(struct Neco));
	printf("sizeof(struct Data) = %zu\n", sizeof(struct Data));
}
```

```c
#pragma pack(1)

#include <stdio.h>

struct Neco {
	int x, y, z;
};


struct Data {
	struct Neco ncx;
	int a, b, c;
	double dval;
};

int main()
{
	struct Data mydata;
	struct Data *p = &mydata;

	//mydata.ncx.y
	//p->ncx.y
}
```


```c
#pragma pack(1)

#include <stdio.h>

struct Neco {
	int x, y, z;
};


struct Data {
	struct Neco *pn;
	int a, b, c;
	double dval;
};

int main()
{
	struct Neco myneco;
	struct Data mydata;
	mydata.pn = &myneco;

	struct Data *pdata = &mydata;
	pdata->pn->y = 34;
	mydata.pn->y = 10;

}
```


```c
#pragma pack(1)

#include <stdio.h>

#include "date.h"

struct Employee {
	int no;
	char name[24];
	Date bdate;
};

int main()
{
	//struct Employee emp = { 12, "havva altintas", {12, 5, 1998} };
	//struct Employee emp = { .bdate = {18, 12, 2002} };
	struct Employee emp = { .bdate = {.my = 2002} };
} 
```

```c
#pragma pack(1)

#include <stdio.h>

#include "date.h"

struct Employee {
	int no;
	char name[24];
	Date bdate;
};

int main()
{
	//struct Employee emp = { 12, "havva altintas", {12, 5, 1998} };
	//struct Employee emp = { .bdate = {18, 12, 2002} };
	struct Employee emp = { .bdate = {.my = 2002} };
} 
```

# student.h kutuphanesi icin Client Kod Ornekleri

```c
#include "student.h"
#include <Windows.h>
#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <stdlib.h>


#define			SIZE		20

typedef int(*FCMP)(const void *, const void *);

void print_student_array(const Student *p, size_t size)
{
	while (size--)
		print_student(p++);
}

int main()
{
	FCMP fpa[] = {

		(FCMP)&cmpStudentbyNo,
		(FCMP)&cmpStudentbyName,
		(FCMP)&cmpStudentbySurname,
		(FCMP)&cmpStudentbyTown,
		(FCMP)&cmpStudentbyDate,
	};

	Student a[SIZE];
	randomize();

	for (int i = 0; i < SIZE; ++i) {
		random_student(a + i);
		//print_student(a + i);
	}

	for (size_t i = 0; i < asize(fpa); ++i) {
		qsort(a, SIZE, sizeof(*a), fpa[i]);
		print_student_array(a, SIZE);
		_getch();
		system("cls");
	}
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <Windows.h>
#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <stdlib.h>


#define			SIZE		20

typedef int(*FCMP)(const void *, const void *);

void print_menu()
{
	printf(
		"[1] numaraya gore\n"
		"[2] isme gore\n"
		"[3] soyisme gore\n"
		"[4] sehre gore\n"
		"[5] dogum tarihine gore\n"
		"secenegi girin: ");
}

void print_student_array(const Student *p, size_t size)
{
	while (size--)
		print_student(p++);
}

int main()
{
	FCMP fpa[] = {

		(FCMP)&cmpStudentbyNo,
		(FCMP)&cmpStudentbyName,
		(FCMP)&cmpStudentbySurname,
		(FCMP)&cmpStudentbyTown,
		(FCMP)&cmpStudentbyDate,
	};

	Student a[SIZE];
	randomize();

	for (int i = 0; i < SIZE; ++i) {
		random_student(a + i);
		//print_student(a + i);
	}


	for (;;) {
		print_menu();
		int option;
		scanf("%d", &option);
		Sleep(200);
		system("cls");
		qsort(a, asize(a), sizeof(*a), fpa[option - 1]);
		print_student_array(a, SIZE);
		_getch();
		system("cls");
	}

}
```

