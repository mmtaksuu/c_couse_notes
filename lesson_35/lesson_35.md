# Lesson 35

## Realloc Impl.
```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "nutility.h"


int main()
{
	int *pd = NULL;
	int cnt = 0;
	int c, ival;

	randomize();

	for (;;) {
		printf("tamsayi girecek misiniz? (e) (h): ");
		while ((c = _getch()) != 'e' && c != 'h')
			;
		printf("\n%c\n", c);
		if (c == 'h')
			break;
		printf("tamsayiyi girin: ");
		ival = rand() % 1000;
		printf("%d\n", ival);

		pd = (int *)realloc(pd, (cnt + 1) * sizeof(int));
		if (!pd) {
			printf("bellek yetersiz\n");
			return 1;
		}
		pd[cnt++] = ival;
	}

	if (cnt == 0) {
		printf("hic giris yapmadiniz\n");
	}
	else {
		printf("toplam %d sayi girdiniz\n", cnt);
		sort(pd, cnt);
		display_array(pd, cnt);
		free(pd);
	}
}
```



# Dynamic Array Implementation Examples in C++ Through Vector Library

```c++
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	size_t cap = 0;
	
	vector<int> ivec;

	for (;;) {
		ivec.push_back(1);
		if (ivec.capacity() > cap)
		{
			cout << "size = " << ivec.size() << "  capacity = " << ivec.capacity() << "\n";
			cap = ivec.capacity();
			_getch();
		}
	}
}
```


```c++
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	size_t cap = 0;
	
	vector<int> ivec;
	ivec.reserve(500000);

	for (;;) {
		ivec.push_back(1);
		if (ivec.capacity() > cap)
		{
			cout << "size = " << ivec.size() << "  capacity = " << ivec.capacity() << "\n";
			cap = ivec.capacity();
			_getch();
		}
	}
}
```




# Storage Class Specifiers (yer belirleyici)

```text
auto =========> kullanımdan düştü
register  =========> kullanımdan düştü
extern
static
```

# Type Modifiers (tür niteleyici)

```text
const
volatile
restrict (C99)
```


# Auto specifier in C

```c
#include <stdio.h>


//auto g = 45; //gecersiz

//warning C4042: 'x': has bad storage class
void func(auto int x)
{

}

int main()
{

}
```


# C++ Type Deduction (tür çıkarımı)

```c++
int foo();

int main()
{
	auto x = foo();
}
```


```c++
int main()
{
	auto x = 4;  //auto int x = 4;
	
	const y = 34;  //const int y = 34;
}
```

# Register specifier

```c
int main()
{
	//derleyici, mumkunse ve senin icin de uygunsa
	//x'i bellekte degil de işlemcinin yazmacında tutacak şekilde bir kod üret

	register int x = 10; 
}
```

```text
C' ve C++  dillerinde register anahtar sözcüğü ile tanımlanmış bir değişken
adres operatörünün operandı olamaz
```

```c
int main()
{
	register int x = 10; 
	int *p = &x;        //Error	C2103	'&' on register variable

}
```

```text
Global namespace de register keyword ile tanimlama yapilamaz.
```
```c
register int g = 30;  //Gecersiz

int main()
{
    return 0;
}
```


```text
Register keyword ile yapilan tanimlamalar fonksiyon parametresi olarak gonderilebilir.
```
```c
void func(register int x, register int y)
{
	//...
}

int main()
{
	register int x = 10; 
	register int y = 20; 
	
	func(x, y);
	
	return 0;
}
```

# Static Specifier

```c
#include <stdio.h>

void func()
{
	int x = 10;
	static int y = 10;

	printf("x = %d   y = %d\n", x, y);
	x += 5;
	y += 5;
}


int main()
{
	for (int i = 0; i < 10; ++i) {
		func();
	}

}
```


```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>

void func()
{
	static int a[] = { 1, 2, 3, 4, 5 };
	display_array(a, 5);

	for (int i = 0; i < 5; ++i) {
		++a[i];
	}
}


int main()
{
	for (int i = 0; i < 10; ++i) {
		func();
		_getch();
	}
}
```


# Neden Statik Omurlu Yerel Degiskenleri Kullanıyoruz ?

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <string.h>
#include <time.h>


char* get_logfile_name()
{
	static char fname[40];
	time_t timer;
	time(&timer);
	struct tm *p = localtime(&timer);
	sprintf(fname, "%04d_%02d_%02d_%02d_%02d_%02d.log", p->tm_year + 1900,
		p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);

	return fname;
}


