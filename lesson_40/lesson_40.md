# Lesson 40

## Bitwise Manipulations 

```text
a) Bir tam sayının belirli bir bitini 1'lemek
    to set the bit
    to turn the bit on

b) Bir tam sayının belirli bir bitini 0'lamak
    to reset the bit
    to clear the bit
    to turn the bit off

c) Bir tam sayının belirli bir bitini değiştirmek
    to toggle the bit
    to flip the bit

d) Bir tam sayının belirli bir bitinin değerini öğrenmek
    to get the bit
```


```text
100?0101	x
00010000

1 << 4

10010101
```


# Bitmask (Bitsel Maske)

```text
x biti set edilecek tam sayı ve n set edilecek bitin indeksi olsun

x'in n. bitini set eden ifade

x | 1 << n

x | (1 << n)
x |= (1 << n)
```


```text
100100?0011   x
11111101111   bitmask

10010000011   x

x & ~(1 << n)
```

```c
#include "nutility.h"
#include <Windows.h>


int main()
{
	randomize();
	int x = 0;

	for (;;) {
		do {
			bprint(x);
			x |= 1 << (rand() % (sizeof(int) * 8));
			Sleep(15);
		} while (x != -1);
		Sleep(35);
		do {
			bprint(x);
			x &= ~(1 << (rand() % (sizeof(int) * 8)));
			Sleep(15);
		} while (x);
	}
	
}
```


```text
x | (1 << n)
x & ~(1 << n)

10101?0011
0000010000

x ^ (1 << n)
```

```c
#include "nutility.h"
#include <Windows.h>


int main()
{
	int x = 0;

	for (;;) {
		bprint(x);
		x ^= 1 << (rand() % 32);
		Sleep(35);
	}
}
```


```text
10001001
00001000

00001000

if (x & (1 << n))
   x'in n. biti 1 demek
else
   x'in n. biti 0 demek   


1001010100010101
1000000000000000
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

// 0111111111111111
// 1000000000000000

void bprint2(int val)
{
	unsigned mask = ~(~0u >> 1);

	while (mask) {
		putchar(val & mask ? '1' : '0');
		mask >>= 1;
	}
	putchar('\n');
}

int main()
{
	int ival;
	printf("bir tamsayi girin: ");
	scanf("%d", &ival);

	bprint(ival);
	bprint2(ival);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

// 0111111111111111
// 1000000000000000

void bprint2(int val)
{
	unsigned mask = ~(~0u >> 1);

	while (mask) {
		putchar(val & mask ? '1' : '0');
		mask >>= 1;
	}
	putchar('\n');
}

void bprint3(int val)
{
	for (int i = (int)(sizeof(int) * 8 - 1); i >= 0; --i)
		putchar((val >> i) & 1 ? '1' : '0');
	putchar('\n');
}

int main()
{
	int ival;
	printf("bir tamsayi girin: ");
	scanf("%d", &ival);

	bprint(ival);
	bprint2(ival);
	bprint3(ival);

}
```


# Hem üretimde gereken hem de programcılara mülakatlarda sorulan bazı bitsel işlemler

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

