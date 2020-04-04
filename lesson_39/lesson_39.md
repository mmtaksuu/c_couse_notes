# Lesson 38

```text
Konu Basliklari

    unions (birlikler)
    enumarations (numaralandırmalar)
    bitwise operations
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#pragma pack(1)

typedef struct {
	int mx, my, mz;
	double d1, d2;
	char s[12];
}STRUCT;

typedef union{
	int mx, my, mz;
	double d1, d2;
	char s[12];

}UNION;

int main()
{
	printf("sizeof(STRUCT) = %zu\n", sizeof(STRUCT));
	printf("sizeof(UNION)  = %zu\n", sizeof(UNION));
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#pragma pack(1)

struct Data {
	int x, y;
	double d;
	char str[12];
};

int main()
{
	struct Data sdx = { 10, 20, 2.3, "cenk" };
}
```

```text
Not: Birlik nesnelerine ilk değer vermede yalnızca tek bir init. expression olabilir
```
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#pragma pack(1)

union Data {
	int x, y;
	double d;
	char str[12];
};


int main()
{
	union Data sdx = { 10};             // VEYA
	union Data udx = { .d = 34.87 };    // VEYA
	union Data udy = { .str = "murat"};  // VEYA

}
```

```c
#include <stddef.h>
#include "date.h"

union Data {
	Date dx;
	int a[3];
};

int main()
{
	union Data mydata = { .dx = {5, 12, 1987} };
	printf("sizeof(union Data) = %zu\n", sizeof(union Data));
}
```


```c
#include <stdio.h>
#include "date.h"
#include <stdint.h>

typedef union {
	struct {
		uint16_t low_bytes;
		uint16_t high_bytes;
	};
	uint32_t uval;
}Myint;


int main()
{
	Myint mx = { .uval = 875424u };

	printf("%u\n", mx.low_bytes);
	printf("%u\n", mx.high_bytes);
}
```


discriminated union
variant


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


typedef struct {
	int status;
	char place[20];
}MilData;

typedef struct {
	int id;
	char name[24];
	int gender;
	union {
		char maiden_name[20];
		MilData mdata;
	};
}Person;


int main()
{
	printf("sizeof(Person) = %zu\n", sizeof(Person));
}
```


```text
öyle bir tür olsun ki
bir tamsayi ---> int
bir gerçek sayi ---> double
bir karakter ---> char
bir tarih ---> Date
tutabilsin
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "date.h"


typedef union {
	int ival;
	double dval;
	char c;
	Date date;
}Data;

int main()
{
	Data dx = { .ival = 45 };

	//
	dx.dval = 2.3;

	////

	dx

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nutility.h"
#include "date.h"
#include <conio.h>


//öyle bir tür olsun ki
//bir tamsayi ---> int
//bir gerçek sayi ---> double
//bir karakter ---> char
//bir tarih ---> Date
//tutabilsin

#define  INT		0
#define  DOUBLE		1
#define  CHAR		2
#define  DATE		3

typedef struct {
	union {
		int ival;
		double dval;
		char c;
		Date date;
	};
	int type;
}Data;


void set_random_data(Data *p)
{
	switch (rand() % 4) {
	case CHAR   : p->type = CHAR; p->c = rand() % 26 + 'A'; break;
	case INT: p->type = INT; p->ival = rand(); break;
	case DOUBLE: p->type = DOUBLE; p->dval = drand(); break;
	case DATE: p->type = DATE; random_date(&p->date); break;
	}
}

void print_data(const Data *p)
{
	switch (p->type) {
	case CHAR: printf("(%c)\n", p->c); break;
	case INT:printf("(%d)\n", p->ival); break;
	case DOUBLE: printf("(%f)\n", p->dval); break;
	case DATE: print_date(&p->date); break;
	}
}


int main()
{
	randomize();
	Data dx;

	for (;;) {
		set_random_data(&dx);
		print_data(&dx);
		_getch();
		system("cls");
	}

}
```



# Enumarations (Numaralandırma)

```text
enumartor 
enumaration constants
```

```c
enum Color {
	White, Blue, Green, Yellow, Red, Black
};

int main()
{
	printf("White  = %d\n", White);
	printf("Blue   = %d\n", Blue);
	printf("Green  = %d\n", Green);
	printf("Yellow = %d\n", Yellow);
	printf("Red    = %d\n", Red);
	printf("Black  = %d\n", Black);
}
```

