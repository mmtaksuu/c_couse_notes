
T func()
{
	///...
	return t;
}


T x;

x = func();


void func(int i1, int i2, double *p_alpha, double *p_beta, double *p_gamma);

/**********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void func(int i1, int i2, double *p_alpha, double *p_beta, double *p_gamma);


int main()
{
	double alpha, beta, gamma;

	func(12, 45, &alpha, &beta, &gamma);

}
/**********************************************************************************************************************/


void func(T x, )

void func(????);




# const anahtar sözcüğü
```text
void func(T *ptr);
void foo(const T *ptr);

1) Kendinize yardımcı oluyorsunuz.

2) Okuyana yardımcı oluyorsunuz.

3) derleyiciye yardımcı oluyorsunuz.
```


```c
#include <stdio.h>

void func(void)
{
    static int x = 0, y = 0, z = 0;
    printf("%d %d %d\n", x, y, z);
    ++x, ++y, ++z;
}


int main(void)
{
    printf("x y z\n");
    for (int i = 0; i < 10; ++i) {
        func();
    }

    return 0;
}
```


```text

kendisi const bir nesneyi (ne nedenle olursa olsun) değiştirme girişiminde bulunmayin! (tanımsız davranış)
```


#include <stdio.h>

int main()
{
	const int x = 1111;

	int *ptr = (int *)&x;
	*ptr = 7777; //ub

	printf("x = %d\n", x);
}


```text
sabit ifadesi ile ilk deger verilmiş const nesneler C'de
sabit ifadesi gereken yerlerde kullanılamazlar. (sentaks hatası)
C++ dilinde bu kullanım geçerlidir.

const anahtar sözcüğünün pointer değişkenlerin bildiriminde kullanılması
```

#include <stdio.h>

int main()
{
	int x = 10;
	int y = 20;

	int *const ptr = &x;	//const pointer
	//TOP level const
	//ptr = &y; //gecersiz
	*ptr = 987; //gecerli
	printf("x = %d\n", x);

}

/**********************************************************************************************************************/
#include <stdio.h>

int main()
{
	int x = 10;
	int y = 20;

	const int *ptr = &x;	//pointer to const int
	//low-level const
	//int const * ptr = &x;

	//*ptr = 999; //gecersiz
	ptr = &y;  //gecerli

}
/**********************************************************************************************************************/


```text
func is a setter
func is a set function
func is a mutator
--------------------
void func(T *ptr);  //output parameter

get function
getter
accessor
observer
--------------------
void foo(const T *ptr); //input parameter
```

# adres türleri ve tür dönüşümleri

```text
T *
const T *
```


int main()
{
	int x = 10;
	const int cx = 20;
	int *ptr;
	const int *p;
	int a[5] = { 0 };
	const int primes[] = { 2, 3, 5, 7, 11 };

	// &x => int *
	//&cx => const int *
	// ptr => int *
	//p => const int *
	// a => int *
	// primes => const int *
}
/**********************************************************************************************************************/

void foo(const double *);

int main()
{
	int x = 10;
	const int *p = &x;
	double dval = 3.4;

	foo(&dval);

}
/**********************************************************************************************************************/


T * ===============> const T *

---------------------------------

//warning C4090: 'initializing': different 'const' qualifiers
int main()
{
	const int x = 10;

	int *ptr = &x;


}
/**********************************************************************************************************************/

# pointer aritmetiği
--------------------
```text
C dilinde
	bir adres ile bir tamsayı toplanabilir
		adres + n
	bir tamsayı ile bir adres toplanabilir
		n + adres
	bir adresten bir tamsayı çıkartılabilir
		adres - n
bu işlemler geçerli işlemlerdir. Her birinden elde edilen değer adrestir.
aşağıdaki işlemler geçersizdir
	adres + adres
	tamsayı - adres
```




#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	double a[10] = { 0 };

	for (int i = 0; i < 10; ++i) {
		printf("%p %p\n", a + i, &a[i]);
	}
}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; ++i) {
		printf("%d %d %d %d\n", a[i], i[a], *(a + i), *(i + a));
	}
}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	short a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; ++i) {
		printf("%d %d %d %d\n", a[i], i[a], *(a + i), *(i + a));
	}
}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	double a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; ++i) {
		printf("%f %f %f %f\n", a[i], i[a], *(a + i), *(i + a));
	}
}
/**********************************************************************************************************************/

int ival = 10;

++ival;
ival = ival + 1;

int *ptr = a;

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *ptr = a;

	for (int i = 0; i < 10; ++i) {
		printf("%d %d %d %d %d\n", a[i], i[a], *(a + i), *(i + a), *ptr);
		++ptr;
	}
}
/**********************************************************************************************************************/

# indeks operatörü

```text
-------------------------------------------------
1       [ ]   ()    .   ->     soldan sağa
-------------------------------------------------

index op / subscript op

x[y]      *(x + y)


a[5]     5[a]

a[n]   *(a + n)

&a[n]   a + n
```

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x = 10;

	(&x)[0]++;
	printf("x = %d\n", x);


}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = a;

	for (int i = 0; i < 10; ++i) {
		printf("%d %d\n", a[i], p[i]);
	}

}
/**********************************************************************************************************************/


*p   p[0]
*a   a[0]

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = a + 5;

	printf("%d\n", *p);
	printf("%d\n", p[0]);
	printf("%d\n", p[3]);
	printf("%d\n", p[-4]);  // *(p - 4)


}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p1 = a + 7;
	int *p2 = a + 2;

	printf("%d\n", p1 - p2);
	printf("%d\n", p2 - p1);

}
/**********************************************************************************************************************/

