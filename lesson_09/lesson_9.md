# LESSON 9

```text
Maximum Munch Durumu
    z = x+++y;
    
    Derleyici gecerli olan en uzun tokeni alir.
        z = x++ + y;
```

```c
int main()
{
	int x = 10;
	int y = 50;

	int z = x+++y;

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
}
```


## Karsilastirma Operatorleri

```text
6		> >= < <=

7		== !=
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	printf("(%d) >  (%d) = (%d)\n", x, y, x > y);
	printf("(%d) >= (%d) = (%d)\n", x, y, x >= y);
	printf("(%d) <  (%d) = (%d)\n", x, y, x < y);
	printf("(%d) <= (%d) = (%d)\n", x, y, x <= y);
	printf("(%d) == (%d) = (%d)\n", x, y, x == y);
	printf("(%d) != (%d) = (%d)\n", x, y, x != y);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;
	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	int z = x == y;;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	printf("sign (%d) = (%d)\n", x, (x > 0) - (x < 0));
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y, z, t;

	printf("4 tamsayi giriniz: ");
	scanf("%d%d%d%d", &x, &y, &z, &t);

	int pos_cnt = 0;

	if (x > 0)
		++pos_cnt;

	if (y > 0)
		++pos_cnt;

	if (z > 0)
		++pos_cnt;

	if (t > 0)
		++pos_cnt;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y, z, t;

	printf("4 tamsayi giriniz: ");
	scanf("%d%d%d%d", &x, &y, &z, &t);

	int pos_cnt = (x > 0) + (y > 0) + (z > 0) + (t > 0);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	if (10 < x < 20)  //always true
		printf("%d [10 20] araliginda\n", x);
	else
		printf("%d [10 20] araliginda degil\n", x);
}
```

## Reel Sayilarin Esitlik Karsilastirmasi

```text
d1 == d2   Asla boyle bir karsilastirma yapmayin.
fabs(d1 - d2) < delta Reel sayilari boyle karsilastirin.
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double dval = 0.;

	for (int i = 0; i < 10; ++i) 
		dval += .1;

	if (dval == 1.)
		printf("esit\n");
	else
		printf("esit degil\n");
    
    return 0;
}
```


## Esitlik Operatoru

```text
==   yan etkisi yok - ürettiği deger 0 ya da 1
=    yan etkisi var -  ürettiği deger nesneye atanan deger

if (5 == x)

if (lval == rval)

if (rval == lval)
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	if (x = 5)             // Always true
		printf("evet esit\n");
	else
		printf("hayir esit degil\n");

	printf("x = %d\n", x);
}
```



# Lojik Operatörler

```text
lojik değil

p	  doğru   yanlış
!p    yanlış  doğru

lojik ve

p       q    p ve q
D       D      D
D       Y      Y
Y       D      Y
Y       Y      Y

lojik veya

p       q    p veya q
D       D      D
D       Y      D
Y       D      D
Y       Y      Y


lojik özel veya

p       q    p exor q
D       D      Y
D       Y      D
Y       D      D
Y       Y      Y

!   logical  not
&&   logical and
||   logical or

Lojik Operatörlerin Kullanim Yerleri
------------------------------------
!exp			operatörünün operandı
exp1 && exp2	operatörünün operandları
exp || exp		operatörünün operandları
if (exp)
while (exp)
do while(exp)
for (; exp; )
exp ? x : y


if (x)   ---> if (x != 0)
if (!x)  ---> if (x == 0)
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x;
    
    printf("bir tamsayi giriniz: ");
    scanf("%d", &x);
    
    printf("!(%d) = %d\n", x, !x);
    printf("x = %d\n", x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);
	printf("!!(%d) = %d\n", x, !!x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	printf("(%d) ozel veya (%d) = (%d)\n", x, y, !!x != !!y);
}
```



## Lojik And Operatörü

```text
x && y Logical And
x & y  Bitwise And
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	printf("%d && %d = %d\n", x, y, x && y);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	if (x && y)
		printf("lojik ve dogru\n");
	else
		printf("lojik ve yanlis\n");

	if (x & y)
		printf("bitsel ve dogru\n");
	else
		printf("bitsel ve yanlis\n");
}
```


