# Fonksiyon Cagrilari


```text
1. fonksiyon çağrısı bir ifadedir (expression)
2. C'de fonksiyon çağrısı operatör seviyesinde bir işlemdir.
3. function call operator ( ) fonksiyon çağrı operatörü ile yapilir.
```

```text
if (sin(a) > cos(b))
	++size;

if (sin(x) > sin(y))
	fun();

while ((c = getchar()) != '\n) 
{
}

while (n--)
	*p1++ = *p2++;

sin(sqrt(x))

strcat(s1, strcpy(s2, s3));
```


```c
/** 4 tam sayinin en buyugunun bulunmasi */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max2(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int x, y, z, t;

	printf("dort tamsayi giriniz: ");
	scanf("%d%d%d%d", &x, &y, &z, &t);

	int ival = max2(max2(x, y), max2(z, t));

	printf("ival = %d\n", ival);
}
```


## Variadic Functions (değişken sayıda arguman ile çağrılabilen fonksiyonlar)

```text
... (ellipsis) 
    Tek basina bir tokendir.
```

```c
void func(int x, int y, ...);

int main()
{
	//func();
	//func(12);
	func(12, 5);
	func(12, 5, 6);
	func(12, 5, 6, 3, 3 ,1);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>


int main()
{
	for (int i = 0; i <= 100; ++i) {
		printf("%3d    %f\n", i, sqrt(i));
	}
    
    return 0;
}
```

```c
#include <stdio.h>

double power_iter(double base, int exp)
{
    double res = 1.;

    while (exp--)
        res *= base;

    return res;
}

double power_recursive(double base, int exp)
{
    return exp == 0 ? 1 : base * power_recursive(base, exp-1);
}

int main(void)
{
    double base;
    int pow;
    printf("Enter the base and power : ");
    scanf("%lf%d", &base, &pow);

    printf("%d power of %.2f is %.2f\n", pow, base, power_iter(base, pow));
    printf("%d power of %.2f is %.2f\n", pow, base, power_recursive(base, pow));

    return 0;
}
```

## C Standard Library (Standart Kütüphane)

```text
math
stdio
string
stdlib
ctype

--------------------
3rd party libraries
```

```text
Peki, Header Dosyalarinda Neler Bulunur ?

    object-like macro
    functional-like macro
    
    INT_MAX
    
    TYPES
        struct tm
        FILE
    size_t
    ptrdiff_t
    time_t
    clock_t
    int32_t
    
    type alias
    tür eş ismi
    
    constants - literals
```


```text
signed int
unsigned int

signed long
unsigned long

signed long long		C99
unsigned long long      C99

float
double
long double
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
	int x = 0x41;

	printf("x = %d\n", x);
	x = 041;
	printf("x = %d\n", x);
	x = 41;
	printf("x = %d\n", x);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x = -1; // 0xFFFF

    if (x > 1u) // 1u --> 0X0001
        printf("dogru\n");
    else
        printf("yanlis\n");

    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	for (int i = 90; i < 10l; ++i)
		printf("%d\n", i);

}
```

```c++
#include <iostream>

int main()
{
    using namespace std;

    cout << typeid(76).name()      << "\n";
    cout << typeid(0x1ac4).name()  << "\n";
    cout << typeid(0x1ac4L).name() << "\n";
    cout << typeid(01234u).name()  << "\n";
    cout << typeid(45UL).name()    << "\n";
    cout << typeid(45ULL).name()   << "\n";
    
    return 0;
}
```


