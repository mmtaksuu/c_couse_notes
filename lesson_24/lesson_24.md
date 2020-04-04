```text
ptr ismi a olan bir dizinin bir öğesini göstermektedir.
ptr'nin gösterdiği dizi öğesinin indeksi nedir?

ptr - a


a dizisinin  i indisli elemanının adresi nedir?

pointer aritmetiği

geçerli ve geçersiz pointer'lar  (valid & invalid pointers)


diziler üstünden işlem yapan fonksiyonlar
dizilerin fonksiyonlara gönderilmesi
adresler ve karşılaştırma işlemleri
adres döndüren fonksiyonlar
NULL pointer semantiği
```


```c
#include <stdio.h>

int main()
{
	int a[5] = { 0, 1, 2, 3, 4 };
	int x = 10;

	int *p1 = &x;
	int *p2 = a + 5;
	//int *p2 = &a[5];  //defined behavior
	//int y = a[5]; //ub
	int *p3 = NULL;
}
```
```c
#include <stdio.h>

// dangling pointer

int main()
{
	int *ptr;

	if (1) {
		int x = 10;
		ptr = &x;
		//ptr burada gecerli bir pointer
	}
	//ptr burada gecersiz  pointer (dangling)

}
```

```c
#include <stdio.h>
#include "nutility.h"

#define   SIZE      100


int main()
{
	int a[SIZE];

	//randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);
	display_array(a, 5);
	display_array(a + 5, 3);
	display_array(a + SIZE - 5, 5);
}
```

```c
#include <stdio.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100

int sum_array(const int *p, int size)
{
	int sum = 0;

	while (size--) {
		sum += *p;
		++p;
	}

	return sum;
}

double get_mean(const int *p, int size)
{
	return (double)sum_array(p, size) / size;
}

double get_std_dev(const int *p, int size)
{
	double mean = get_mean(p, size);
	double sum_square = 0.;

	for (int i = 0; i < size; ++i)
		sum_square += (p[i] - mean) * (p[i] - mean);

	return sqrt(sum_square / size);
}

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);
	printf("std. sapma = %f\n", get_std_dev(a, SIZE));
}
```

```c
#include <stdio.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      20


void reverse_array(int *p, int size)
{
	int *pe = p + size;
	int n = size / 2;

	while (n--)
		swap(p++, --pe);
}


//void reverse_array(int *p, int size)
//{
//	for (int i = 0; i < size / 2; ++i) {
//		swap(p + i, p + size - 1 - i);
//		//swap(&p[i], &p[size - 1 - i]);
//		/*int temp = p[i];
//		p[i] = p[size - 1 - i];
//		p[size - 1 - i] = temp;*/
//	}
//}
//

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);
	reverse_array(a, SIZE);
	display_array(a, SIZE);
}
```


```c
#include <stdio.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100


void copy_array(int *pdest, const int *psource, int size)
{
	while (size--) {
		*pdest = *psource;
		++pdest;
		++psource;
	}
}

int main()
{
	int a[SIZE];
	int b[SIZE];

	randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);
	copy_array(b, a, SIZE);
	display_array(a, SIZE);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100


void copy_array(int *pdest, const int *psource, int size)
{
	while (size--) {
		*pdest = *psource;
		++pdest;
		++psource;
	}
}

int main()
{
	int a[SIZE];
	int b[SIZE] = { 0 };
	int idxa, idxb, n;

	randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);

	printf("a'da indeks b'de indeks ve oge sayisi: ");
	scanf("%d%d%d", &idxa, &idxb, &n);

	copy_array(b + idxb, a + idxa, n);

	display_array(b, SIZE);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      20

void reverse_copy_array(int *pdest, const int *psource, int size)
{
	int *pe = pdest + size;

	while (size--) {
		--pe;
		*pe = *psource;
		++psource;
	}
}

void copy_array(int *pdest, const int *psource, int size)
{
	while (size--) {
		*pdest = *psource;
		++pdest;
		++psource;
	}
}

int main()
{
	int a[SIZE];
	int b[SIZE];
	int c[SIZE];

	randomize();
	set_random_array(a, SIZE);
	copy_array(b, a, SIZE);
	reverse_copy_array(c, a, SIZE);
	display_array(a, SIZE);
	display_array(b, SIZE);
	display_array(c, SIZE);


}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>

#define   SIZE      20

void get_minmax(const int *pa, int size, int *pmax, int *pmin)
{
	*pmax = *pmin = *pa;

	for (int i = 1; i < size; ++i) {
		if (pa[i] > *pmax) {
			*pmax = pa[i];
		}
		else if (pa[i] < *pmin) {
			*pmin = pa[i];
		}
	}

}

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	display_array(a, SIZE);
	int min, max;

	get_minmax(a, SIZE, &max, &min);

	printf("min = %d    max = %d\n", min, max);

}
```



# adreslerin karşılaştırılması

```text
==    !=

< <= > >=


1) eğer her iki pointer da aynı nesneyi gösteriyor ise

    if (*p1 == *p2)

2) Eğer her iki pointer değişken de aynı dizinin bittiği yeri gösteriyor ise iki pointer eşittir.
    
    if (p1 == p2)
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x = 10, y = 20;
	int *p1 = &x, *p2 = &y;

	if (p1 == p2)
		printf("evet esit\n");
	else
		printf("hayir esit degil\n");

	p2 = &x;

	if (p1 == p2)
		printf("evet esit\n");
	else
		printf("hayir esit degil\n");
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

int main()
{
	int a[] = { 218, 336, 693, 908, 379, 684, 412, 354, 295, 909, };
	int *p = a;
	int *pe = a + asize(a);

	while (p != pe) {
		printf("%d ", *p);
		++p;
	}

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

#define   SIZE      20

void display_array2(const int *ps, const int *pe)
{
	while (ps != pe) {
		printf("%3d ", *ps);
		++ps;
	}
	printf("\n----------------------------------------------\n");
}

int main()
{
	int a[SIZE];

	randomize();

	set_random_array(a, SIZE);
	display_array(a, SIZE);
	display_array2(a, a + SIZE);
	display_array2(a + 3, a + 8);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

#define   SIZE      10

void reverse_array(int *p, int size)
{
	int *pe = p + size;

	while (p < pe)
		swap(p++, --pe);
}


int main()
{
	int a[SIZE];

	randomize();

	set_random_array(a, SIZE);
	display_array(a, SIZE);
	randomize();
	int *p1 = a + rand() % SIZE;
	int *p2 = a + rand() % SIZE;

	if (p1 > p2)
		printf("dogru\n");
	else
		printf("yanlis\n");
	printf("%d  %d\n", *p1, *p2);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

#define   SIZE      10

void reverse_array(int *p, int size)
{
	int *pe = p + size;

	while (p < pe)
		swap(p++, --pe);
}


int main()
{
	int a[SIZE];

	randomize();

	set_random_array(a, SIZE);
	display_array(a, SIZE);
	reverse_array(a, SIZE);
	display_array(a, SIZE);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

#define   SIZE      10


int main()
{
	int x = 10, y = 20;


	if (&x > &y) //unspecified behavior
		printf("evet dogru\n");
	else
		printf("hayir yanlis\n");

}
```

# Yazilar

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

#define   SIZE      10


int main()
{
	char str[100];

	printf("bir yazi girin: ");
	scanf("%s", str);

	if (str == "burak")
		printf("dogru\n");
	else
		printf("yanlis\n");

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

#define   SIZE      10


int main()
{
	char s1[] = "hilal";
	char s2[] = "hilal";

	if (s1 == s2) //always false
		printf("dogru\n");
	else
		printf("yanlis\n");


}
```