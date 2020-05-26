# LESSON 10

## Sequence Point (Yan Etki Noktası)

```text
Yan Etki Noktalari Nerede Bulunur ?

1)    Virgul ile ayrilan liste
        int x = 10, y = ++x, z = y + x;

2)    Noktali virgul olan noktalar
        x = 5; //deyim sonundan sonra artik x'in degeri 5

3)    Logik and, or operatorleri
        ++x && func(x)

4)    If deyimi
        if (x++ > 5)
            f1(x);
        else
            f2(x);

5)    Kosul Operatoru
        ++a ?  :
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Undefined Behaviour Gosterimi
int main(void)
{
    int x = 10;
    int y;

    // error: operation on 'x' may be undefined [-Werror=sequence-point]
    y = x + x++;

    printf("y = %d\n", y);

    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// const nesnenin degerinin const olmayan pointer uzerinden degistirilmesi islemi
// Not: Asla Yapmayin.

int main(void)
{
    const int x = 10;
    int *ptr = (int *)&x;

    *ptr = 999;

    printf("x = %d\n", x);

    return 0;
}
```


## Virgul Operatoru

```text
x = 5, 7

expr1, expr2

x = 10, y = ++x, z = y * x;

++x, ++y, ++z;


exp1;
exp2;
exp3;
exp4;
---------------
exp1, exp2, exp3, exp4;
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Bu koddaki hicbir virgul operator degil, hepsi delimiter (ayrac).

void func(int a, int b);

int main()
{
	int x = 10, y = 20;
	int a[] = { 1, 4, 5, 6 };
	func(x, y);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Swap isleminde virgulun delimiter kullanilmasi.
int main(void)
{
	int x, y, temp;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	temp = x, x = y, y = temp;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// For dongusunde virgulun delimiter kullanilmasi.
int main()
{
	int x = 10;
	int i, k;

	for (i = x, k = i + 2; i + k < 1000; ++i, k += i)
		; //
	//
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// If deyiminde virgulun delimiter kullanilmasi.
int main()
{
	int x;
	int a = 5, b = 7;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	if (x > 10)
		++a, ++b;
}
```


### Virgulun Operator Olarak Kullanilmasi
```text
Virgul operatorunun urettigi deger sag operandin degeridir.
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Virgulun Operator olarak kullanilmasi.
int main(void)
{
    int x;
    int y = 10, z = 87;

    x = (y, z);  // x = 87
    printf("x = %d\n", x);
    
    x = (z, y);  // x = 10
    printf("x = %d\n", x);

    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Virgulun Operatorunun urettigi deger sag operandin degeridir.
int main(void)
{
	int c;

	printf("giris lutfen: ");

	while (c = getchar(), c != '\n')
		printf("%d\n", c);
    
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Geri donus turu void olan fonksiyonlarin virgul operatoru 
// hilesi ile lojik operatorler ile kullanilmasi.

int f1(void)
{
	printf("f1 cagrildi\n");
	return 1;
}

void f2(void)
{
	printf("f2 cagrildi\n");
}

int main(void)
{
	f1() && (f2(), 0);
	
	return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double dval = 2.5;

	if (dval > 5,7)    // if (dval > 7) anlamidadir
		printf("dogru\n")
	else
		printf("yanlis\n")
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int);

int main(void)
{
    func((x, y)); // func(y); demek ile ayni anlamdadir.

    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Virgulun Operator olarak kullanilmasi.

int main(void)
{
    int a[10] = { (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)};  // a[10] = {10, 0, 0, 0, 0, 0, 0, 0, 0, 0,}
    
    for (int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);   // Cikti --> 10 0 0 0 0 0 0 0 0 0
    }
    
    return 0;
}
```

```text
Ikinci Dereceden Denklemin Koklerinin Bulunmasi

// Δ = b^2 − 4ac  is called discriminant
delta = pow(b,2) - (4 * a * c);

// x1 = (−b - √Δ) / 2a
x1 = (-b - sqrt(delta)) / (2 * a)

// x2 = (−b + √Δ) / 2a
x2 = (-b + sqrt(delta)) / (2 * a)


if (delta > 0)
    we get two real solutions

if (delta == 0)
    we get just ONE solution

if (delta < 0)
    we get complex solutions
```

