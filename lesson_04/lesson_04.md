# Scope (Kapsam)

```text
Scope compile time'a iliskin bir kavramdir.

    file scope  (dosya kapsamı - dosya bilinirlik alanı)
    block scope (blok kapsamı - blok bilinirlik alanı)
    function prototype scope (fonksiyon prototip bilinirlik alanı)
    function scope (fonksiyon kapsamı
```
)


```c
int x = 10;
void func(int);
typedef int Word;

void f1()
{
	++x;
	func(1);
}

void f2()
{
	Word a = x;

	//
}

void f3()
{
	x += 10;
	func(2);
}
```



//----------------------------------------------------------------------------------------------------------

# Storage Duration (Omur)

```text
Storage Run-time'a iliskin bir kavramdir.

	Static storage class (statik ömür)
	Automatic storage class (otomatik ömür)
	Dynamic storage class (otomatik ömür)

Statik ömürlü değişkenlere ilk değer veren ifadeler
(initializing expression) sabit ifadesi olmak zorundadir.
C++ dilinde böyle bir mecburiyet  yok.

Otomatik ömürlü değişkenlere ilk değer verilmez ise hayata
garbage value (indetermined value) ile baslar. 
```



## Comma seperated list Kullanimi

```c
#include <stdio.h>

int main()
{
	int x = 10, y = 20, z = 30;
	//int x = 10;
	//int y = 20;
	//int z = 30;
}
```

```c
#include <stdio.h>

int main()
{
	int a, b, c;
}
```

```c
#include <stdio.h>

int main()
{
	int a, b = 10, c;
}
```

```c
#include <stdio.h>

int main()
{
	int a, double b; //gecersiz
}
```

## Name Collision (isim çakışması)

```text
Aynı isimlerin farklı varlıklara verilmesi isim çakışmasına sebep olur. 

Birden fazla varliga aynı isim verilebilir mi?

Aynı scope'ta (aynı kapsamda) bir isim birden fazla varlığa verilemez.

Peki, aynı scope ne demek?

    eğer iki ismin kapsamı aynı } (kapanan küme parantezinde)
    bitiyor ise bu isimlerin kapsamı aynıdır.
    
    eğer iki ismin kapsamı farklı } (kapanan küme parantezinde)
    bitiyor ise bu isimlerin kapsamı farklıdır.
```

```c
#include <stdio.h>

//warning C4456: declaration of 'x' hides previous local declaration

int main()
{
	int x = 10;

	if (x > 5) {
		int x = 23;

		printf("x = %d\n", x);

	}
}
```


```c
#include <stdio.h>

int x = 10;

int main()
{
	printf("[1] x = %d\n", x); //10
	int x = 444;
	if (1) {
		printf("[2] x = %d\n", x); //444

		int x = 141;
		printf("[3] x = %d\n", x); //141

		if (1) {
			int x = 345;
			printf("[4] x = %d\n", x); //345

		}
		printf("[5] x = %d\n", x); //141
	}
	printf("[6] x = %d\n", x); //444
}
```