## Lojik Or Operatörü

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	printf("%d || %d = %d\n", x, y, x || y);
}
```


# De Morgan Kuralları

```text
!(x && y)   !x || !y
!(x || y)   !x && !y
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	printf("(%d) <  (%d) = (%d)\n", x, y, x < y);
	printf("(%d) >  (%d) = (%d)\n", x, y, y < x);
	printf("(%d) >= (%d) = (%d)\n", x, y, !(x < y));
	printf("(%d) <= (%d) = (%d)\n", x, y, !(y < x));
	printf("(%d) == (%d) = (%d)\n", x, y, !(x < y) && !(y < x)); // equivalance - equality
	printf("(%d) != (%d) = (%d)\n", x, y, (x < y) || (y < x));   // equivalance - equality
}
```


```text
if (x != 5 || x != 13)  //always true
	++y;

if (x == 5 && x = 13)  //always false
    ++y;

if (x != 5 && x != 13)  //always false
	++y;
```


## Short Circuit Behaviour Of the Logic Operators

```text
if (a > 10)
	if (b > 50)
		++x;

if (a > 10 && b > 50)
	++x;

if (x == 0 && f() && g() && h() &&)

if (p != NULL && *p > 100)
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 0;
	int y = 99;

	int z = x && ++y;    // Sag taraf hic degerlendirilmez.

	printf("z = %d\n", z);
	printf("y = %d\n", y);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 10;
	int y = 99;

	int z = x || ++y;

	printf("z = %d\n", z);
	printf("y = %d\n", y);
}
```


## Atama Operatörleri

```text
assignment   ---> Atama 
initializing ---> Ilk deger verme

C'de atama operatörlerinin ürettiği değer nesneye atanan değerdir.

Islemli Atama Operatörleri

    += -= *= /= %=    &= ^= |= <<= >>=      
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int a)
{
    printf("a = %d\n", a);
}

int main()
{
    int x = 12;

    func(x = 5);

    printf("x = %d\n", x);
    
    return 0;
}
```
                
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ch;

	printf("bir giris yapin: ");

	while ((ch = getchar()) != '\n')
		printf("%d ", ch);
}
```
 
```text
Atama operatorunun urettigi deger nesneye atanan degerdir.

    int ival;
    
    double dval = 12.6;
    
    ival = dval
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x;
    double dval = 12.98;

    printf("%d\n", (x = dval) / 5);  // 2

    return 0;
}
```

## Virgulle Ayrilan Liste Kullanilarak Yapilan Atama Islemi


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y, z, t;

	t = foo();
	z = t;
	y = z;
	x = y;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y, z, t;

	x = y = z = t = foo();
}
```



## Islemli Atama Operatorleri

```text
x = x + 5;	--->  x += 5;
y = y - 3;	--->  y -= 3;
z = z * 10; --->  z *=  10;
x = x / 10; --->  x /= 10;
m = m % 10; --->  m %= 10;
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int day, hour, minute, second;

    printf("Enter the time as Day, Hour, Minute and Second : \n");
    scanf("%d%d%d%d", &day, &hour, &minute, &second);

    minute += second / 60;
    second %= 60;

    hour += minute / 60;
    minute %= 60;

    day += hour / 24;
    hour %= 24;

    printf("%d Day %d Hour %d Minute %d Second\n", day, hour, minute, second);

    return 0;
}
```


# C ve C++ Dillerinde çok önemli olan bazı terimlerin açıklaması

```text
Undefined Behavior (tanımsız davranış)
    y = x + x++;
    ++x && f(x)
    
Implementation Defined (implementation dependant)
    f1() + f2() * f3()  --> Cagrilma sirasi
    
    char *p1 = "mehmet";  --> Kac tane olsuturulacagi
    char *p2 = "mehmet";
    char *p3 = "mehmet";

Implementation Specified
    char turunun signed veya unsigned olmasi
```