```c
#include <stdio.h>
#include <math.h>

typedef struct {
    double reel;
    double im;
} COMPLEX_t ;

typedef struct {
    double a;
    double b;
    double c;
    double delta;
    double x1;
    double x2;
    COMPLEX_t c_x1;
    COMPLEX_t c_x2;
} Quadratic_Equation_t;


void quadratic_equation_solver(Quadratic_Equation_t *p_quad_eq);
void prints_quadratic_equation_result(Quadratic_Equation_t *p_quad_eq);

int main(void)
{
    Quadratic_Equation_t quadratic_equation_t = {0};
    
    printf("Enter the coefficients of the equation 'ax^2 + bx + c = 0'\n");
    
    printf("a : ");
    scanf("%lf", &quadratic_equation_t.a);
    
    printf("b : ");
    scanf("%lf", &quadratic_equation_t.b);
    
    printf("c : ");
    scanf("%lf", &quadratic_equation_t.c);
    
    quadratic_equation_solver(&quadratic_equation_t);
    prints_quadratic_equation_result(&quadratic_equation_t);
    
    return 0;
}


void quadratic_equation_solver(Quadratic_Equation_t *p_quad_eq)
{
    // First, find the discriminant    Δ = b^2 − 4ac
    p_quad_eq->delta = pow(p_quad_eq->b, 2) - (4 * p_quad_eq->a * p_quad_eq->c);
    
    if (p_quad_eq->delta > 0) // we get two real solutions
    {
        // x1 = (−b - √Δ) / 2a
        p_quad_eq->x1 = (-p_quad_eq->b - sqrt(p_quad_eq->delta)) / (2 * p_quad_eq->a);
    
        // x2 = (−b + √Δ) / 2a
        p_quad_eq->x2 = (-p_quad_eq->b + sqrt(p_quad_eq->delta)) / (2 * p_quad_eq->a);
    }
    else if (p_quad_eq->delta == 0)  // we get just ONE solution
    {
        // x1 = x2 = -b / 2a
        p_quad_eq->x1 = p_quad_eq->x2 = (-p_quad_eq->b) / (2 * p_quad_eq->a);
    }
    else if (p_quad_eq->delta < 0)  // we get complex solutions
    {
        // x1 = a - bi
        p_quad_eq->c_x1.reel = (-p_quad_eq->b) / (2 * p_quad_eq->a);
        p_quad_eq->c_x1.im   = (-sqrt(fabs(p_quad_eq->delta))) / (2 * p_quad_eq->a);
    
        // x2 = = a + bi
        p_quad_eq->c_x2.reel = (-p_quad_eq->b) / (2 * p_quad_eq->a);
        p_quad_eq->c_x2.im   = (sqrt(fabs(p_quad_eq->delta))) / (2 * p_quad_eq->a);
    }
}


void prints_quadratic_equation_result(Quadratic_Equation_t *p_quad_eq)
{
    printf("Answer: \n\n");
    
    if (p_quad_eq->delta > 0) // we get two real solutions
    {
        printf("There are two real solutions \n");
        printf("The parabola crosses the x axis at two different points. \n");
    
        if (-p_quad_eq->b / (2* p_quad_eq->a) > 0)
            printf("The parabola crosses the x axis on the positive side of the y axis. \n");
        else if (-p_quad_eq->b / (2* p_quad_eq->a) < 0)
            printf("The parabola crosses the x axis on the negative side of the y axis. \n");
    
        printf("x1 = %.2f\nx2 = %.2f\n", p_quad_eq->x1, p_quad_eq->x2);
    }
    else if (p_quad_eq->delta == 0)  // we get just ONE solution
    {
        printf("There is just one real solutions \n");
        printf("The parabola is tangent to the x axis. \n");
    
        if (-p_quad_eq->b / (2* p_quad_eq->a) > 0)
            printf("The parabola is tangent on the positive side of the y axis. \n");
        else if (-p_quad_eq->b / (2* p_quad_eq->a) < 0)
            printf("The parabola is tangent on the negative side of the y axis. \n");
    
        printf("x1 = %.2f\nx2 = %.2f\n", p_quad_eq->x1, p_quad_eq->x2);
    
    }
    else if (p_quad_eq->delta < 0)  // we get complex solutions
    {
        printf("There are two complex solutions \n");
        printf("The parabola does not cross the x axis. \n");
    
        if (p_quad_eq->a > 0)
            printf("The parabola is on the positive side of the y axis. \n");
        else if (p_quad_eq->a < 0)
            printf("The parabola is on the negative side of the y axis. \n");
    
        printf("x1 = %.1f %c %.2fi\n", p_quad_eq->c_x1.reel, p_quad_eq->c_x1.im > 0 ? '+' : '-', fabs(p_quad_eq->c_x1.im));
        printf("x2 = %.1f %c %.2fi\n", p_quad_eq->c_x2.reel, p_quad_eq->c_x2.im > 0 ? '+' : '-', fabs(p_quad_eq->c_x2.im));
    }
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 3 basamakli armstrong sayilarinin bulunmasi

int main()
{
	printf("%d %d %d %d\n", 153, 370, 371, 407);
	
	for (int i = 100; i < 1000; ++i) {
		int d1 = i / 100;
		int d2 = i / 10 % 10;
		int d3 = i % 10;

		if (i == (d1 * d1 * d1) + (d2 * d2 * d2) + (d3 * d3 * d3))
			printf("%d\n", i);
	}
}
```



