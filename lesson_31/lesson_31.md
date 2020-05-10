# LESSON 31

## Generic Functions and Generic Pointers

```text
<string.h> header file icerisinde 5 adet turden bagimsiz generic fonksiyon bulunmaktadir.
Bu fonksiyonlar string.h dosyasi icinde tanimlanmis olsa dahi sadece yazilar icin degil tum
turler ile islem yapmak icin kullanilabilir. Bu fonksiyonlar asagida verilmistir.
```

```c
void *memset(void *vp, int val, size_t n);
void *memcpy(void  *restrict vpdest, const void *restrict vpsource, size_t n);
void *memmove(void *vpdest, const void *vpsource, size_t n);
void *memchr(const void *vp, int val, size_t n);
int   memcmp(const void *vp1, const void *vp2, size_t n);
```



```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

int main()
{
    int x = 12976;
    memset(&x, 0, sizeof x);
    
    printf("x = %d\n", x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
    int a[SIZE];
    
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    
    memset(a, 0, sizeof(a));
    
    display_array(a, SIZE);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
    int a[SIZE];
    
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    int idx, n;
    printf("indeks ve adet giriniz: ");
    scanf("%d%d", &idx, &n);
    
    memset(a + idx, 0, n * sizeof(int));
    display_array(a, SIZE);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
    char str[100] = "bugun cok yagmur yagdi";
    //3  10
    memset(str + 3, 'X', 7);
    
    puts(str);

}
```




```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"


int main()
{
    int x;
    
    memset(&x, 255, sizeof x);
    printf("x = %d\n", x);
    memset(&x, 1, sizeof x);
    printf("x = %d\n", x);

}
```

```text
int x;
memset(&x, 255, sizeof x);

1111 1111 1111 1111 1111 1111 1111 1111

int x;
memset(&x, 1, sizeof x);

00000001 00000001 00000001 00000001
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100


void* memset1(void *vp, int val, size_t n)
{
    //unsigned char *p = vp;
    unsigned char *p = (unsigned char*)vp;
    while (n--)
        *p++ = (unsigned char)val;
    
    return vp;
}

int main()
{

    int x;
    
    memset(&x, 255, sizeof x);
    printf("x = %d\n", x);
    memset(&x, 1, sizeof x);
    printf("x = %d\n", x);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
    int a[SIZE];
    int b[SIZE];
    
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    memcpy(b, a, sizeof(a));
    display_array(b, SIZE);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
    int a[SIZE];
    int b[SIZE] = { 0 };
    
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    
    size_t idx_a, idx_b, n;
    
    printf("a'da indeks b'de indeks ve oge sayisi : ");
    scanf("%zu%zu%zu", &idx_a, &idx_b, &n);
    memcpy(b + idx_b, a + idx_a, n * sizeof(int));
    
    display_array(b, SIZE);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
    int a[SIZE];
    
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    
    memcpy(a + 20, a, 60 * sizeof(int)); //ub

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

void* memcpy1(void *vpdest, const void *vpsource, size_t n)
{
    char *pdest = vpdest;
    const char *psource = vpsource;
    
    while (n--)
        *pdest++ = *psource++;
    
    return vpdest;
}

int main()
{
    int a[SIZE];
    
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    
    memcpy(a + 20, a, 60 * sizeof(int)); //ub

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
    char s1[SIZE];
    char s2[SIZE];
    
    printf("yazi girin: ");
    sgets(s1);
    
    memcpy(s2, s1, strlen(s1) + 1);
    
    printf("(%s)\n", s1);
    printf("(%s)\n", s2);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void *memmove_(void *vpdest, const void *vpsource, size_t n)
{
    char *pdest = (char *)vpdest;
    const char *psource = (const char *)vpsource;
    
    if (pdest < psource) {
        while (n--)
            *pdest++ = *psource++;
    }
    else {
        pdest += n;
        psource += n;
        while (n--)
            *--pdest = *--psource;
    }
    
    return vpdest;
}


int main()
{
    char str[100] = "gulden";
    
    //strcpy(str + 3, str);
    memmove(str + 3, str, strlen(str) + 1);
    
    puts(str);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define   SIZE      100


char *str_prepend(char *pdest, const char *psource)
{
	size_t source_len = strlen(psource);
	size_t dest_len = strlen(pdest);

	memmove(pdest + source_len, pdest, dest_len + 1);
	memmove(pdest, psource, source_len);

	return pdest;
}

int main()
{
	char s1[SIZE];
	char s2[SIZE];

	printf("iki isim girin: ");
	scanf("%s%s", s1, s2); //dogancan  ahmet
	str_prepend(s1, s2);
	printf("(%s)\n", s1); //(ahmetdogancan)

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

void * memchr1(const void *vp, int val, size_t n)
{
	const unsigned char *p = vp;

	while (n--) {
		if ((unsigned char)val == *p)
			return (unsigned char *)p;
		++p;
	}
	return NULL;
}

typedef unsigned char Byte;

int main()
{
	Byte a[SIZE] = { 0 };

	randomize();

	for (int i = 0; i < 500; ++i)
		a[rand() % SIZE] = 1;

	for (int i = 0; i < SIZE; ++i) {
		printf("%u", a[i]);
	}
	printf("\n");

	Byte *p = memchr(a, 0, sizeof(a));
	if (!p) {
		printf("hic 0 yok\n");
	}
	else {
		printf("dizinin %d indisli ogesi\n", p - a);
	}
	
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	int x = 10, y = -1;

	int cmp_result = memcmp(&x, &y, sizeof(int));

	if (cmp_result > 0)
		printf("birinci buyuk\n");
	else if (cmp_result < 0)
		printf("ikinci buyuk\n");
	else
		printf("esit\n");

}
```