```text
underlying type of the enum in C is int.
```

```c
typedef enum Color {
	White, Blue, Green, Yellow, Red, Black, 
}Color;


typedef enum Pos{
	On, Off, Hold, Standby
}Pos;

int main()
{
	Color mycolor = Red;
	mycolor = 45;
	mycolor = Standby;
}
```


```c
#include <stdio.h>

enum Color {White, Blue, Green, Yellow, Red, Black };
const char *const p[] = { "White", "Blue", "Green", "Yellow", "Red", "Black" };

double vals[] = { [Green] = 2.3,[Red] = 4.5, [White] = 3.4 };

int main()
{
	printf("%s\n", p[Red]);
}
```


```c
#include <stdio.h>

void func()
{
	enum {SIZE = 500};
	int a[SIZE] = { 0 };
}

int main()
{
	int a = SIZE; //,invalid - out of scope
}
```

```c
#include <stdio.h>

typedef enum { White, Blue, Green, Yellow, Red, Black, NoOfColors }Color;

int main()
{
	for (Color c = 0; c < NoOfColors; ++c) {
		//c
	}

}
```

```text
C'de enum türleri ile ilgili genel sorunlar
```

```c
#include <stdio.h>

typedef enum { White, Blue, Green, Yellow, Red, Black, NoOfColors }Color;

int main()
{
	Color c = Yellow;
	int ival = c;
	c = 132;
}
```


# Bitwise Operations (Bitsel Islemler)

```text
bitwise operators
bitwise operations (bitwise maipulation)
genel kullanım alanları - örnekler
bitfield members
```

```text
Operator Oncelik Tablosu

---------------------------------------------------------------------
1  () [] . ->
---------------------------------------------------------------------
2   +  -  ! sizeof  (double)  &  * ++ --   ~           sağdan sola
---------------------------------------------------------------------
3   * / %
---------------------------------------------------------------------
4   + -
---------------------------------------------------------------------
5   >>  <<
---------------------------------------------------------------------
6   < <= > >=
---------------------------------------------------------------------
7   == !=
---------------------------------------------------------------------
8   &
---------------------------------------------------------------------
9   ^
---------------------------------------------------------------------
10  |
---------------------------------------------------------------------
11  &&
---------------------------------------------------------------------
12  ||
---------------------------------------------------------------------
13  ? :													 sağdan sola
---------------------------------------------------------------------
14  = += -= *= /= %= &= ^= |= >>=  <<=                   sağdan sola
---------------------------------------------------------------------
15  ,
---------------------------------------------------------------------
```


```text
Bitwise Operatorlerin Onceliklerinin Inclenmesi

---------------------------------------------------------------------
2   ~									sağdan sola
---------------------------------------------------------------------
5   >>  <<
---------------------------------------------------------------------
8   &
---------------------------------------------------------------------
9   ^
---------------------------------------------------------------------
10  |
---------------------------------------------------------------------
14  &=  ^= |= >>=  <<=                   sağdan sola
---------------------------------------------------------------------
```

```text
x & y

10101001010010001
10101001010010001

0101 1001
```

# BITWISE NOT (Bitsel Degil Operatoru)

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>


int main()
{
	int ival;
	printf("bir tamsayi girin: ");
	scanf("%d", &ival);

	bprint(ival);
	bprint(~ival);
	bprint(~~ival);
	printf("ival = %d\n", ival);
	//
	ival = ~ival;

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>


int main()
{
	unsigned int uval = ~0u;

	printf("uval = %u\n", uval);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>

int main()
{
	int x = 0b1001'0101;
	printf("x = %d\n", x);
}
```


# Bitwise Shift Operators (Bitsel Kaydırma Operatorleri)

```text
    >>   bitsel sağa kaydırma (bitwise right shift)
    <<   bitsel sola kaydırma (bitwise left shift)

Bitsel kaydırma operatörlerinin sağ operandı olan ifadenin değeri
a) 0'dan küçükse tanımsız davranıştır.
b) tamsayi türünün bit sayısına eşit ya da bu değerden daha büyükse tanımsız davranıştır.

a << b
x >> 24

----------------
1001001010011010
1001010011010000
----------------

