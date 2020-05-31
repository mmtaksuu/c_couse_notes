# LESSON 11

## Dangling Else (Redundant Else)

```text
if (x > 10)
	if (y > 20)
		++a;
	else
		++b;
----------------------
if (x > 10) 
	if (y > 20)
		++a;
else
	++b;

// Olmasi gereken boyledir.
int max2(int a, int b)
{
	if (a > b)
		return a;

	return b;
}
```

```text
if (x == (y > 10 ? 5 : 12))

if (ndays < (isleap(y) ? 29 : 28))


if (x == 3)
	a = 5;
else if (x == 7)
	b = 8;
else if (x == 11)
	c++;
else if (x == 23)
	c = 45;
else
	???


if (mon == 12)
	statement1;
else if (expr2)
	statement2;
else if (expr3)
	statement3;
else if (expr4)
	statement4;
else
	statement5;
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//ax2 + bx + c = 0

int main()
{
	int a, b, c;

	printf("Denklemin katsayilarini girin: ");
	scanf("%d%d%d", &a, &b, &c);
	double delta = b * b - 4 * a * c;

	if (delta > 0) {
		double root_delta = sqrt(delta);
		printf("kok 1 = %f\n", (-b - root_delta) / (2 * a));
		printf("kok 2 = %f\n", (-b + root_delta) / (2 * a));
	}
	else if (delta == 0) {
		printf("kok = %f\n", -b / (2 * a));
	}
	else
		printf("denklemin gercek koku yok\n");
    
    return 0;
}
```



## Test Fonksiyonlari

```text
Test functions
Query functions
Predicate functions

int isneco(int x);
if (isprime(x) && isprime(y))
```


```c
int iseven(int x)
{
	return x % 2 == 0;
}

int isodd(int x)
{
	return x % 2 != 0;
	// return x % 2;
	// return x & 1;
}
```

```c
Clamp Ifadesi

int clamp(int v, int low, int high)
{
    return (v < low) ? low : (high < v) ? high : v;
}
```

```c
int is_in_range(int x, int low, int high)
{
	return x >= low && x <= high;
}
```

```text
Artik yil testi yapan fonksiyon

4'e tam bolunenlerden
	 400'e tam bolunenler ya da 100'e tam bolunmeyenler 
```

```c
int isleap(int y)
{
	return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int isleap(int y)
{
	return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int main()
{
	int year;
	printf("bir yil girin: ");
	scanf("%d", &year);

	if (isleap(year))
		printf("%d artik yil\n", year);
	else
		printf("%d artik yil degil\n", year);
}
```

```c
int is_prime(unsigned val)
{
    if (val == 0 || val == 1)
        return 0;
    
    if (val % 2 == 0)
        return val == 2;
    
    if (val % 3 == 0)
        return val == 3;
    
    if (val % 5 == 0)
        return val == 5;
    
    for (size_t i = 7; power(i,2) <= val; i += 2)
        if (val % i == 0)
            return 0;
    
    return 1;
}
```


## Mersenne Primes (2^P - 1)

```text
An integer greater than one is called a prime number if its only divisors are one and itself. 
The first prime numbers are 2, 3, 5, 7, 11, etc. For example, the number 10 is not prime because it is divisible by 2 and 5. 
A Mersenne prime is a prime of the form 2P-1.
The first Mersenne primes are 3, 7, 31, 127 (corresponding to P = 2, 3, 5, 7).
There are only 51 known Mersenne primes.

 #         P            (2^P - 1) 
---    ---------       ---------
1)        2               3
2)        3               7
3)        5               31
4)        7               127
5)        11              2047
 
```

## Perfect Numbers 

```text
A positive integer n is called a perfect number if it is equal to the sum of all of its positive divisors, excluding n itself.

6 = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
```

## The Relationship Between Mersenne Primes and Perfect Numbers

```text
Mp : Mersenne prime
Pn : Perfect number

Euclid proved that if 2^p − 1 is prime, then (2p − 1)*(2p − 1) is a perfect number. 
    Pn = (2p − 1) * (2p − 1)
This number, also expressible as Mp(Mp + 1)/2.
    Pn = ( Mp * (Mp + 1) ) / 2
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

// A positive integer n is called a perfect number
// if it is equal to the sum of all of its positive divisors, excluding n itself.
int is_perfect_number(unsigned val)
{
    unsigned div_sum = 0;

    for (size_t i = 1; i <= val / 2; ++i)
        if (val % i == 0)
            div_sum += i;

    return val == div_sum;
}

int main(void)
{
    while (!_kbhit() || _getch() != 'Q')
    {
        unsigned test_val;
        printf("Enter a number : ");
        scanf("%u", &test_val);

        printf("%u is %s\n", test_val, is_perfect_number(test_val) > 0 ? "Perfect Number" : "Not Perfect Number");
    }

    /*for (unsigned i = 2; i < 1000000; ++i) {
        if (is_perfect_number(i))
            printf("%u ", i);
    }*/

    return 0;
}
```

## Standart ctype Library 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define     EXIT    'Q'

void delay(double delay_time)
{
    clock_t start = clock();
    
    while ((double )(clock() - start)/CLOCKS_PER_SEC < delay_time)
        ;
}

int is_hit_button(int ch)
{
    return (_kbhit() && toupper(_getch()) == ch);
}

void randomize(void)
{
    srand((unsigned)time(NULL));
}