```text
memcmp() fonksiyonu verilen iki adresin icerik olarak buyuklugunu karsilastirmaz.
Byte buyukluklerini karsilastirir. Asagidaki yapi icin Sag taraf daha buyuktur.

00011000  00011000
00010001  00010001
01001010  11000111
01001010  11000111
```



```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

int memcmp1(const void *vp1, const void* vp2, size_t n)
{
	const unsigned char *p1 = vp1;
	const unsigned char *p2 = vp2;
	
	while (n--) {
		if (*p1 != *p2)
			return *p1 > *p2 ? 1 : -1;
		++p1;
		++p2;
	}

	return 0;
}

int main()
{
	int x = 10, y = -1;

	int cmp_result = memcmp(&x, &y, sizeof(int));

	if (cmp_result > 0)
		printf("birinci buyuk\n");
	else if (cmp_result < 0)
		printf("ikinci buyuk\n");
	else
		printf("esit\n");

}
```


# Generic Fonksiyonlarin Tasarimi ve Implementasyonu


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      20

void* greverse(void *vpa, size_t size, size_t width)
{
	char *p = (char *)vpa;

	for (size_t i = 0; i < size / 2; ++i) {
		gswap(p + i * width, p + (size - 1 - i) * width, width);
	}

	return vpa;
}