```c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define     ONE_HOUR        60
#define     ONE_MINUTE      60
#define     ONE_SECOND      60

int ndigit(int x)
{
    int digit_count = 0;

    if (!x)
        return 1;

    while (x != 0) {
        ++digit_count;
        x /= 10;
    }

    return digit_count;
}

int power(int base, size_t exp)
{
    int result = 1;

    if (!exp)
        return 1;

    while (exp--)
        result *= base;

    return result;
}


int is_armstrong(int x)
{
    size_t nOfdigit    = (size_t)ndigit(x);
    int    temp        = x;
    int    sum         = 0;
    int    digit_value = 0;

    while (temp) {
        digit_value = temp % 10;
        sum += power(digit_value, nOfdigit);
        temp /= 10;
    }

    if (sum == x)
        return 1;

    return 0;
}

// Total time is 2 minutes and 59 seconds.
int main(void)
{
    clock_t start = clock();

    for (int i = 0; i < 999999999; ++i) {
        if (is_armstrong(i))
            printf("%d\n", i);
    }

    clock_t end = clock();

    clock_t second  = (end - start) / CLOCKS_PER_SEC;
    clock_t minute  = 0;

    minute += second / ONE_MINUTE;
    second %= ONE_SECOND;
    minute %= ONE_HOUR;

    printf("Total time is %ld minutes and %ld seconds.\n", minute, second);

    return 0;
}
```

## Kontrol Deyimleri

```text
 expression statement
 compound statement
 null statement
 control statement

 if

 while
 do while
 for

 switch
 goto

 break
 continue
 return


if (getvalue(&x), x > 10) 
{
    // codes
}


if (x++ > 100)

if (exp1 && exp2)

if (!!exp1 & !!exp2)


if (x != 13 || x != 20)
if (x != 13 && x != 20)

if (x == y)
if (x = y)

if (x > 10 && x < 20)
if (10 < x < 20)      // always true

if (dval > 12,7)
if (dval > 12.7)

if (func())

if (func)  //always true

if (x > 10)
	;


if (!expr)
	statement2;


if (i < size && a[i] == val) // Arama islemlerinde tasmayi onler.

if (getval1() > 5 & func() < 10)

if (expr1 && expr2 && expr3)

if (exp)
    statement1;
else
	statement2;


if (lval == rval)

if (rval == lval)

if (5 == x)
```