int main()
{
	FILE *f = fopen(get_logfile_name(), "w");
	///

	fclose(f);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <string.h>
#include <time.h>


char* get_logfile_name()
{
	static char fname[40];
	time_t timer;
	time(&timer);
	struct tm *p = localtime(&timer);
	sprintf(fname, "%04d_%02d_%02d_%02d_%02d_%02d.log", p->tm_year + 1900,
		p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);

	return fname;
}


int main()
{
	char *p[10];

	for (int i = 0; i < 10; ++i) {
		p[i] = get_logfile_name();
		printf("bir tusa basin\n");
		_getch();
	}

	for (int i = 0; i < 10; ++i) {
		puts(p[i]);
	}
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


char* get_logfile_name()
{
	static char fname[40];
	time_t timer;
	time(&timer);
	struct tm *p = localtime(&timer);
	sprintf(fname, "%04d_%02d_%02d_%02d_%02d_%02d.log", p->tm_year + 1900,
		p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);

	char *pd = (char *)malloc(strlen(fname) + 1);
	if (!pd) {
		printf("bellek yetersiz\n ");;
		exit(EXIT_FAILURE);
	}

	return strcpy(pd, fname);
}


int main()
{
	char *p[10];

	for (int i = 0; i < 10; ++i) {
		p[i] = get_logfile_name();
		printf("bir tusa basin\n");
		_getch();
	}

	for (int i = 0; i < 10; ++i) {
		puts(p[i]);
		free(p[i]);
	}

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>
#include <stdlib.h>

#define URAND_MAX    100

int urand(void)
{
	static int a[URAND_MAX] = { 0 };
	static int cnt = 0;

	if (cnt == URAND_MAX)
		return -1;

	int ival;

	while (a[ival = rand() % URAND_MAX])
		;

	a[ival] = 1;
	++cnt;
	return ival;
}


int main()
{
	randomize();

	for (int i = 0; i < URAND_MAX; ++i) {
		printf("%d ", urand());
	}
	printf("\n");
	printf("\n");

	printf("%d ", urand());
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>
#include <stdlib.h>


void func(void)
{
	static int cnt = 0;
	printf("func islevine yapilan %d. cagri\n", ++cnt);
}


int main()
{
	for (int i = 0; i < 100; ++i) {
		func();
	}

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void func(void)
{
	static bool first_call_flag = true;

	if (first_call_flag) {
		printf("ilk cagrida yapilmasi gereken islemler  yapildi\n");
		first_call_flag = false;
	}
	printf("her cagrida yapilmasi gereken islemler  yapildi\n");
}


int main()
{
	for (int i = 0; i < 10; ++i) {
		func();
	}
}
```

# strtok fonksiyonu

```text
char* strtok(char *p, const char *pdelim);

C'nin önemli string fonksiyonlarından biri olan strtok fonksiyonunun incelenmesi

ahmet\0mehmet\0hasan\0,  ayse
                         |
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define			SIZE		100

int main()
{
	char str[SIZE];
	int cnt = 0;

	printf("bir yazi girin: ");
	sgets(str);

	char *p = strtok(str, " \t.;?:,");
	while (p) {
		printf("[%02d] %s\n", ++cnt, p);
		p = strtok(NULL, " \t.;?:,");
	}

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define			SIZE		100

int main()
{
	char str[SIZE];
	int cnt = 0;

	printf("bir yazi girin: ");
	sgets(str);

	char *p = strtok(str, "0123456789");
	while (p) {
		printf("[%02d] %s\n", ++cnt, p);
		p = strtok(NULL, "0123456789");
	}

}
```

# Look-up Tablolarinin Static Olarak Tanitilmasi

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define			SIZE		100

int get_nth_prime(int n)
{
	static int const primes[] = {
		0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
		31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
		73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
		127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
		179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
		233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
		283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
		353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
		419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
		467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
	};

	if (n < 1 && n > 100)
		return -1;

	return primes[n];
}



int main()
{
	int n;
	printf("bir tamsayi girin: ");
	scanf("%d", &n);

	printf("%d. asal sayi %d\n", n, get_nth_prime(n));
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define			SIZE		100


void  date_xyz(int d, int m, int y)
{
	static const int daytabs[][13] = {
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
		{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	};

	daytabs[isleap(y)][m]

}
```

# Dikkat

```text
Adres döndüren fonksiyonlarda şu bilgileri mutlaka edinin:

a) Fonksiyon nasıl bir nesnenin adresini döndürüyor
   i) Benden aldığını bana geri  veriyor
   ii) statik ömürlü bir nesne adresi döndürüyor
   iii) dinamik ömürlü bir nesne adresi döndürüyor

b) NULL pointer döndürme ihtimali var mı?


Adres isteyen fonksiyonlarda şu bilgiyi mutlaka edinin

a) NULL pointer gönderme opsiyonum var mı?
b) NULL pointer göndermek tanımsız davranış
```

# Modül ve Baglanti Kavrami (linkage)

```text
1) External linkage : Bir isim briden fazla kaynak dosyada kullanıldığında (runtime'da) aynı varlığa ilişkin ise

2) Internal linkage : Bir isim ancak tek bir kaynak dosyada aynı varlığa ilişkin ise

3) No linkage : yerel kullanimda olanlar

mutable variables   (Degeri degisebilen degiskenler)
immutable variables (Salt okuma amacli degiskenler)
```


```c
int main()
{
	int x = 10;

	const int *p = &x;          // low level const  | pointer to const int
	int *const  p = &x;         // top level const  | const pointer to int
	const int *const  p = &x;  // top level const   | const pointer to const int
}
```


```c
int *foo(void);

const int *func(void);

int main()
{
	*foo()  = 45;
	*func() = 45;  // gecersiz
}
```

```c
int main()
{
	const int x = 10;
	int a[x] = { 0 }; //C'de illegal, C++'da gecerli
}
```



