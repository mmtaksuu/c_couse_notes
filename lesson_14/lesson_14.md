# LESSON 14

## Function Prototype Declaration

```c
int foo(int, int, int);

int main()
{
	double dval = 34.56;

	foo(12, 45);         //gecersiz
	foo(12, 45, 56,98);  //gecersiz
	foo(12, 657, dval);  //gecerli ama veri kaybi
}
```

```text
fonksiyon bildirimlerinde parametre değişkenlerine isim verilebilir ya da verilmeyebilir.
Ancak eğer isim verilirse bu isimler özel bir kapsam kuralına tabidir.

Bu kurala  "function prototype scope" denir.

ReCall : Scopes in C
        file scope
        block scope
        function prototype scope
        function scope
```

```c
int foo(int, int, int);
int foo(int a, int b, int a); //gecersiz, iki isim de function prototype scope'ta

int main()
{

}
```


```c
int x, func(int), foo(double);  //gecerli ama boyle bir bildirim yapmayin

int main()
{

}
```


```text
Asagidaki iki bildirim C++ dilinde özdeş (aynı anlamda).
    Her ikisi de parametre değişkeni olmayan fonksiyonların bildirimleridir.

Ancak C'de bu iki bildirim arasında anlam farklılığı vardir.
    f2 parametre değişkeni olmayan bir fonksiyon,
    f1 ise parametre değişkenleri hakkında bilgi verilmeyen bir fonksiyondur.
```

```c
int f1();
int f2(void);

int main()
{
    f1(1);
    f1(1, 2);
    f1(1, 2, 3);
    f2();
    f2(1);
}
```

```c
int func();

int main()
{
	func(12, 56);
}
```



## Function Redeclaration (Fonksiyonun Yeniden Bildirimi)

```text
Bir fonksiyon bildiriminin  (özdeş olmak kaydıyla) birden fazla kes tekrar etmesi geçerli bir durumdur.
```

```c
int foo(int);
int foo(int x); //gecerli
int foo(int y); //gecerli


int foo(int);
double foo(int); //gecersiz
```


## Separate Compilation Model of C Programming Language


### Bir başlık dosyasında (header file) (tipik olarak) neler bulunur ?

```text
a) external fonksiyonların bildirimi (external function prototypes)
	- asla diğer kaynak dosyalara kapatılmış (internal - static) fonksiyonların bildirimlerini başlık dosyalarına koymayın

b) external global değişkenlerin bildirimi

c) makrolar
	nesnel makrolar (object-like macros)
	işlevsel makrolar (function-like macros)

d) tür bildirimleri
	user defined types (programcı tarafından oluşturulan türler)
		structures (yapılar)
		unions (birlikler)
		enumarations (numaralandırmalar)
	type alias decalaration (tür eş isimleri)

e) external inline function definitions (C99)
```
	
## Preprocessor Directives (On Islemci Komutlari)

```c
#           // null directive

#include
#define
#undef
#if
#endif
#else
#elif
#ifdef
#ifndef
#line
#error
#pragma
```

### INCLUDE Directive

```text
<> default directory
"" actual directory

çift tırnak içinde yazılmış ise
	önce "actual directory" ye bak
	bulamaz isen
	"default directory" ye bak


açısal parantez yazılmış ise
	yalnizca "default directory" ye bak

#include <stdio.h>
#include "nutility.h"
```



### DEFINE Directive

```text
macro

Basit yer değiştirme yapar.
     (substitution)
	 (replacement)
```

```c
#include <stdio.h>
#define    NECO			100 + 500

int main()
{
    int x = 5 * NECO;
    
    printf("x = %d\n", x);
}
```

```c
#include <stdio.h>

#define    NECO			(100 + 500) + \
                        (200 * 5)

int main(void)
{
	int x = 5 * NECO;

	printf("x = %d\n", x);
}
```