void print_char(int c)
{
    if (isupper(c))
        printf("Upper Case\n");
    
    if (islower(c))
        printf("Lower Case\n");
    
    if (isalpha(c))
        printf("Alphabetic Character\n");
    
    if (isdigit(c))
        printf("Digit\n");
    
    if (isalnum(c))
        printf("Alpha Numeric\n");
    
    if (isxdigit(c))
        printf("Hexadecimal Digit\n");
    
    if (ispunct(c))
        printf("Punctuation Character\n");
    
    if (isspace(c))
        printf("Space Character\n");
    
    if (isblank(c))
        printf("Blank Character\n");
    
    if (isprint(c))
        printf("Printable Character\n");
    
    if (isgraph(c))
        printf("Graphical Character\n");
    
    if (iscntrl(c))
        printf("Control Character \n");
}


int main(void)
{
    randomize();
    
    for (;;) {
        int c = rand() % 128;
        if (isgraph(c)) {
            printf("%c\n", c);
            print_char(c);
            printf("\n\n");
            delay(1); // sn
        }
    
        if (is_hit_button(EXIT))
            break;
    }
    
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;
	printf("bir karakter girin: ");
	ch = getchar();

	printf("ch = %d\n", ch);
	printf("%c ----> %c\n", ch, toupper(ch));
	printf("%c ----> %c\n", ch, tolower(ch));

	return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	int c1, c2;
	printf("iki karakter girin: ");
	c1 = getchar();
	c2 = getchar();

	if (toupper(c1) == toupper(c2)) {
		printf("ayni karakterler\n");
	}
	else {
		printf("farkli karakterler\n");
	}
    return 0;
}
```



```c
#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>

int get_decimal_input(void)
{
    int c;
    int x = 0;

    while ((c = getchar()) != '\n') {
        if (isdigit(c))
        {
            // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. '0' = 48'dir.
            x = x * 10 + c - '0';
        }
    }

    return x;
}

int get_hex_input(void)
{
    int x = 0;

    int c;
    while ((c = getchar()) != '\n') {
        if (isdigit(c))
        {
            // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. '0' = 48'dir.
            x = x * 16 + c - '0';
        }
        else if (isxdigit(c))
        {
            // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. 'A' = 65'dir.
            x = x * 16 + toupper(c) - 'A' + 10;    // A --> 10
        }                                          // B --> 11
    }                                              // C --> 12
                                                   // D --> 13
                                                   // E --> 14
                                                   // F --> 15
    return x;
}


int main(void)
{
    int input1 = get_decimal_input();
    printf("input = %d\n", input1);

    int input2 = get_hex_input();
    printf("input = 0X%02X\n", input2);

    return 0;
}
```


## Ternary Operator (Conditional Operator)

```text
Koşul operatörü

op1 ? op2 : op3

x != 0 ? y : z

x ? y : z

x > y ? x : y

x > 0 ? x : -x
```



## C Kodlarinda Kosul Operatorunun Kullanildigi Tipik Senaryolar


```text
1. Bir nesneye bir koşula bağlı olarak iki değerden biri atanıyor ise

 if (x > 10)
	y = a;
 else
    y = b;

y = x > 10 ? a : b;

max = a > b ? a : b;

val = val >= 0 ? val : -val;

ndays = isleap(y) ? 29 : 28;

yeardays = isleap (y) ? 366 : 365;
c = islower(c) ? c - 'a' + 'A' : c;
```


```c
unsigned int abs(int x)
{
    return x > 0 ? x : -x;
}
```

```c
int max2(int x, int y)
{
    return x > y ? x : y;
}
```

```c
int is_leap(int x)
{
    return x % 4 == 0 && (x % 100 != 0 || x % 400 == 0);
}
```

```c
int ndays(int year)
{
    return is_leap(year) ? 29 : 28;
}
```

```c
int year_days(int year)
{
    return is_leap(year) ? 366 : 365;
}
```

```text
2. bir fonksiyon bir koşula bağlı olarak iki değerden biri ile çağrılıyor

if (x > 5)
	func(a);
else
	func(b);

func(x > 5 ? a : b);

-----------------------------------------------

if (x > 10)
	return a;
else
	return b;

-----------------------------------------------
return x > 10 ? a : b;


(x > 10) ? a : b

-----------------------------------------------

if (x > (isleap(y) ? 366 : 365)) {
	++a;
}


if (isleap(y)) {
	if ( x > 366)
		++a;
}
else if (x > 365)
	++a;


for (int i = x > y ? x : y; )


if (x > 10)
	a = z;
else
	b = z;


x > 10 ? a : b = z;

a > 10 ? b++ : c++

x++ > 10 ? f(x) : g(x)
```

## C ve C++ Dilleri Arasinda Value Category Farkliliklari

```text
Aşağıdaki ifadeler C dilinde R val. expr iken C++ dilinde L val expr

++x ifadesi

--x ifadesi

(x, y)
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	int x = 23, a = 10, b = 45, z = 4;

	x > 10 ? a : b = z;  // C'de gecersiz (R val. expr)
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>


int main()
{
	int x = 23, a = 10, b = 45, z = 4;

	*(x > 10 ? &a : &b) = z;  // C'de yapilan hile
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>


int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	int y = x == 5 ? 13 :
			x == 9 ? 17 :
			x == 19 ? 65 : 26;

	printf("x = %d  y = %d\n", x, y);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	int y = (x == 5 ? 13 :(x == 9 ? 17 : (x == 19 ? 65 : 26)));
	printf("x = %d  y = %d\n", x, y);
}
```