```

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>


int main()
{
	int ival;
	printf("bir tamsayi girin: ");
	scanf("%d", &ival);

	bprint(ival);
	bprint(ival << 1);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>

int main()
{
	int ival;
	printf("bir tamsayi girin: ");
	scanf("%d", &ival);

	bprint(ival);
	bprint(ival << 1);
	printf("%d\n", ival << 1);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>


// 00000001
// 00000010
// 00000100
// 10000000
// 00000000

int main()
{
	int ival = 1;

	while (ival) {
		bprint(ival);
		//ival = ival << 1;
		ival <<= 1;
	}

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>
#include <Windows.h>


// 00000001
// 00000010
// 00000100
// 10000000
// 00000000

int main()
{
	int ival = 1;

	while (ival) {
		bprint(ival);
		//ival = ival << 1;
		ival <<= 1;
		Sleep(100);
	}
}

```

```text
Dikkat!!!!

bitsel sağa kaydırma işleminde
eğer sol operand işaretsiz tamsayı türlerinden ise besleme 0 ile yapılır
eğer sol operand işaretli türden pozitif bir sayi ise besleme 0 ile yapılır

eğer sol operand işaretli türden negatif bir sayi ise beslenin 0 ya da 1 olacağı  implementation defined

1001100110011001
1100110011001100

sign extension
```

```text
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>
#include <Windows.h>


// 00000001
// 00000010
// 00000100
// 10000000
// 00000000

int main()
{
	int x = -1;

	bprint(x);
	bprint(x >> 1);
}
```

```text
//   00000000000000000000
//   11111111111111111111
//   01111111111111111111
//   10000000000000000000

	~(~0u >> 1)
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>
#include <Windows.h>

#define			STIME     50

void shift_right()
{
	unsigned int uval = ~(~0u >> 1);

	while (uval) {
		bprint(uval);
		Sleep(STIME);
		uval >>= 1;
	}
	bprint(0);
	Sleep(STIME);
}

void shift_left()
{
	unsigned int uval = 1;

	while (uval) {
		bprint(uval);
		Sleep(STIME);
		uval <<= 1;
	}
	bprint(0);
	Sleep(STIME);
}

int main()
{
	while (1) {
		shift_left();
		shift_right();
	}
}
```

```c

// 100000000000000000000000

int main()
{
	bprint(~(~0u >> 1));
	printf("%d\n", ~(~0u >> 1));
}
```

```text
bitsel ve

10010010101110010011011
10101111100001010010100

10000010100000010010000


bitsel veya

10010010101110010011011
10101111100001010010100
10111111101111010011111


bitsel özel veya

10010010101110010011011
10101111100001010010100
00111101001111000001111
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>
#include <Windows.h>

#define			STIME     50

void shift_right()
{
	unsigned int uval = ~(~0u >> 1);

	while (uval) {
		bprint(uval);
		Sleep(STIME);
		uval >>= 1;
	}
	bprint(0);
	Sleep(STIME);
}

void shift_left()
{
	unsigned int uval = 1;

	while (uval) {
		bprint(uval);
		Sleep(STIME);
		uval <<= 1;
	}
	bprint(0);
	Sleep(STIME);
}

int main()
{
	while (1) {
		shift_left();
		shift_right();
	}
}
```


```c

// Bitwise And
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>


int main()
{
	int x, y;
	printf("iki tamsayi girin: ");
	scanf("%d%d", &x, &y);

	bprint(x);
	bprint(y);
	bprint(x & y);

}
```

```c
// Bitwise Or
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>


int main()
{
	int x, y;
	printf("iki tamsayi girin: ");
	scanf("%d%d", &x, &y);

	bprint(x);
	bprint(y);
	bprint(x | y);

}
```

```c

// Bitwise And
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>

int main()
{
	int x, y;
	printf("iki tamsayi girin: ");
	scanf("%d%d", &x, &y); //10 20

	if (x && y)
		printf("dogru\n");
	else
		printf("yanlis\n");

	if (x & y)
		printf("dogru\n");
	else
		printf("yanlis\n");

	bprint(x);
	bprint(y);
	bprint(x & y);
	
}
```


```c
// Bitwise Xor
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>

int main()
{
	int x, y;
	printf("iki tamsayi girin: ");
	scanf("%d%d", &x, &y); 

	x ^= y;
	printf("x = %d\n", x);

	x ^= y;

	printf("x = %d\n", x);

}
```