int main()
{
	int a[SIZE];
	randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);
	greverse(a, SIZE, sizeof(int));
	display_array(a, SIZE);

	double b[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	greverse(b, asize(b), sizeof(*b));

	for (size_t i = 0; i < asize(b); ++i) {
		printf("%f\n", b[i]);
	}

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      20


void* greverse(void *vpa, size_t size, size_t width)
{
	char *p = (char *)vpa; 
	char *plast = p + (size - 1) * width;

	while (p < plast) {
		gswap(p, plast, width);
		p += width;
		plast -= width;
	}

}

void* greverse(void *vpa, size_t size, size_t width)
{
	char *p = (char *)vpa;

	for (size_t i = 0; i < size / 2; ++i) {
		gswap(p + i * width, p + (size - 1 - i) * width, width);
	}

	return vpa;
}

int main()
{
	int a[SIZE];
	randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);
	greverse(a, SIZE, sizeof(int));
	display_array(a, SIZE);

	double b[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	greverse(b, asize(b), sizeof(*b));

	for (size_t i = 0; i < asize(b); ++i) {
		printf("%f\n", b[i]);
	}
}
```



```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      20


void* greverse(void *vpa, size_t size, size_t width)
{
	char *p = (char *)vpa; 
	char *plast = p + (size - 1) * width;

	while (p < plast) {
		gswap(p, plast, width);
		p += width;
		plast -= width;
	}

}

void* greverse(void *vpa, size_t size, size_t width)
{
	char *p = (char *)vpa;

	for (size_t i = 0; i < size / 2; ++i) {
		gswap(p + i * width, p + (size - 1 - i) * width, width);
	}

	return vpa;
}

int main()
{
	int a[SIZE];
	randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);
	greverse(a, SIZE, sizeof(int));
	display_array(a, SIZE);

	double b[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	greverse(b, asize(b), sizeof(*b));

	for (size_t i = 0; i < asize(b); ++i) {
		printf("%f\n", b[i]);
	}
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

void *gsearch(const void *vpa, size_t size, size_t width, const void *vpkey)
{
	const char *p = vpa;

	while (size--) {
		if (!memcmp(p, vpkey, width))
			return (char *)p;
		p += width;
	}

	return NULL;
}

void *gsearch(const void *vpa, size_t size, size_t width, const void *vpkey)
{
	const char *p = vpa;

	for (size_t i = 0; i < size; ++i) {
		if (!memcmp(p + i * width, vpkey, width))
			return (char *)(p + i * width);
	}

	return NULL;
}

int main()
{
	int a[SIZE];
	randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);
	int sval;
	printf("aranacak deger: ");
	scanf("%d", &sval);

	int *p = gsearch(a, SIZE, sizeof(*a), &sval);
	if (p) {
		printf("bulundu... dizinin %d indisli ogesi %d\n", p - a, *p);
	}
	else {
		printf("bulunamadi\n");
	}

}
```

# (void *) & (void **) Pointers

```text
    void *vp;                       void **p;
    ____________                    ____________
    - Generictir.                   - Generic degildir.
    - Dereference edilemez.         - Dereference edilebilir.
    - Her turden nesnenin           - Yalnizca void * turden pointerlarin
      adresini tutabilir.             adresini tutabilir.
```


```c
int main()
{
	int x = 21;
	double dval = 5.9;
	void *vp = &x;
	void ** vptr = &vp;
	*vptr = &dval;

	**vptr = 2.3; //gecersiz

}
```


```c
void func(int x, void **vptr);

int main()
{
	int x = 21;
	double dval = 5.9;
	void *vp = &x;

	func(12, &vp);

}
```

```c
void *func(void);

int main()
{
	void *a[10];

	for (int i = 0; i < 10; ++i) {
		a[i] = func();
	}

}
```


# Function Pointers (Fonksiyon Gostericileri)


```text
int func(int);
func işlevinin adresinin türü
int(*)(int)


standart sqrt işlevinin adresinin türünü yazınız
double (*)(double)

strcmp işlevinin adresinin türü
int (*)(const char *, const char *)

strcpy işlevinin adresinin türü
char *(*)(char *, const char *)


Peki, bir fonksiyon adresi nasıl elde edilir

C ve C++ dillerinde
bir fonksiyonun ismi bir ifade içinde kullanıldığında
derleyici fonksiyon ismini ilgili fonksiyonun adresine dönüştürür
Function to Pointer Conversion

Bu durumda genel olarak asagidaki iki kullanim ayni anlamdadir.
    func
    &func

(&func)()
```


```c
#include <stdio.h>

void func(void)
{
	printf("func fonksiyonu cagrildi\n");
}

int main()
{
	func();
	(&func)();

}
```


```c
#include <stdio.h>

int func(int x, int y)
{
	printf("func cagrildi\n");

	return x * y;
}

int foo(int x, int y)
{
	printf("foo cagrildi\n");

	return x + y;
}

int main()
{
	//int(*fp)(int, int) = &func;
	int(*fp)(int, int) = func;

	int x = fp(12, 45);
	printf("x = %d\n", x);
	fp = foo;
	int y = fp(12, 45);
	printf("y = %d\n", y);

}
```


```c
#include <stdio.h>
#include <string.h>


int main()
{
	int(*fptr)(const char *, const char *) = &strcmp;

	fptr = strcoll;
	fptr = &strcoll;

}
```


```c
#include <stdio.h>
#include <string.h>

void f1(void)
{
	printf("f1 cagrildi\n");
}

void f2(void)
{
	printf("f2 cagrildi\n");
}

void f3(void)
{
	printf("f3 cagrildi\n");
}


int main()
{
	void(*fp)(void) = f1;

	fp();
	fp = f2;
	fp();
	fp = f3;
	fp();

}
```

```c
void foo(int, int);

int main()
{
	void(*fp)() = &foo;
}
```


```c
#include <stdio.h>
#include <string.h>

void func(void)
{
	printf("func cagrildi\n");
}

int main()
{
	void(*fp)(void) = func;

	fp();
	(*fp)();

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

void foo(void(*fp)(void))
{
	printf("foo cagrildi\n");
	fp();
	sl();
}

void f1(void)
{
	printf("f1 cagrildi\n");
}

void f2(void)
{
	printf("f2 cagrildi\n");
}

void f3(void)
{
	printf("f3 cagrildi\n");
}


int main()
{
	foo(f1);
	foo(f2);
	foo(f3);

	/*foo(&f1);
	foo(&f2);
	foo(&f3);*/
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include "nutility.h"


void fdisplay(const char *p, int(*fp)(int))
{
	printf("%s islevinin true deger dondurdugu karakterler\n", p);
	for (int i = 0; i < 128; ++i)
		if (fp(i))
			printf("%c", i);
	printf("\n\n");
}



int main()
{
	fdisplay("isupper", isupper);
	fdisplay("ispunct", ispunct);
	fdisplay("isxdigit", isxdigit);
	
}
```