## For Loop

```text
- 'For' is reserved word or keyword,
- A parenthesis is mandatory after the 'for' keyword,
- Two semicolon ';' is mandotory in for parenthesis.
----------------------------------------------------

The relationship between for loop and while loop is given below.

----------------------
for (exp1; exp2; exp3)
	statement;

----------------------
exp1;
while ( exp2 ) {
	statement;
	exp3;
}
```

## While-for arasindaki iliski

```text
i = 0;

dongu {
	statement1
	statement2
	statement3
	statement4
	++i;
}
----------------------------------------------------

for (exp1; 1; exp3)
	statement;


exp1;
while ( exp2 ) {
	statement;
	exp3;
}
```

```c

#include <stdio.h>

int main()
{
	int i;

	for (i = 0; i < 100; ++i) {
		printf("%d ", i);
	}

	printf("\ndongu sonrasindaki deyim\n");
}
```


```c
#include <stdio.h>

int main()
{
	int i;

	i = 0;

	for (; i < 100; ++i) {
		printf("%d ", i);
	}
	
	printf("\ndongu sonrasindaki deyim\n");

}
```


```c
#include <stdio.h>

int main()
{
	int i;

	i = 0;

	for (; i < 100;) {
		printf("%d ", i);
		++i;
	}

	printf("\ndongu sonrasindaki deyim\n");
}
```

```c
#include <stdio.h>

int main()
{
	int i;

	i = 0;

	while (i < 100) {
		printf("%d ", i);
		++i;
	}

	printf("\ndongu sonrasindaki deyim\n");
}
```


```c
#include <stdio.h>

int main()
{
	int i;

	i = 0;

	for (; ;) {
		if (i == 100)
			break;
		printf("%d ", i);
		++i;
	}

	printf("\ndongu sonrasindaki deyim\n");

}
```



## Ways of defining an infinite loop in C

```text
while (1) == for(;;) == for(;1;)

```

```c
#include <stdio.h>

// Defines i as a global loop variable.
int i;

// Defines funtion prototypes
int f1(void);
int f2(void);
void f3(void);
void f4(void);


int main(void)
{
    for (f1(); f2(); f3())
        f4();
    
    return 0;
}

// Function Definitions
int f1(void)
{
    i = 0;
    return i;
}

int f2(void)
{
    return i > 10 ? 0 : 1;
}

void f3(void)
{
    ++i;
}

void f4(void)
{
    printf("%d \n", i);
}
```


```c
#include <stdio.h>

int main()
{
	int i;

	for (i = 0; i < 100; ++i) // Birer birer artan dongu degiskeni
		printf("%d ", i);
}
```

```c
#include <stdio.h>

int main()
{
	int i;

	for (i = 0; i < 100; i += 2) // Ikiserli artan dongu degiskeni
		printf("%d ", i);
}
```

```c
#include <stdio.h>

int main()
{
	int i;

	for (i = 1; i < 1000; i *= 2)  // iki kati olarak artan dongu degiskeni
		printf("%d ", i);

}
```

```c
#include <stdio.h>

int main()
{
	int i;

	for (i = 1; i < 100000000; i *= 10) // On kati olarak artan dongu degiskeni
		printf("%d\n", i);
}
```


```c
#include <stdio.h>

int main()
{
	int i; // Isaretli olarak tanimlandiginda azalan dongu degiskeni

	for (i = 10; i >= 0; --i)
		printf("%d ", i);

}
// Output : 10 9 8 7 6 5 4 3 2 1 0
```

```c
#include <stdio.h>

int main()
{
	unsigned int i; // Isaretsiz olarak tanimlandiginda azalan dongu degiskeni

	for (i = 10; i >= 0; --i)
		printf("%d ", i);
}
// Output : Sonsuz donguye girer. Cunku i degiskeni -1 oldugunda isaretsiz en buyuk sayiya esit olmus olur.
```


```c
#include <stdio.h>

int main()
{
    for (int i = 0; i < 10; ++i) {
        int i = 879; //C++ dilinde gecersiz, error: redeclaration of 'int i'
    }
    return 0;
}
```

```c
#include <stdio.h>

int main()
{
	for (int i = 0; i < 10; ++i) {
		int i = 455;  //C ve C++ kural farkliligi, C 'de hata degildir.
		printf("%d ", i);
	}
    return 0;
}
// Output : 455 455 455 455 455 455 455 455 455 455

```

## Bir Kosula Bagli Olarak Dongu Degiskenini Belirli Bir Deger Ile Baslatmak

```c
#include <stdio.h>

int main()
{
	int x = 10, y = 20;

	for (int i = x > y ? x : y; i < 100; ++i) {
		//...
	}
}
```


```c
#include <stdio.h>

int main()
{
	int i, k;

	for (i = 0, k = 2; i * k < 12000; i++, k += i)
	{
        // codes
	}

}
```


