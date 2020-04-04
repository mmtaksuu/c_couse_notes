# Lesson 38

```text
Konu Basliklari

    self-referential structures
    linked-list veri yapısı
    handle tekniği ve veri gizleme
    alignment (hizalama)

node (düğüm)

struct Node{
	Data its_data
	struct Node *p;
};



linked list (bağlı liste)
	singly linked list (tekli bağlı liste)
	doubly linked list (çifte bağlı liste)
	rotating linked list


12   7    8    9    5   3   6    1
 	                    |
```

## Linked List Test Kodlari

```c
//test1

#include "studentlist.h"
#include "student.h"
#include "nutility.h"
#include <stdio.h>
#include <conio.h>


int main()
{
	Student s;

	randomize();
	for (int i = 0; i < 10; ++i) {
		random_student(&s);
		print_student(&s);
		push_front(&s);
	}
	printf("\n\n\n");
	_getch();
	print_list();
}
```

```c
//test2

#include "studentlist.h"
#include "student.h"
#include "nutility.h"
#include <conio.h>


int main()
{
	int n;
	Student s;

	printf("kac ogrenci\n ");
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		random_student(&s);
		push_front(&s);
	}

	printf("ekleme islemi tamamlandi\n");
	_getch();
	print_list();
	make_empty();

}
```

```c
//test3

#include "studentlist.h"
#include "student.h"
#include "nutility.h"
#include <conio.h>
#include <stdlib.h>


int main()
{
	Student s;

	randomize();
	int n = rand() % 10 + 10;

	while (n--) {
		random_student(&s);
		push_front(&s);
	}
	printf("\n\n");

	while (!is_empty()) {
		print_list();
		pop_front();
		_getch();
		system("cls");
	}
}
```

## Handle Sistemi ile Veri Yapilari Uzerinde Calisma

```text
f1(Data *)
f2()
f3()
f4()
f5()
f6()

struct Data {
	d1, d2, d3, d4, d5
}


ListHandle create_list(void);
void close_list(ListHandle);
```

## Handle Sistemi Implementasyonu Cliend Kodu


```c
#include "studentlist_handle.h"
#include "student.h"
#include <stdio.h>
#include "nutility.h"
#include <stdlib.h>
#include <conio.h>

#define    NLIST			1000

int main()
{
	ListHandle a[NLIST];
	Student s;

	randomize();

	for (int i = 0; i < NLIST; ++i) {
		a[i] = create_list();
		int n = rand() % 10 + 10;
		while (n--) {
			random_student(&s);
			push_front(a[i], &s);
		}
	}
	/////

	for (int i = 0; i < NLIST; ++i) {
		printf("%d. listede %d ogenci var\n", i + 1, get_size(a[i]));
		print_list(a[i]);
		_getch();
		system("cls");
	}
	/////

	for (int i = 0; i < NLIST; ++i) {
		close_list(a[i]);
	}
}
```


## Nested Structures

```c
struct Data {
	int x, y, z;
	//....
};

struct Neco {
	///
	struct Data mydata;
};
```

```c
struct Neco {
	
	struct Data {
		int x, y, z;
		//....
	}data;

	int a, b, c;
};

int main()
{
	struct Data dx;

}
```

```c
struct Neco {
	
	struct {
		int x, y, z;
		//....
	}d1, d2;

	int a, b, c;
};

int main()
{
	struct Neco necx;

	necx.d1.x = 10;

}
```

## Hizalama (Alignment)

```text
 padding bytes
 hole
```

```c
#include <stdio.h>

typedef struct {
	char c1;
	int ival;
	char c2;
}Data;

int main()
{
	printf("sizeof(Data) = %zu\n", sizeof(Data));
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	char c1;
	int ival;
	char c2;
}Data;

int main()
{
	Data mydata = { 12, 345712, 24 };

	printf("%p %p\n", &mydata, &mydata.c1);
	printf("%d\n", mydata.c1);
	printf("%d\n", mydata.ival);
	printf("%d\n", mydata.c2);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stddef.h>


typedef struct {
	char c1;
	int ival;
	char c2;
}Data;

int main()
{
	Data mydata = { 12, 345712, 24 };
	char *p = &mydata.c1;

	int *iptr = (int *)(p + 1); //yanlış giriş
	printf("*iptr = %d\n", *iptr);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stddef.h>


typedef struct {
	char c1;
	int ival;
	char c2;
}Data;

int main()
{
	printf("%zu\n", offsetof(Data, c1));
	printf("%zu\n", offsetof(Data, ival));
	printf("%zu\n", offsetof(Data, c2));
}
```


## offsetof Makrosu Kullanimi

```c
#define offsetoff(s, m)      ((size_t) &(((s *)0)->m))

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stddef.h>


struct Data{
	char c1;
	int ival;
	char c2;
};

int main()
{
	struct Data d1 = { 13, 98713, 45 };
	struct Data d2 = { 13, 98713, 45 };

	///
	if (d1.c1 == d2.c1 && d1.ival == d2.ival && d1.c2 == d2.c2) {
		printf("evet esit\n");
	}

	else {
		printf("hayir esit degil\n");
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stddef.h>
#include <string.h>


struct Data{
	char c1;
	int ival;
	char c2;
};

int main()
{
	struct Data d1 = { 13, 98713, 45 };
	struct Data d2 = { 13, 98713, 45 };

	///yanlis
	if (!memcmp(&d1, &d2, sizeof(d1))) {
		printf("evet esit\n");
	}

	else {
		printf("hayir esit degil\n");
	}
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stddef.h>
#include <string.h>


struct Data{
	char c1;
	int ival;
	char c2;
};

int main()
{
	struct Data d1;
	struct Data d2;

	memset(&d1, 0, sizeof(d1));
	memset(&d2, 0, sizeof(d2));

	d1 = (struct Data) { 12, 5698, 23 };
	d2 = (struct Data) { 12, 5698, 23 };

	
	if (!memcmp(&d1, &d2, sizeof(d1))) {
		printf("evet esit\n");
	}

	else {
		printf("hayir esit degil\n");
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#pragma   pack(1)
#include <stdio.h>
#include <stddef.h>
#include <string.h>

typedef struct Data{
	char c1;
	int ival;
	char c2;
}Data;

int main()
{
	printf("sizeof(Data) = %zu\n", sizeof(Data));
}
```