int main()
{
	int x;
	printf("bir tamsayi girin: ");
	scanf("%d", &x);

	//x = ~-x;
	x = -~x;

	printf("x = %d\n", x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

//100100100101001
//010010010000100
//1

int main()
{
	int x, y;
	printf("iki tamsayi girin: ");
	scanf("%d%d", &x, &y);

	if ((x ^ y) < 0) {
		printf("zit isaretliler\n");
	}
	else {
		printf("ayni isaretliler\n");
	}
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

//100100100101001
//010010010000100
//1

int main()
{
	int x;
	printf("bir tamsayi girin: ");
	scanf("%d", &x);

	if (x & 1) {
		//tek sayi
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include "nutility.h"


// 1010 1001 1010 0110
// 1001 1010 0110 0000
// 0000 0000 1001 1010 


// 1010 1001 1010 0110
// A    9    A    6         x

// 0000 0000 1001 1010      

int main()
{
	uint16_t x;
	///cop degerde degil

	x << 4 >> 8
}
```



```text
x && !(x & (x - 1))
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include "nutility.h"

// 1111 1010 1011 1100 0011 1101 1110 1010

//little endian
// FA
// BC
// 3D
// EA


typedef union {
	unsigned int uval;
	unsigned char s[4];
}Data;


int main()
{
	//unsigned int x = 0xFABC3DEA;

	Data dx = { .uval = 0xFABC3DEA };

	printf("%X\n", dx.s[0]);
	printf("%X\n", dx.s[1]);
	printf("%X\n", dx.s[2]);
	printf("%X\n", dx.s[3]);

}
```

```c
#define  econ32(x)  ((x >> 24 & 0xFF) | (x << 24) | (x >> 8 & 0x0000FF00) | (x << 8 & 0x00FF0000))


int main()
{
	unsigned int x = 0x58f792ac;

	printf("%X\n", x);
	printf("%X\n", econ32(x));

}
```

```text
AB CD
CD AB

(X << 8) | (X >> 8 & 0Xff)
```

```c
#define  econ32(x)  (((x) >> 24 & 0xFF) | ((x) << 24) | ((x) >> 8 & 0x0000FF00) | ((x) << 8 & 0x00FF0000))
#define  econ16(x)  ((x) << 8) | ((x) >> 8 & 0xFF)

int main()
{
	unsigned int x = 0x58f792ac;

	printf("%X\n", x);
	printf("%X\n", econ32(x));

}
```


# Bir tam sayının set edilmiş bitlerini saymak

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int sbc(int x)
{
	int cnt = 0;

	unsigned int mask = ~(~0u >> 1);
	while (mask) {
		if (x & mask)
			++cnt;
		mask >>= 1;
	}

	return cnt;
}

int main()
{
	int ival;
	printf("bir tamsayi girin: ");
	scanf("%d", &ival);
	bprint(ival);
	printf("%d sayisinin %d biti 1\n", ival, sbc(ival));

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"


int main()
{
	int ival;
	printf("bir tamsayi girin: ");
	scanf("%d", &ival);

	sbc(ival)
}
```

```text
00000010000
00000000010

00000010010

(1 << 4) | (1 << 1)
```




# Isaretsiz bir tamsayı değişkeni bir bit vectoru olarak kullanmak

```c
// 0000 0000 0000 0000

#include <ctype.h>
#include <stdio.h>

#define  UPPER		1
#define  LOWER		2
#define  DIGIT		4
#define  XDIGIT		8
#define  SPACE		16
#define  PUNCT		32
#define  PRINT		64
#define  CONTROL	128

int main()
{
	for (int i = 0; i < 128; ++i) {
		unsigned int x = 0;
		if (isupper(i))
			x |= UPPER;

		if (islower(i))
			x |= LOWER;

		if (isdigit(i))
			x |= DIGIT;

		if (isxdigit(i))
			x |= XDIGIT;

		if (isspace(i))
			x |= SPACE;

		if (ispunct(i))
			x |= PUNCT;

		if (isprint(i))
			x |= PRINT;

		if (iscntrl(i))
			x |= CONTROL;

		if (i && i % 8 == 0)
			printf("\n");

		printf("0X%2X, ", x);
	}
}
```

```c
#include "myctype.h"
#include <stdio.h>

int main()
{
	int c;

	printf("bir karakter girin:  ");
	c = getchar();

	if ((_myc[(c)] & (PUNCT)))
		printf("punctuation\n");
	else
		printf("punctuation degil\n");
}
```

```text
[0-31]
val

val << 5

0000000000000000
xxxxyyyzzzzzmmmkk
11111110000011111
xxxxyyy00000mmmkk
```


# Bitfield Members

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//typedef struct {
//	unsigned int x : 1;
//}Data;

//typedef struct {
//	unsigned int x : 7;
//	unsigned int y : 7;
//	unsigned int z : 7;
//	unsigned int t : 7;
//	unsigned int m : 4;
//}Data;

typedef struct {
	unsigned int x : 7;
	unsigned int y : 7;
	unsigned int z : 7;
	unsigned int t : 7;
	unsigned int m : 5;
}Data;

int main()
{
	printf("sizeof(Data) = %zu\n", sizeof(Data));
}
```




# Birliklerin bit alanları ile birlikte kullanılması

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//warning C4201 : nonstandard extension used : nameless struct / union

typedef union _Dtcon {
	unsigned int uval;
	struct {
		unsigned int mday : 5;
		unsigned int mon : 4;
		unsigned int year : 7;
		unsigned int hour : 5;
		unsigned int min : 6;
		unsigned int sec : 5;
	};
}Dtcon;

int main()
{
	Dtcon x = {
	.mday = 4,
	.mon = 4,
	.year = 2020 - 1980,
	.hour = 20,
	.min = 29,
	.sec = 58 / 2

	};

	printf("%u\n", x.uval);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//warning C4201 : nonstandard extension used : nameless struct / union

typedef union _Dtcon {
	unsigned int uval;
	struct {
		unsigned int mday : 5;
		unsigned int mon : 4;
		unsigned int year : 7;
		unsigned int hour : 5;
		unsigned int min : 6;
		unsigned int sec : 5;
	};
}Dtcon;

int main()
{
	Dtcon x = {
	.uval = 3954462852
	};

	printf("%02u-%02u-%u %02u:%0u:%02u\n",
		x.mday,
		x.mon,
		x.year + 1980,
		x.hour,
		x.min,
		x.sec * 2
		);

}
```


```c
#include <stdint.h>

typedef union {
    uint32_t uval;
    struct {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int bit5 : 1;
    unsigned int bit6 : 1;
    unsigned int bit7 : 1;
    unsigned int bit8 : 1;
    unsigned int bit9 : 1;
    unsigned int bit10 : 1;
    unsigned int bit11 : 1;
    unsigned int bit12 : 1;
    unsigned int bit13 : 1;
    unsigned int bit14 : 1;
    unsigned int bit15 : 1;
    unsigned int bit16 : 1;
    unsigned int bit17 : 1;
    unsigned int bit18 : 1;
    unsigned int bit19 : 1;
    unsigned int bit20 : 1;
    unsigned int bit21 : 1;
    unsigned int bit22 : 1;
    unsigned int bit23 : 1;
    unsigned int bit24 : 1;
    unsigned int bit25 : 1;
    unsigned int bit26 : 1;
    unsigned int bit27 : 1;
    unsigned int bit28 : 1;
    unsigned int bit29 : 1;
    unsigned int bit30 : 1;
    unsigned int bit31 : 1;
};
}Myint;
    
int main()
{
    //printf("sizeof(Myint) = %zu\n", sizeof(Myint));
    
    Myint x = { .uval = 765123912u };
    
    printf("%u\n", x.bit13);
}
```

```c
#include <stdint.h>

typedef union {
    uint32_t uval;
    struct {
        unsigned int bit0 : 1;
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
        unsigned int bit6 : 1;
        unsigned int bit7 : 1;
        unsigned int bit8 : 1;
        unsigned int bit9 : 1;
        unsigned int bit10 : 1;
        unsigned int bit11 : 1;
        unsigned int bit12 : 1;
        unsigned int bit13 : 1;
        unsigned int bit14 : 1;
        unsigned int bit15 : 1;
        unsigned int bit16 : 1;
        unsigned int bit17 : 1;
        unsigned int bit18 : 1;
        unsigned int bit19 : 1;
        unsigned int bit20 : 1;
        unsigned int bit21 : 1;
        unsigned int bit22 : 1;
        unsigned int bit23 : 1;
        unsigned int bit24 : 1;
        unsigned int bit25 : 1;
        unsigned int bit26 : 1;
        unsigned int bit27 : 1;
        unsigned int bit28 : 1;
        unsigned int bit29 : 1;
        unsigned int bit30 : 1;
        unsigned int bit31 : 1;
    };
}Myint;

int main()
{
    Myint x = { .uval = 0 };
    
    x.bit5 = 1;
    x.bit10 = 1;
    x.bit15 = 1;
    x.bit23 = 1;
    
    printf("%u\n", x.uval);
}
```

```c
#include <stdint.h>
#include "nutility.h"
#include <stdio.h>

typedef union {
    uint32_t uval;
    struct {
        unsigned int bit0 : 1;
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
        unsigned int bit6 : 1;
        unsigned int bit7 : 1;
        unsigned int bit8 : 1;
        unsigned int bit9 : 1;
        unsigned int bit10 : 1;
        unsigned int bit11 : 1;
        unsigned int bit12 : 1;
        unsigned int bit13 : 1;
        unsigned int bit14 : 1;
        unsigned int bit15 : 1;
        unsigned int bit16 : 1;
        unsigned int bit17 : 1;
        unsigned int bit18 : 1;
        unsigned int bit19 : 1;
        unsigned int bit20 : 1;
        unsigned int bit21 : 1;
        unsigned int bit22 : 1;
        unsigned int bit23 : 1;
        unsigned int bit24 : 1;
        unsigned int bit25 : 1;
        unsigned int bit26 : 1;
        unsigned int bit27 : 1;
        unsigned int bit28 : 1;
        unsigned int bit29 : 1;
        unsigned int bit30 : 1;
        unsigned int bit31 : 1;
    };
}Myint;

int main()
{
    Myint x = { .uval = 0 };
    
    x.bit5 = 1;
    x.bit10 = 1;
    x.bit15 = 1;
    x.bit23 = 1;
    
    printf("%u\n", x.uval);
    bprint(x.uval);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// isimsiz bir bitfield elemani tanimlamak. 
struct Data {
    unsigned int x : 5;
    unsigned int   : 3;
    unsigned int y : 4;
    //..	
};
```