```c
#include <stdio.h>

int factorial(int x)
{
	int result = 1;

	for (int i = 1; i <= x; ++i)
		result *= i;

	return result;
}


int main(void)
{
	for (int i = 0; i < 13; ++i)
		printf("%2d! = %d\n", i, factorial(i));
    
    return 0;
}
```


```text
 0! = 1
 1! = 1
 2! = 2
 3! = 6
 4! = 24
 5! = 120
 6! = 720
 7! = 5040
 8! = 40320
 9! = 362880
10! = 3628800
11! = 39916800
12! = 479001600
13! = 6227020800
14! = 87178291200
15! = 1307674368000
16! = 20922789888000
17! = 355687428096000
18! = 6402373705728000
19! = 121645100408832000
20! = 2.432.902.008.176.640.000
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Recursive Power Func.
int power(int a, int b)
{
    return b == 0 ? 1 : a * power(a, b - 1);
}


// Recursive Factorial Func.
int factorial(int x)
{
    return x < 2 ? 1 : x * factorial(x - 1);
}


// Iterative Factorial Func.
long long int factorial(int x)
{
	long long int result = 1;

	for (int i = 1; i <= x; ++i)
		result *= i;

	return result;
}


int main(void)
{
	for (int i = 0; i < 21; ++i)
		printf("%2d! = %lld\n", i, factorial(i));
    
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int power(int a, int b)
{
    return b == 0 ? 1 : a * power(a, b - 1);
}


int main(void)
{
    int x, y;
    
    printf("iki tamsayi giriniz: ");
    scanf("%d%d", &x, &y);
    
    printf("%d uzeri %d = %d\n", x, y, power(x, y));
    
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// iprint iterative func.
void iprint(int x)
{
    char str[40];
    int sign = 1;
    
    if (x < 0) {
        sign = -1;
        x = -x;
    }
    int i = 0;
    
    while (x != 0) {
        str[i++] = x % 10 + '0';
        x /= 10;
    }
    if (sign == -1)
        str[i++] = '-';
    
    str[i] = '\0';
    for (--i; i >= 0; --i) {
        putchar(str[i]);
    }

}

int main(void)
{
    iprint(-98765);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// iprint recursive func.
void iprint(int x)
{
	if (x < 0) {
		putchar('-');
		x = -x;
	}

	if (x == 0)
		return;
	iprint(x / 10);

	putchar(x % 10 + '0');
}

int main()
{
	iprint(-98765);
}
```

## Fibonacci Sequence 

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// Defines recursive fibonacci function.
int fibonacci_recursive(int n)
{
    return n < 2 ? n : fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Defines Iterative fibonacci function.
int fibonacci_iterative(int n)
{
    if (n < 2)
        return n;
    
    // Rule is xn = xn−1 + xn−2
    int x[45] = {0, 1};
    
    for (int i = 2; i <= n; ++i) {
        x[i] = x[i-1] + x[i-2];
    }
    return x[n];
}

// Defines first 46 fibonacci sequence look-up table.
int fibonacci_lookup(int n)
{
    if (n < 0 || n > 46)
        return -1;
    
    int fibonacci_sequence[] = {
            0,
            1,
            1,
            2,
            3,
            5,
            8,
            13,
            21,
            34,
            55,
            89,
            144,
            233,
            377,
            610,
            987,
            1597,
            2584,
            4181,
            6765,
            10946,
            17711,
            28657,
            46368,
            75025,
            121393,
            196418,
            317811,
            514229,
            832040,
            1346269,
            2178309,
            3524578,
            5702887,
            9227465,
            14930352,
            24157817,
            39088169,
            63245986,
            102334155,
            165580141,
            267914296,
            433494437,
            701408733,
            1134903170,
    };
    
    return fibonacci_sequence[n];
}


int main(void)
{
    printf("\n Calculates Fibonacci Series using Iterative Function.\n");
    for (int i = 0; i < 20; ++i) 
        printf("%2d --> %d\n", i, fibonacci_iterative(i));

    printf("\n Calculates Fibonacci Series using Recursive Function.\n");
    for (int i = 0; i < 20; ++i) 
        printf("%2d --> %d\n", i, fibonacci_recursive(i));
    
    printf("\n Calculates Fibonacci Series using Look-up Table.\n");
    for (int i = 0; i < 20; ++i) 
        printf("%2d --> %d\n", i, fibonacci_lookup(i));
    
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double calc_sum_of_series(int n)
{
    double sum = 0.;
    int factorial = 1;
    
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
        sum += 1. / factorial;
    }
    
    return sum;
}

int main(void)
{
    int n;
    printf("How many series do you want to sum : ");
    scanf("%d", &n);
    
    printf("Sum of the %d series is = %f\n", n, calc_sum_of_series(n));
    
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int factorial(int n)
{
	int result = 1;

	for (int i = 1; i <= n; ++i) {
		result *= i;
	}

	return result;
}

int main()
{
	int n;

	printf("serinin kac terimi toplanacak: ");
	scanf("%d", &n);

	double sum = 0.;

	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0)
			sum += 1. / (2 * i + 1);
		else
			sum -= 1. / (2 * i + 1);

	}

	printf("%f\n", 4. * sum);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n = 5;
    
    for (int i = 0; i + n; --i) {
        printf("NECATI\n");
    }
}
```


## NESTED LOOP (iç içe döngüler)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	for (int i = 0; i < 10; ++i) {
		for (int k = 0; k < 20; ++k) {
			printf("(%d %d) ", i, k);
		}
	}
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int size = 0;

	for (int i = 0; i < 10; ++i) {
		for (int k = 0; k < 20; ++k) {
			++size;
		}
	}

	printf("size = %d\n", size);
    return 0;
}
```

## 3 Basamakli Perfect Sayilarinin Nested-loops ile Bulunmasi

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    printf("\n\n3rd order perfect numbers are : \n");

    int val = 100;

    // This loop counts from 100 to 999 to finds 3 order perfect numbers ( 153, 370, 371, 407)
    for (int i = 1; i <= 9; ++i) {           // represents 100 order
        for (int j = 0; j <= 9; ++j) {       // represents 10 order
            for (int k = 0; k <= 9; ++k) {   // represents 1 order
                if (val == i * i * i + j * j * j + k * k * k)
                    printf("%d\n", val);
                ++val;
            }
        }
    }

    return 0;
}
```

```c
#include <stdio.h>
#include "helper.h"

#define     SIZE              20

void set_arr(int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        *p++ = rand() % 10;
    }
}

void plot_rand_numbers(const int *p, size_t size)
{
    int max = find_imax(p, size);
    
    for (int i = max; i > 0; --i) {
        printf("%2d |  ", i);
        for (size_t j = 0; j < size; ++j) {
            if (p[j] >= i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}



int main(void)
{
    int a[SIZE] = {0};
    
    randomize();
    set_arr(a, SIZE);
    display_array(a, SIZE);
    
    plot_rand_numbers(a, SIZE);
    
    return 0;
}
```

```text
Output of the above code is : 

  0   6   1   6   4   0   0   7   9   8   4   5   1   9   1   1   6   7   9   7

-------------------------------------------------------------------------------
 9|                 *         *         *
 8|                 * *       *         *
 7|               * * *       *       * * *
 6|   *   *       * * *       *     * * * *
 5|   *   *       * * *   *   *     * * * *
 4|   *   * *     * * * * *   *     * * * *
 3|   *   * *     * * * * *   *     * * * *
 2|   *   * *     * * * * *   *     * * * *
 1|   * * * *     * * * * * * * * * * * * *
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "helper.h"

#define     SIZE              20

int * find_unique_numbers(const int *p, size_t size, int *p_unique)
{
    size_t j;

    for (size_t i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            if (p[i] == p[j] && i != j)
                break;
        }
        if (j == size)
            *p_unique++ = p[i];
    }
    
    *p_unique = -1;
    
    return p_unique;
}

void print_unique_numbers(const int *p_unique, size_t size)
{
    printf("\nUnique numbers : \n");
    for (size_t i = 0; i < size && p_unique[i] != -1; ++i) {
        printf("%3d%c", p_unique[i], i % 20 == 19 ? '\n' : ' ');
    }
    printf("\n-------------------------------------------------------------------------------\n");
}


int main(void)
{
    int a[SIZE] = {0};
    int unique[SIZE] = {0};
    
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    
    find_unique_numbers(a, SIZE, unique);
    print_unique_numbers(unique, SIZE);
    
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void find_all_factors (int x)
{
    int n = 2;
    
    while (x != 1) {
        while (x % n == 0) {
            printf("%d ", n);
            x /= n;
        }
        ++n;
    }
}


int main(void)
{
    int x;
    printf("Enter a number : ");
    scanf("%d", &x);
    
    find_all_factors(x);
    
    return 0;
}
```


## Fonksiyon Bildirimleri (Function Prototypes)

```text
external reference

func(x, y);

fonk.a giris kodlari
e.reference
fonk.dna cikis kodlari

derleyicinin fonk'a giriş ve fonk'dan çıkış kodlarını 
doğru olarak üretebilmesi için çağrılan fonksiyon ile 
ilgili şu bilgilere sahip olması gerekir:

a) fonksiyonun geri dönüş değeri türü
b) fonksiyonun parametre değişkeni sayısı
c) fonksiyonun her bir parametre değişkeninin türünu
```